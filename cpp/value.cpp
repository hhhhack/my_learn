/*
 * @Author: your name
 * @Date: 2021-04-07 08:12:27
 * @LastEditTime: 2021-04-07 08:14:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /my_learn_1/cpp/value.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
using namespace std;

const int ONESEC = 1000000;

#define cout_value(type, v) cout << "size of type " << #type << \
" is " << sizeof(v) << " value is " << v << endl;

int main(){
    char val_1 = 'v';
    short val_2 = 1;
    int val_3 = 2;
    long val_4 = 043;
    long long val_5 = 0x14;
    wchar_t val_6 = '\a';
    unsigned short val_7 = USHRT_MAX;
    bool val_8 = true;
    float val_9 = 54.5455;
    double val_10 = 3.43e-5;
    auto val_11 = INT_MAX + val_1;

    cout_value(char, val_1);
    cout <<"val_1 字面常量 是" << int(val_1) << " " <<' ';
    cout.put(val_1);
    cout << endl;
    cout_value(short, val_2);
    cout_value(int, val_3);
    cout << oct;
    cout_value(long, val_4);
    cout << hex;
    cout_value(long_long, val_5);
    cout_value(wchar_t, val_6);
    cout_value(u_short, val_7);
    cout_value(bool, val_8);
    cout_value(float, val_9);
    cout_value(double, val_10);
    cout << dec;
    cout_value(int+int, long(long(INT_MAX) + INT_MAX));
    cout_value(auto, val_11);

    return 0;
}