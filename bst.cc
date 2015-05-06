/*************************************************************************
 > File Name: bst.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Tue 05 May 2015 20:51:30 CST
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct node
{
    struct node* lchild;
    struct node* rchild;
    struct node* parent;
    int nd_val;
}node_t,*pnode_t;

int creatTree(pnode_t *root,int arr[],int len);
int insertTree(pnode_t *root,int val);
int printTree(pnode_t root,int len);
bool delete_by_val(pnode_t *root,int val);
int level_Order(pnode_t root);
void inOrder(pnode_t root);
bool isleaf(pnode_t node)
{
    return (node->lchild == NULL && node->rchild==NULL);
}


int main()
{
    int arr[] = {5,8,7,9,4,10,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
    pnode_t root = NULL;
    creatTree(&root,arr,len);
    inOrder(root);
    cout << endl;
    cout << "rm 1: " << endl;
    delete_by_val(&root,1);
    inOrder(root);
    cout << endl;
    cout << "rm 9: " << endl;
    delete_by_val(&root,9);
    inOrder(root);
    return 0;
}

int creatTree(pnode_t *root,int arr[],int len)
{
    for(int i = 0;i < len;++i)
        insertTree(root,arr[i]);
    return 1;
}

int insertTree(pnode_t *root ,int val)
{
    pnode_t pnew = NULL;
    pnew = (pnode_t)(calloc(1,sizeof(node)));
    pnew->nd_val = val;
    pnew->lchild = NULL;
    pnew->rchild = NULL;

    pnode_t pcur = NULL;
    if(*root == NULL)
        *root = pnew;
    else {
        pcur = *root;
        while(1)
        {
            if(pcur->nd_val > val)
            {
                if(pcur->lchild == NULL)
                {
                    pcur->lchild = pnew;
                    pnew->parent = pcur;
                    break;
                }
                else {
                    pcur = pcur->lchild;
                    continue;
                }
            }
            if(pcur->nd_val <= val)
            {
                if(pcur->rchild == NULL)
                {
                    pcur->rchild = pnew;
                    pnew->parent = pcur;
                    break;
                }
                else {
                    pcur = pcur->rchild;
                    continue;
                }
            }
        }
    }
    return 1;
}

void inOrder(pnode_t root)
{
    if(root)
    {
        inOrder(root->lchild);
        inOrder(root->rchild);
        printf("%d ",root->nd_val);
    }
}
bool delete_by_val(pnode_t *root,int val)
{
    if(*root == NULL)
        return false;
    else {
        pnode_t pcur = *root;
        while(pcur->nd_val != val)
        {
            if(pcur->nd_val > val)
            {
                pcur = pcur->lchild;
            }
            else {
                pcur = pcur->rchild;
            }
        }
        if(isleaf(pcur))
        {
            if(pcur->parent->lchild == pcur)
                pcur->parent->lchild = NULL;
            else {
                pcur->parent->rchild = NULL;
            }
            return true;
        }
        else if(!(pcur->lchild != NULL && pcur->rchild !=NULL))
        {
            if(pcur->lchild == NULL)
            {
                if(pcur->parent->lchild == pcur)
                    pcur->parent->lchild = pcur->rchild;
                else {
                    pcur->parent->rchild = pcur->rchild;
                }
            }
            else {
                if(pcur->parent->lchild == pcur)
                    pcur->parent->lchild = pcur->lchild;
                else {
                    pcur->parent->rchild = pcur->lchild;
                }
            }
            return true;
        }
        else {
            pnode_t ptmp = pcur;
            pcur->lchild = NULL;
            pcur->rchild->parent = pcur->parent;
            pcur->parent->rchild = pcur->rchild;
            int ival = ptmp->nd_val;
            while(pcur)
            {
                if(pcur->nd_val > ival)
                {
                    if(pcur->lchild == NULL)
                    {
                        pcur->parent->rchild->lchild = ptmp->lchild;
                        break;
                    }
                    else {
                        pcur = pcur->lchild;
                        continue;
                    }
                }
                else {
                    if(pcur->rchild == NULL)
                    {
                        pcur->rchild = ptmp->lchild;
                        break;
                    }
                    else {
                        pcur = pcur->rchild;
                        continue;
                    }
                }
            }
            return true;
        }
    }
}
