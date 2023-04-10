#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 10

typedef char BitElemType;
typedef int Status;

typedef struct BiTNode{
    BitElemType data;
    struct BiTNode* lchild,*rchild;
}BiTNode,*BiTree;

//��������������
Status Create_Bitree(BiTree* T){
    char c;
    scanf("%c",&c);
    if(c == ' '){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T) -> data = c;
        Create_Bitree(&(*T) -> lchild);
        Create_Bitree(&(*T) -> rchild);
    }
}

Status visit(BiTree T,int level){
    printf("%c �ڵ� %d ��\n",T -> data,level);
}

//��������ǰ�����(�ݹ�)
Status PreOrder_Traverse(BiTree T,int level){
    if(T){
        visit(T,level);
        PreOrder_Traverse(T -> lchild,level + 1);
        PreOrder_Traverse(T -> rchild,level + 1);
    }
    return OK;
}

//�������ĸ���(�ݹ�)
Status Copy_BitTree(BiTree* Tnew,const BiTree T){
    if(T){
        *Tnew = (BiTree)malloc(sizeof(BiTNode));
        (*Tnew) -> data = T -> data;
        Copy_BitTree(&(*Tnew) -> lchild,T -> lchild);
        Copy_BitTree(&(*Tnew) -> rchild,T -> rchild);
    }else{
        *Tnew = NULL;
        return ERROR;
    }
}

//�����
Status Depth(BiTree T){
    if(T){
        int m = Depth(T -> lchild);
        int n = Depth(T -> rchild);
        if(m > n){
            return m + 1;
        }else{
            return n + 1;
        }
    }else if(T == NULL){
        return ERROR;
    }
}

//������
Status Nodes(BiTree T){
    if(T){
        return 1 + Nodes(T -> lchild) + Nodes(T -> rchild);
    }else{
        return ERROR;
    }
}

int main(){
    BiTree T = NULL;
    BiTree T1 = NULL;
    int level = 1;

    Create_Bitree(&T);

    //Copy_BitTree(&T1,T);

    PreOrder_Traverse(T,1);
    printf("#####################\n");
    printf("%d\n",Depth(T));
    printf("%d\n",Nodes(T));
    //PreOrder_Traverse(T1,1);
}
