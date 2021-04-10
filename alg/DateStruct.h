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
 * @LastEditTime: 2021-04-10 15:03:26
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
    void insert_node(int val);
    void insert_node(node *data);
    void insert_node(node data);
    void delete_node(int key);
};
const bool BLACK = false;
const bool RED = true;

struct RbNode : pubilc node
{
    bool rbcolor;
    using node::node;
    RbNode(bool color, node *l, node *r, node *f, int k, int v) : rbcolor(color), node(l, r, f, k, v){};
};

struct RbTree : public Bst
{
    using Bst::Bst;
    static const RbNode leaf{false, nullptr, nullptr, nullptr, 0, 0};
    RbTree(node *fa, int deep, int count) : Bst(fa, deep, count){};
};