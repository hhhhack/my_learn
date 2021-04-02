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
 * @Date: 2021-04-02 13:14:03
 * @LastEditTime: 2021-04-02 19:19:40
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/alg/Sort.cpp
 * 
 */
#include "Sort.h"

void insert_sort(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return;
    }
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        auto tmp = nums[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (tmp < nums[j])
            {
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
            else
            {
                break;
            }
        }
    }
    return;
}

static int partition(vector<int> &nums, int start, int end)
{
    auto mid = nums[start];
    int cur = start + 1;
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] < mid)
        {
            if (cur != i)
            {
                nums[i] += nums[cur];
                nums[cur] = nums[i] - nums[cur];
                nums[i] -= nums[cur];
            }
            cur++;
        }
    }
    if (cur - 1 != start)
    {
        nums[start] += nums[cur - 1];
        nums[cur - 1] = nums[start] - nums[cur - 1];
        nums[start] -= nums[cur - 1];
    }

    return cur - 1;
}

void quic_sort(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = partition(nums, start, end);
        quic_sort(nums, start, mid - 1);
        quic_sort(nums, mid + 1, end);
    }
}