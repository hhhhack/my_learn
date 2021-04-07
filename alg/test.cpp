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
 * @Date: 2021-04-02 13:28:19
 * @LastEditTime: 2021-04-06 22:10:17
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/alg/test.cpp
 * 
 */

#include "Sort.h"
#include <cstdlib>
#include <ctime>
int main()
{
    unsigned int length;
    cin >> length;
    vector<int> input(length);
    for (unsigned int i = 0; i < length; i++)
    {
        input[i] = rand() % (3 * length);
    }
    vector<int> input2(input.begin(), input.end());
    vector<int> input3(input.begin(), input.end());
    auto time_1 = clock();
    //insert_sort(input);
    count_sort(input, 0, 3 * length);
    auto time_2 = clock();
    quic_sort(input2, 0, length - 1);
    auto time_3 = clock();
    heap_sort(input3);
    if (length < 20)
        for (int i : input2)
        {
            cout << i << " ";
        }
    auto time_4 = clock();
    cout << "count time is " << time_2 - time_1 << " quick time is " << time_3 - time_2 << " heap time is " << time_4 - time_3 << endl;
}
