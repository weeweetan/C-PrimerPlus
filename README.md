# C-PrimerPlus

《C++ Primer Plus》与 C++ 基础练习代码，保留原来的章节文件名。目前已验证 `MyArray` 的复制与生命周期、模板栈的边界，以及 DMA 类赋值的分配失败路径；其他章节暂未逐一纳入验证。

## 构建与运行

需要 C++11 编译器和 CMake 3.20+。使用新的构建目录，避免复用仓库中历史 `cmake-build-debug` 缓存的本机路径。

```sh
git clone https://github.com/weeweetan/C-PrimerPlus.git
cd C-PrimerPlus
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
./build/useMyArray
ctest --test-dir build --output-on-failure
```

| 目标 | 入口 | 用途 |
| --- | --- | --- |
| `C__Primer` | [usealgorithm.cpp](usealgorithm.cpp) | 保留原有算法演示入口 |
| `useMyArray` | [useMyArray.cpp](useMyArray.cpp) | 插入、深复制和自赋值演示 |
| `test_myarray` | [tests/test_myarray.cpp](tests/test_myarray.cpp) | 复制与异常路径回归检查 |
| `test_stack` | [tests/test_stack.cpp](tests/test_stack.cpp) | 模板栈的边界、后进先出与赋值异常回归检查 |
| `useDMA` | [usedma.cpp](usedma.cpp) | 运行 DMA 类继承与复制演示 |
| `test_dma` | [tests/test_dma.cpp](tests/test_dma.cpp) | `baseDMA` 与 `hasDMA` 赋值时的资源所有权和分配失败回归 |

默认开启 `BUILD_TESTING`，不需要 Python 或第三方库。日常生成的 `build*/` 目录已忽略；既有历史构建产物本轮未清理。

## MyArray 的复制与生命周期

[MyArray.hpp](MyArray.hpp) 是固定容量的教学容器，元素需要可以默认构造和复制赋值。`std::unique_ptr<T[]>` 管理数组，复制构造仍逐个复制逻辑元素；即使某个元素赋值抛异常，已分配数组也会自动释放。

复制赋值先构造完整副本，再交换指针、容量和大小。成功后两份数组互不共享存储；失败时目标原有内容、容量和大小保持不变。自赋值直接保留原值，不会把数组清空。只读数组可使用 const 下标和查询函数，头文件不再引入全局 `using namespace std`。

保留原有接口约定：

- `Push_Back` 在容量已满时不插入；`Pop_Back` 在空数组上不操作。
- 容量为 0 合法；负容量抛出 `std::invalid_argument`。
- `operator[]` 不检查边界，调用者需保证 `0 <= index < getSize()`。
- 容量内所有槽位在构造时默认构造，删除尾部只修改逻辑大小；元素到整个数组释放时才析构，行为与 `std::vector` 不同。

## 模板栈的赋值异常

[stacktp.h](stacktp.h) 的 `Stack<Type>` 固定容纳 10 个元素，保留原来的 `istempty()`、`isfull()`、`push()` 和 `pop()` 接口。元素需要可以默认构造和复制赋值。

`push()` 在元素赋值成功后才增加元素数量；`pop()` 在输出赋值成功后才减少元素数量。如果赋值抛异常，异常继续传给调用者，栈的元素数量保持不变，可以重试，不会多出一个未成功插入的元素或丢失待弹出的栈顶。失败的赋值仍可能改变未使用的槽位，或调用者传给 `pop()` 的输出对象；栈不负责回滚元素类型本身的赋值副作用。

栈满时 `push()` 返回 `false`，栈空时 `pop()` 返回 `false`，两者均不尝试赋值。弹出只减少逻辑数量，槽位在栈对象销毁时才析构。

## DMA 类的赋值异常

[dma.cpp](dma.cpp) 中的 `baseDMA` 和 `hasDMA` 都拥有动态分配的字符数组。赋值现在先准备新数组，再替换旧数组；`hasDMA` 在修改基类部分前准备好自己的 `style`。如果任一次分配抛出 `std::bad_alloc`，目标对象仍保持原来的标签、评分和样式，可以继续使用或重新赋值。回归测试分别让基类分配、派生类样式分配以及派生类赋值中的基类分配失败，并检查源对象和目标对象的内容。

## 验证

15 组 CTest 包括：

- `MyArray` 的 7 组回归：容量边界、深复制与链式赋值、自赋值、复制构造异常后的资源回收、赋值失败时原值不变、元素默认构造失败、插入失败后的大小与重试。
- 模板栈的 4 组回归：空/满边界与后进先出、在不同深度插入失败后重试、在不同深度弹出失败后重试，以及与 `std::vector` 对照的 5,000 次入栈/出栈操作。异常用例使用会先修改目标再抛出的元素赋值，空/满拒绝路径也检查不会触发赋值。
- DMA 类的 4 组回归：普通复制与自赋值，以及上述三种分配失败后的原值保留和重试。

测试断言在 Release 构建中也生效。

```sh
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build-asan --parallel
ASAN_OPTIONS=detect_leaks=0 UBSAN_OPTIONS=halt_on_error=1 \
  ctest --test-dir build-asan --output-on-failure
```

CI 使用 Linux / macOS Clang 的 ASan 和 UBSan，Linux 额外开启泄漏检查。测试通过不代表其余未整理章节已完成审查。
