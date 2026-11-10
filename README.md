# C-PrimerPlus

《C++ Primer Plus》与 C++ 基础练习代码，保留原来的章节文件名。本轮整理聚焦于 `MyArray` 的资源所有权和复制行为；其他章节暂未逐一纳入验证。

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

默认开启 `BUILD_TESTING`，不需要 Python 或第三方库。日常生成的 `build*/` 目录已忽略；既有历史构建产物本轮未清理。

## MyArray 的复制与生命周期

[MyArray.hpp](MyArray.hpp) 是固定容量的教学容器，元素需要可以默认构造和复制赋值。`std::unique_ptr<T[]>` 管理数组，复制构造仍逐个复制逻辑元素；即使某个元素赋值抛异常，已分配数组也会自动释放。

复制赋值先构造完整副本，再交换指针、容量和大小。成功后两份数组互不共享存储；失败时目标原有内容、容量和大小保持不变。自赋值直接保留原值，不会把数组清空。只读数组可使用 const 下标和查询函数，头文件不再引入全局 `using namespace std`。

保留原有接口约定：

- `Push_Back` 在容量已满时不插入；`Pop_Back` 在空数组上不操作。
- 容量为 0 合法；负容量抛出 `std::invalid_argument`。
- `operator[]` 不检查边界，调用者需保证 `0 <= index < getSize()`。
- 容量内所有槽位在构造时默认构造，删除尾部只修改逻辑大小；元素到整个数组释放时才析构，行为与 `std::vector` 不同。

## 验证

7 组 CTest 覆盖容量边界、深复制与链式赋值、自赋值、复制构造异常后的资源回收、赋值失败时原值不变、元素默认构造失败、插入失败后的大小与重试。测试断言在 Release 构建中也生效。

```sh
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build-asan --parallel
ASAN_OPTIONS=detect_leaks=0 UBSAN_OPTIONS=halt_on_error=1 \
  ctest --test-dir build-asan --output-on-failure
```

CI 使用 Linux / macOS Clang 的 ASan 和 UBSan，Linux 额外开启泄漏检查。测试通过不代表其余未整理章节已完成审查。
