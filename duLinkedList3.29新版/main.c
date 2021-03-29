#include <stdio.h>
#include "duLinkedList.h"
DuLinkedList L;
int main(){
	while(1){
		int key;
		do{
			system("cls");
			menu();
			printf("\n请输入数字:");
		}while(!input(&key)||key<0||key>6);
		switch(key){
			case 0:{
				system("cls");	
				if(InitList_DuL(&L)){
					printf("\n创建链表成功！\n");
				}else{
					break;
				} ;
            	TraverseList_DuL(L,visit);
            	system("pause");
            	system("cls"); 
				break;
			}
			case 1:{
				if(L!=NULL){
					TraverseList_DuL(L,visit);
					system("pause");
            		system("cls"); 
				}else{
					printf("链表不存在！");
					system("pause");
            		system("cls"); 
				}
				break;
			}
			case 2:{
				DestroyList_DuL(&L);
            	system("cls");
            	printf("删除链表成功!\n");
            	system("pause");
				break;
			}
			case 3:{
				int position,content;
				printf("请输入插入的位置：");
				if(!input(&position)){
					break;
				}
				DuLinkedList p =FindNode(L,position);
				printf("\n请输入节点数据："); 
				if(!input(&content)){
					break;
				}
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = content;
				if (InsertBeforeList_DuL(p, q)){
					printf("插入成功！\n");
			    	TraverseList_DuL(L,visit);
				} 
			    else{printf("插入失败！\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{
				int position,content;
				printf("请输入插入的位置：");
				if(!input(&position)){
					break;
				}
				DuLinkedList p =FindNode(L,position);
				printf("\n请输入节点数据："); 
				if(!input(&content)){
					break;
				}
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = content;
				if (InsertAfterList_DuL(p, q)){
					printf("插入成功！\n");
			    	TraverseList_DuL(L,visit);
				} 
			    else{printf("插入失败！\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 5:{
				system("cls");
            	int position, content;
            	printf("请输入删除的结点：");
            	if(!input(&position)){
					break;
				}
            	if (DeleteList_DuL(FindNode(L, position), &content)) {
				printf("结点删除成功！\n");
				printf("该结点的数据为:%d\n",content);	
				}else{
					printf("删除失败！\n");
				}
				system("pause");
				system("cls");
				break;
			} 
		} 
	}
}
