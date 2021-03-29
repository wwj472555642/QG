#include <stdio.h>
#include "linkedList.h"
#include<ctype.h>
LinkedList L=NULL;
int main(){
	while(1){
		char key;
		do{
			system("cls");
			menu();
			printf("\n请输入0~9的数字\n");
			scanf("%d",&key);
		}while(isdigit(key));
		switch(key){
			case 0:{
				system("cls");
				
				InitList(&L);
            	TraverseList(L,visit);
            	printf("\n创建链表成功！\n");
            	system("pause");
            	system("cls"); 
				break;
			}
			case 1:{
				if(L!=NULL){
					TraverseList(L,visit);
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
            	DestroyList(&L);
            	system("cls");
            	printf("删除链表成功!");
            	system("pause");
				break;
			}
			case 3:{
				int position,content;
				printf("请输入插入的位置：");
				scanf("%d",&position);
				LinkedList p =FindNode(L,position);
				printf("\n请输入节点数据："); 
				scanf("%d",&content);
				LinkedList q = (LinkedList)malloc(sizeof(LNode));
				q->data = content;
				if (InsertList(p, q)){
					printf("插入成功！\n");
			    	TraverseList(L,visit);
				} 
			    else{printf("插入失败！\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{
				int content;
				if(L!=NULL){
					printf("输入你想要查找的数据：\n");
					scanf("%d",&content);
					if(SearchList(L,content)){
						printf("该数据存在链表之中\n");
					}else{
						printf("查无此数！\n"); 
					} 
				}else{
					printf("链表不存在！\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				if(ReverseList(&L)){
					printf("链表逆序成功！\n");
					TraverseList(L,visit);	
					system("pause");
					system("cls");
				}else{
					printf("出现未知错误！\n");
				}
				break;
			}
			case 6:{
				if(!IsLoopList(&L)){
					printf("链表不循环！\n");
					system("pause");
					system("cls");
				}else{
					printf("链表循环！\n");
					system("pause");
					system("cls");
				}
				break;
			}
			case 7:{
				if(L!=NULL){
					ReverseEvenList(&L);
					printf("奇偶调换成功！\n");
					TraverseList(L,visit);
					system("pause");
					system("cls");	
				}else{
					printf("链表不存在！\n");
					system("pause");
					system("cls");
				}	
				break;
			} 
			case 8:{
				if(L!=NULL){
					LinkedList middle;
					middle=FindMidNode(&L);
					printf("中间节点的数据为%d\n",middle->data);
					system("pause");
					system("cls");
				}else{
					printf("链表不存在！\n");
					system("pause");
					system("cls");
				}
				break;
			}
			case 9:{
				system("cls");
            	int position, content;
            	printf("请输入删除的结点：");
            	scanf("%d", &position);
            	if (DeleteList(FindNode(L, position), &content)) {
				printf("结点删除成功！\n");
				printf("该结点的数据为:%d\n", content);	
				}else{
					printf("删除失败！\n");
				}
				system("pause");
				system("cls");
            	break;
			}
		}
	};
}
