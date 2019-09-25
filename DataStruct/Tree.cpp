#include<iostream>
using namespace std;
typedef struct node * tree;
class Tree{
    public:
            Tree();//初始化二叉树
        int GetTreeDepth();//查询二叉树深度
        void preSearchTree();//前序遍历
        void midSearchTree();//中序遍历
        void aftSearchTree();//后序遍历
    private:
            struct node
            {
                int val;
                struct node * lchild;
                struct node * rchild;
                /* data */
            };
            
            
};