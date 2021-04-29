/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 * 
 * @Author: hhhhack
 * @Date: 2021-04-23 11:38:35
 * @LastEditTime: 2021-04-23 16:44:29
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/cpp/move.cpp
 * 
 */

#include <vector>
#include <iostream>
#include <string.h>
#include "common.h"
using namespace std;

int testA::i = 0;

testA creatA()
{
    testA tmp{new char[10], new int(10)};
    tmp.printA();
    return tmp;
}

int main()
{
    vector<testA> vec;
    // 调用空构造函数
    testA a;
    a.printA();
    psplit();
    // creat调用构造函数，然后调用移动赋值函数
    a = creatA();
    a.printA();
    psplit();
    testA &&b = creatA();
    b.printA();
    psplit("rvalue_ref");
    testA c(b);
    c.printA();
    psplit("rval_ref to lef ");
    testA d;
    d = move(c);
    psplit("l_val move r_ref ");
    // creat调用构造函数，然后直接调用移动构造函数
    vec.emplace_back(creatA());
    vec[0].printA();
    psplit();
    // creat调用构造函数，然后调用移动构造函数创建临时变量，再调拷贝构造函数
    vec.push_back(creatA());
    vec[1].printA();
    psplit();
    // 调用默认构造函数创建对象
    vec.push_back(testA());
    vec[2].printA();
    psplit();

    vec.emplace_back(testA());
    vec[3].printA();
    psplit();

    vec.push_back(d);
    vec[4].printA();
    psplit("push back l ref ");
    // 调用移动构造函数
    vec.push_back(move(d));
    vec[5].printA();
    psplit("push back l and r ref ");
    // 调用拷贝构造函数
    vector<testA> vec_1(vec);
    psplit("vector to vector ");
    // 调用拷贝构造函数
    vector<testA> vec_2(3, a);
    psplit("n testA to vector ");

    psplit("share_ptr start ");

    return 0;
}