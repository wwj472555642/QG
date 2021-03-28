#include "./duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void menu(){
	printf("----------------单链表----------------\n");
	printf("------------0、创建链表并赋值------------\n");
	printf("------------1、遍历并展现列表------------\n");
	printf("------------2、删除链表------------\n");
	printf("------------3、在特定节点前插入节点------------\n");
	printf("------------4、在特定节点后插入节点------------\n");
	printf("------------5、删除节点------------\n");
	printf("------------6、关闭------------\n");
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
		printf("内存空间异常！无法创建");
		return ERROR;	
	}
	int num;
	DuLinkedList p, q;
	int i = 0;
	p = (*L);
	(*L)->prior=NULL;
	ElemType e;
	printf("请输入节点个数\n");
	scanf("%d",&num); 
	printf("请输入节点数据\n");
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
	while (p != NULL) {         //当节点指向倒数第二个的时候结束 
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
	if(p->next==NULL){    //指针为最后一个节点时报错 
		printf("已经是最后一个节点！");
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
    while (p != NULL) {   //遍历链表 
        (*visit)(p->data);      //将每个节点内容作为形参传递到visit指向的函数 
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
		printf("\n已定位至指定位置"); 
		return L;
	}
	if (L == NULL) {
		printf("链表长度不足，仅有%d个节点",n); 
	}
}
