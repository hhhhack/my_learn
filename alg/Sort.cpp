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
 * @LastEditTime: 2021-04-09 17:54:37
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/alg/Sort.cpp
 * 
 */
#include "Sort.h"

/*** 比较排序 ***/
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

#define parent(i) (((i)-1) / 2)
#define left(i) (((i)*2) + 1)
#define right(i) (((i) + 1) * 2)

void exchange(vector<int> &input, int i, int j)
{
    int length = input.size();
    if (i == j || i < 0 || j < 0 || i >= length || j >= length)
    {
        return;
    }
    input[i] += input[j];
    input[j] = input[i] - input[j];
    input[i] -= input[j];
}

void max_heapity(vector<int> &input, int i, int length)
{
    int ls = left(i), rs = right(i), largest = i;
    if (ls < length && input[ls] > input[largest])
    {
        largest = ls;
    }
    if (rs < length && input[rs] > input[largest])
    {
        largest = rs;
    }
    if (largest != i)
    {
        exchange(input, i, largest);
        max_heapity(input, largest, length);
    }
}

void build_max_heap(vector<int> &input)
{
    for (int i = parent(input.size()); i >= 0; i--)
    {
        max_heapity(input, i, input.size());
    }
}

void heap_sort(vector<int> &input)
{
    build_max_heap(input);
    for (int i = input.size() - 1; i >= 1;)
    {
        exchange(input, i, 0);
        i--;
        max_heapity(input, 0, i);
    }
}

/*** 比较排序 ***/

/*** 线性排序 ***/
/**** 计数排序 ****/
void count_sort(vector<int> &input, int min, int max)
{
    int n = max - min + 1;
    vector<int> count(n, 0);
    for (auto i = input.begin(); i != input.end(); i++)
    {
        count[*i]++;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                input[k++] = i;
            }
        }
    }
}

/*** 顺序计量 ***/
/**** 最大最小值 ****/
int max(vector<int> &input)
{
    int max = input[0];
    for (auto i = input.begin() + 1; i != input.end(); i++)
    {
        if (*i > max)
        {
            max = *i;
        }
    }
    return max;
}

vector<int> max_and_min(vector<int> &input)
{
    int min = input[0], max = input[0];
    for (auto i = 1; i + 1 < input.size();)
    {
        if (input[i] > input[i + 1])
        {
            max = max > input[i] ? max : input[i];
            min = min < input[i + 1] ? min : input[i + 1];
        }
        else
        {
            max = max > input[i + 1] ? max : input[i + 1];
            min = min < input[i] ? min : input[i];
        }
    }
    return vector<int>{max, min};
}
/**** 第N位数 ****/
// struct rst
// {
//     bool ok;
//     int ret;
// };

// int binary_find(vector<int> input, int start, int end)
// {
//     int tmp = input[0];
//     for (int i = start; i <=)
// }

// rst find_thN(vector<int> &input, int n)
// {
//     if (n > input.size())
//     {
//         return rst{false, -1};
//     }
//     binary_find()
// }
