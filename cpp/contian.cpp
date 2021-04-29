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
 * @Date: 2021-04-25 16:10:58
 * @LastEditTime: 2021-04-28 15:50:36
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/cpp/contian.cpp
 * 
 */

#include <vector>
#include <iostream>
using namespace std;
void coutvec(vector<int> &input, string name = "")
{
    cout << "vector " << name << " size is " << input.size() << " capacity is " << input.capacity();
    for (auto i : input)
        cout << " " << i;
    cout << endl;
}

int main()
{
    int a[10] = {23};
    vector<int> vec_1(10, 20);
    vec_1.push_back(21);
    coutvec(vec_1, "vec_1");

    vector<int> vec_2(a, a);

    coutvec(vec_2, "vec_2");
}