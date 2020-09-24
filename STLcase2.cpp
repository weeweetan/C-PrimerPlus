//
// Created by 11135 on 2020/8/24.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

#define CEHUA   0
#define MEISHU  1
#define YANFA   2


using namespace std;

class Worker
{
public:
    string m_Name;
    int m_Salary;
};


void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;       //10000 - 19999
        v.push_back(worker);
    }
}


void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门号
        int deptId = rand() % 3;

        //将员工插入到分组中
        m.insert(make_pair(deptId, *it));
    }
}


void showWorkerByGroup(multimap<int, Worker> & m)
{
    // 0 A B C 1 D E 2 F G...
    cout << "策划部门：" << endl;
    auto pos = m.find(CEHUA);
    int count = m.count(CEHUA); //统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" <<  pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }

    cout << endl;
    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); //统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" <<  pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }

    cout << endl;
    cout << "研发部门：" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); //统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" <<  pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }

}

int main(int argc, char **argv)
{
    srand((unsigned int) time(NULL));

    vector<Worker> vWorker;
    createWorker(vWorker);

    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    //分组显示员工
    showWorkerByGroup(mWorker);

    //test
/*    for (auto it = vWorker.begin(); it != vWorker.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 工资：" << it->m_Salary << endl;
    }*/



}