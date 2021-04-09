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
 * @Date: 2021-04-09 17:28:40
 * @LastEditTime: 2021-04-09 19:05:06
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/alg/DateStruct.h
 * 
 */
#include <vector>
using namespace std;

struct node
{
    node *left, *right, *parent;
    int key;
    int value;
    node(node *l, node *r, node *f, int k, int v) : left(l), right(r), parent(f), key(k), value(v){};
};

struct Bst
{
    node *root;
    int deep;
    int count;
    vector<int> inorder_tree_walk();
    node *find_by_key(int key);
    node *min();
    node *max();
    Bst(node *fa, int deep, int count) : root(fa), deep(deep), count(count){};
    void insert(int val);
    void insert(node *data);
    void insert(node data);
};