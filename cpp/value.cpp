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
 * @Date: 2021-04-01 19:25:35
 * @LastEditTime: 2021-04-01 20:49:59
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /code/my_learn/cpp/value.cpp
 * 
 */

#include <iostream>
using namespace std;

#define ValueSize(type, v) wcout << "size of type " << #type << " is " << sizeof(v) << " " << v << endl;

int main()
{
    short v1 = 0;
    int v2 = 0;
    long v3 = 0;
    long long v4 = 0;
    char v6 = '0';
    wchar_t *v7 = L"我";
    char16_t v8 = u'啊';
    char32_t v9 = u'啊';
    setlocale(LC_ALL, "chs");
    ValueSize(short, v1);
    ValueSize(int, v2);
    ValueSize(long, v3);
    ValueSize(long_long, v4);
    ValueSize(char, v6);
    ValueSize(wchar_t, v7);
    ValueSize(char16_t, v8);
    ValueSize(char32_t, v9);
    return 0;
}