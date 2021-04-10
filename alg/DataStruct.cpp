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
 * @Date: 2021-04-09 16:26:52
 * @LastEditTime: 2021-04-10 15:07:29
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/alg/DataStruct.cpp
 * 
 */
#include <stack>
#include <limits.h>
#include "DateStruct.h"

node *Bst::min()
{
    auto cur = this->root;
    while (cur->left != nullptr)
    {
        cur = cur->left;
    }
    return cur;
}
node *Bst::max()
{
    auto cur = this->root;
    while (cur->right != nullptr)
    {
        cur = cur->right;
    }
    return cur;
}

node *find_key(node *cur, int key)
{
    if (cur == nullptr || cur->key == key)
    {
        return cur;
    }
    else if (cur->key < key)
    {
        return find_key(cur->right, key);
    }
    return find_key(cur->right, key);
}

node *Bst::find_by_key(int key)
{
#ifdef Recursion
    return find_key(this->root, key);
#else
    node *cur = this->root;
    while (cur != nullptr && cur->key != key)
    {
        cur = cur->key > key ? cur->left : cur->right;
    }
    return cur;
#endif
}

void tree_walk(node *cur, vector<int> &output)
{
    if (cur == nullptr)
    {
        return;
    }
    tree_walk(cur->left, output);
    output.push_back(cur->value);
    tree_walk(cur->right, output);
}

vector<int> Bst::inorder_tree_walk()
{
    vector<int> ret(this->count);
#ifdef Recursion
    tree_walk(this->root, ret);
#else
    stack<node *> nodesta;
    nodesta.push(this->root);
    node *cur = root;
    while (nodesta.size() != 0)
    {
        if (cur == nullptr)
        {
            cur = nodesta.top();
            nodesta.pop();
            ret.push_back(cur->value);
            if (cur->right != nullptr)
            {
                nodesta.push(cur->right);
            }
            cur = cur->right;
            continue;
        }
        cur = cur->left;
        if (cur != nullptr)
            nodesta.push(cur);
    }

#endif
    return ret;
}

void Bst::insert_node(node innode)
{
    Bst::insert_node(innode.value);
}

void Bst::insert_node(node *innode)
{
    if (innode == nullptr)
    {
        return;
    }
    Bst::insert_node(innode->value);
}

void Bst::insert_node(int val)
{
    auto getkey = [](int value) -> int { return val % SHRT_MAX };
    int key = getkey(val);
    auto innode = new node(nullptr, nullptr, nullptr, key, val);
    auto cur = this->root, p = nullptr;
    while (cur != nullptr)
    {
        p = cur;
        if (cur->key > key)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right
        }
    }
    auto innode = new node(nullptr, nullptr, p, key, val);
    if (p == nullptr)
    {
        this->root = innode;
    }
    else if (p->key > key)
    {
        p->left = innode;
    }
    else
    {
        p->right = innode;
    }
}

void delete