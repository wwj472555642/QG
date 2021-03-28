#include "./duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void menu(){
	printf("----------------������----------------\n");
	printf("------------0������������ֵ------------\n");
	printf("------------1��������չ���б�------------\n");
	printf("------------2��ɾ������------------\n");
	printf("------------3�����ض��ڵ�ǰ����ڵ�------------\n");
	printf("------------4�����ض��ڵ�����ڵ�------------\n");
	printf("------------5��ɾ���ڵ�------------\n");
	printf("------------6���ر�------------\n");
}
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(*L==NULL){
		printf("�ڴ�ռ��쳣���޷�����");
		return ERROR;	
	}
	int num;
	DuLinkedList p, q;
	int i = 0;
	p = (*L);
	(*L)->prior=NULL;
	ElemType e;
	printf("������ڵ����\n");
	scanf("%d",&num); 
	printf("������ڵ�����\n");
	while (i < num) {
		scanf("%d", &e);
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		q->data = e;
		p->next = q;
		q->prior=p;
		p = q;
		i++;
	}
	p->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p,q;
	p=*L;
	while (p != NULL) {         //���ڵ�ָ�����ڶ�����ʱ����� 
        q = p->next;
        free(p);
        p = q;
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	DuLNode *temp;
	temp=p->prior;
	p->prior=q;
	q->next=p;
	q->prior=temp;
	temp->next=q;
	return SUCCESS; 
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	DuLNode *temp;
	temp=p->next;
	p->next=q;
	q->next=temp;
	return SUCCESS; 
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *temp;
	*e=p->next->data;
	if(p->next==NULL){    //ָ��Ϊ���һ���ڵ�ʱ���� 
		printf("�Ѿ������һ���ڵ㣡");
		return ERROR;
	}
	temp=p->next->next;
	if(temp!=NULL){
		temp->prior=p;
	}
	free(p->next);
	p->next=temp;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p;
    p = L->next;
    while (p != NULL) {   //�������� 
        (*visit)(p->data);      //��ÿ���ڵ�������Ϊ�βδ��ݵ�visitָ��ĺ��� 
        p = p->next;
    }
}
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
 *  @name        : FindNode(LinkedList L, int i)
 *	@description : find the  node you want 
 *	@param		 : L(the head node) i(the position you want)
 *	@return		 : LNode
 *  @notice      :None
 */
DuLNode* FindNode(DuLinkedList L, int i) {
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
