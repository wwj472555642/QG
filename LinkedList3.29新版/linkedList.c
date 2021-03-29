#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void menu(){
	printf("----------------������----------------\n");
	printf("------------0������������ֵ------------\n");
	printf("------------1��������չ���б�------------\n");
	printf("------------2��ɾ������------------\n");
	printf("------------3������ڵ�------------\n");
	printf("------------4����������------------\n");
	printf("------------5����������------------\n");
	printf("------------6���ж������Ƿ�ѭ��------------\n");
	printf("------------7����ż�ڵ����------------\n");
	printf("------------8�������м�ڵ�------------\n");
	printf("------------9��ɾ���ڵ�------------\n");
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));
	if(*L==NULL){
		printf("�ڴ�ռ��쳣���޷�����");
		return ERROR;	
	}
	int num;
	LinkedList p, q;
	int i = 0;
	p = (*L);
	ElemType e;
	printf("������ڵ����\n");
	if(!input(&num)){
		return ERROR;
	}
	printf("������ڵ�����\n");
	while (i < num) {
		if(!input(&e)){
			return ERROR;
		}
		q = (LinkedList)malloc(sizeof(LNode));
		q->data = e;
		p->next = q;
		p = q;
		i++;
	}
	p->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : Create(LinkedList L, int n);
 *	@description : Create a node  
 *	@param		 : L(the head node).n(the num of nodes you want to create)
 *	@return		 : None
 *  @notice      : None
 */

/**
 *  @name        : visit(ElemType e);
 *	@description : printf a num 
 *	@param		 : ElemType e(the num you deliver)
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e){
	printf("%d->",e);
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p,q;
	p=*L;
	while (p != NULL) {         //���ڵ�ָ�����ڶ�����ʱ����� 
        q = p->next;
        free(p);
        p = q;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	LNode *temp;
	temp=p->next;
	p->next=q;
	q->next=temp;
	return SUCCESS; 
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *temp;
	if(p->next==NULL){    //ָ��Ϊ���һ���ڵ�ʱ���� 
		printf("�Ѿ������һ���ڵ㣡");
		return ERROR;
	}
	temp=p->next->next;       //tempָ��p������ڶ����ڵ� 
	*e=p->next->data;
	free(p->next);
	p->next=temp;
	return SUCCESS;	
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
    p = L->next;
    while (p != NULL) {   //�������� 
        (*visit)(p->data);      //��ÿ���ڵ�������Ϊ�βδ��ݵ�visitָ��ĺ��� 
        p = p->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	while (L->data != e) {
        L = L->next;
        if (L == NULL)// ���������δ���ָ����ݣ������ݲ����� 
    	return ERROR;
    }
    return SUCCESS;	
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	//����Ϊ�ջ�ֻ��һ���ڵ��ʱ�򱨴� 
	if ((*L)->next == NULL || (*L)->next->next == NULL){
		return ERROR;
	} 
    LinkedList first,second, temp;
    first = (*L)->next;
    second = first->next;
    (*L)->next->next=NULL;
    temp = NULL;
    while (second != NULL) {
        temp=second;
        second=second->next;
        temp->next=first;
        first=temp;
    }
    (*L)->next=first;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	//�����������ָ�룬������ѭ�����ָ��ض���ĳ��ѭ���е�����ָ�� 
	LinkedList fast,slow;
	fast=slow=L;
	while((fast!=NULL)&&(fast->next!=NULL)){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return SUCCESS;
		}		
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p,q,t;
	p=(*L)->next;
	q=p->next;
	t=q->next;
	p->next=t;
	q->next=p;
	(*L)->next=q;
	while(t!=NULL&&t->next!=NULL){
		q=t->next;
		t=q->next;
		p->next->next=t;
		q->next=p->next;
		p->next=q;
		p=q->next;
	}
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList fast,slow;
	slow=(*L)->next;
	fast=slow->next->next;
	while(fast!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
/**
 *  @name        : FindNode(LinkedList L, int i)
 *	@description : find the  node you want 
 *	@param		 : L(the head node) i(the position you want)
 *	@return		 : LNode
 *  @notice      :None
 */
LNode* FindNode(LinkedList L, int i) {
	int n = 1;
	while(n < i) {
		n++;
		L = L->next;
	}
	if (L!=NULL){
		printf("\n�Ѷ�λ��ָ��λ��"); 
		return L;
	}
	if (L == NULL) {
		printf("�����Ȳ��㣬����%d���ڵ�",n); 
	}
}

Status  input(int *num){
	char input[16] = {0};
    scanf("%10s", input);
    if (sscanf(input, "%d", num) != 1){
        	printf("�����˰ɸ��ǣ���\n");
        	fflush(stdin);
        	system("pause");
        	return ERROR;
	}
    else{
    	return SUCCESS;
	}
   
} 
