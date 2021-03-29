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
			printf("\n������0~9������\n");
			scanf("%d",&key);
		}while(isdigit(key));
		switch(key){
			case 0:{
				system("cls");
				
				InitList(&L);
            	TraverseList(L,visit);
            	printf("\n��������ɹ���\n");
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
					printf("�������ڣ�");
					system("pause");
            		system("cls"); 
				}
				break;
			}
			case 2:{
            	DestroyList(&L);
            	system("cls");
            	printf("ɾ������ɹ�!");
            	system("pause");
				break;
			}
			case 3:{
				int position,content;
				printf("����������λ�ã�");
				scanf("%d",&position);
				LinkedList p =FindNode(L,position);
				printf("\n������ڵ����ݣ�"); 
				scanf("%d",&content);
				LinkedList q = (LinkedList)malloc(sizeof(LNode));
				q->data = content;
				if (InsertList(p, q)){
					printf("����ɹ���\n");
			    	TraverseList(L,visit);
				} 
			    else{printf("����ʧ�ܣ�\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{
				int content;
				if(L!=NULL){
					printf("��������Ҫ���ҵ����ݣ�\n");
					scanf("%d",&content);
					if(SearchList(L,content)){
						printf("�����ݴ�������֮��\n");
					}else{
						printf("���޴�����\n"); 
					} 
				}else{
					printf("�������ڣ�\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				if(ReverseList(&L)){
					printf("��������ɹ���\n");
					TraverseList(L,visit);	
					system("pause");
					system("cls");
				}else{
					printf("����δ֪����\n");
				}
				break;
			}
			case 6:{
				if(!IsLoopList(&L)){
					printf("����ѭ����\n");
					system("pause");
					system("cls");
				}else{
					printf("����ѭ����\n");
					system("pause");
					system("cls");
				}
				break;
			}
			case 7:{
				if(L!=NULL){
					ReverseEvenList(&L);
					printf("��ż�����ɹ���\n");
					TraverseList(L,visit);
					system("pause");
					system("cls");	
				}else{
					printf("�������ڣ�\n");
					system("pause");
					system("cls");
				}	
				break;
			} 
			case 8:{
				if(L!=NULL){
					LinkedList middle;
					middle=FindMidNode(&L);
					printf("�м�ڵ������Ϊ%d\n",middle->data);
					system("pause");
					system("cls");
				}else{
					printf("�������ڣ�\n");
					system("pause");
					system("cls");
				}
				break;
			}
			case 9:{
				system("cls");
            	int position, content;
            	printf("������ɾ���Ľ�㣺");
            	scanf("%d", &position);
            	if (DeleteList(FindNode(L, position), &content)) {
				printf("���ɾ���ɹ���\n");
				printf("�ý�������Ϊ:%d\n", content);	
				}else{
					printf("ɾ��ʧ�ܣ�\n");
				}
				system("pause");
				system("cls");
            	break;
			}
		}
	};
}
