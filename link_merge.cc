/*************************************************************************
 > File Name: link_merge.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Mon 04 May 2015 22:26:19 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
}node_t,*pnode;

void link_show(pnode phead);
void link_destroy(pnode phead);
void link_init_from_input(pnode *phead);
void link_merge(pnode *phead_1,pnode *phead_2,pnode* phead_3);

int main()
{
    pnode phead_1 = NULL;
    pnode phead_2 = NULL;
    pnode phead_3 = NULL;
    link_init_from_input(&phead_1);
    link_init_from_input(&phead_2);
    link_merge(&phead_1,&phead_2,&phead_3);
    link_show(phead_3->next);
    link_destroy(phead_1);
    link_destroy(phead_2);
    link_destroy(phead_3);
    return 0;
}

void link_init_from_input(pnode *phead)
{
    int val;
    pnode pnew = NULL;
    pnode ptail = NULL;
    while(fflush(stdin),scanf("%d",&val) != EOF)
    {
        pnew = (pnode)calloc(1,sizeof(node_t));
        pnew->val = val;
        if(*phead == NULL)
        {
            *phead = pnew;
            ptail = pnew;
        }
        else {
            ptail->next = pnew;
            ptail = pnew;
        }
    }
}

void link_show(pnode phead)
{
    pnode pcur = phead;
    while(pcur)
    {
        printf("%d ",pcur->val);
        pcur = pcur->next;
    }
    printf("\n");
}

void link_destroy(pnode phead)
{
    pnode pcur = phead;
    pnode ptmp = NULL;
    while(pcur)
    {
        ptmp = pcur->next;
        free(pcur);
        pcur = ptmp;
    }
    phead = NULL;
}

void link_merge(pnode *phead_1,pnode* phead_2,pnode* phead_3)
{
    pnode pnew;
    pnode pcur_1 = *phead_1;
    pnode pcur_2 = *phead_2;
    pnode pcur_3 ;
    *phead_3 = (pnode)calloc(1,sizeof(node_t));
    pcur_3 = *phead_3;
    while(pcur_1 != NULL && pcur_2 != NULL)
    {
        if(pcur_1->val < pcur_2->val)
        {
            pnew = (pnode)calloc(1,sizeof(node_t));
            pnew->val = pcur_1->val;
            pcur_3->next = pnew;
            pcur_1 = pcur_1->next;
            pcur_3 = pnew;
        }
        else {
            pnew = (pnode)calloc(1,sizeof(node_t));
            pnew->val = pcur_2->val;
            pcur_3->next = pnew;
            pcur_2 = pcur_2->next;
            pcur_3 = pnew;
        }
    }
    if(pcur_1 == NULL)
    {
        while(pcur_2)
        {
            pnew = (pnode)calloc(1,sizeof(node_t));
            pnew ->val = pcur_2->val;
            pcur_3->next = pnew;
            pcur_2 = pcur_2->next;
            pcur_3 = pnew;
        }
    }
    if(pcur_2 == NULL)
    {
        while(pcur_1)
        {
            pnew = (pnode)calloc(1,sizeof(node_t));
            pnew->val = pcur_1->val;
            pcur_3->next = pnew;
            pcur_1 = pcur_1->next;
            pcur_3 = pnew;
        }
    }
}
