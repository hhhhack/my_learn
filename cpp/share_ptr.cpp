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
 * @Date: 2021-04-23 11:42:44
 * @LastEditTime: 2021-04-25 16:10:31
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/cpp/share_ptr.cpp
 * 
 */
#include <memory>
#include <iostream>
#include "common.h"
using namespace std;

void test_share_ptr(char *ch_ptr)
{
    shared_ptr<char *> sp = make_shared<char *>(ch_ptr);
    cout << "value of ptr is " << *sp << endl;
}
int testA::i = 0;
int main()
{
    testA a;
    // shared_ptr<testA> sp_1(&a);
    psplit("错误演示");
    shared_ptr<testA> sp_1 = make_shared<testA>(a);
    return 0;
}
