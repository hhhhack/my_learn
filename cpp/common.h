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
 * @Date: 2021-04-23 16:42:05
 * @LastEditTime: 2021-04-23 16:46:55
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/cpp/common.h
 * 
 */

#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
class testA
{
public:
    static int i;
    static void add_i()
    {
        i++;
    }
    static int get_i()
    {
        return i;
    }
    char *a;
    int *b;
    int c;
    string d;
    testA()
    {
        a = nullptr;
        b = nullptr;
        add_i();
        c = get_i();
        cout << "tesA noting i is " << i << endl;
    }
    testA(testA &&A) : a(A.a), b(A.b)
    {
        A.a = nullptr;
        A.b = nullptr;
        d = A.d;
        add_i();
        c = get_i();
        cout << "test && A  i is " << i << endl;
    };
    testA(const testA &A)
    {
        if (A.a != nullptr)
            a = strdup(A.a);
        b = new int;
        if (A.b != nullptr)
            *b = *(A.b);
        add_i();
        c = get_i();
        d = A.d;
        cout << "test & A i is " << i << endl;
    };
    testA(char *a1, int *b1)
    {
        this->a = strdup(a1);
        this->b = new int(*b1);
        add_i();
        c = get_i();
        this->d = string(a1);
        cout << "test a b c  i is " << i << endl;
    };
    ~testA()
    {
        cout << "~ testA c is " << c << endl;
        // i--;
        delete[] a;
        delete b;
    };
    testA &operator=(const testA &A)
    {
        cout << "operator A& " << endl;
        if (A.a)
            a = strdup(A.a);
        b = new int;
        if (A.b)
        {
            *b = *(A.b);
        }
        // c = A.c;
        d = A.d;
        return *this;
    }
    testA &operator=(testA &&A)
    {
        cout << "operator A&& " << endl;
        a = A.a;
        b = A.b;
        // c = A.c;
        d = A.d;
        A.a = nullptr;
        A.b = nullptr;
        return *this;
    }
    void printA()
    {
        cout << "this ptr is "
             << (void *)this << " this a is " << (void *)this->a << " this b is " << (void *)this->b << " id is " << c << endl;
    }
};

inline void psplit(string info = "")
{
    cout << "----------分割线------------ "
         << info
         << '\n'
         << endl;
}