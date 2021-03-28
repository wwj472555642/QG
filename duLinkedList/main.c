#include <stdio.h>
#include "duLinkedList.h"
DuLinkedList L;
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
				InitList_DuL(&L);
            	TraverseList_DuL(L,visit);
            	printf("\n��������ɹ���\n");
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
					printf("�������ڣ�");
					system("pause");
            		system("cls"); 
				}
				break;
			}
			case 2:{
				DestroyList_DuL(&L);
            	system("cls");
            	printf("ɾ������ɹ�!\n");
            	system("pause");
				break;
			}
			case 3:{
				int position,content;
				printf("����������λ�ã�");
				scanf("%d",&position);
				DuLinkedList p =FindNode(L,position);
				printf("\n������ڵ����ݣ�"); 
				scanf("%d",&content);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = content;
				if (InsertBeforeList_DuL(p, q)){
					printf("����ɹ���\n");
			    	TraverseList_DuL(L,visit);
				} 
			    else{printf("����ʧ�ܣ�\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 4:{
				int position,content;
				printf("����������λ�ã�");
				scanf("%d",&position);
				DuLinkedList p =FindNode(L,position);
				printf("\n������ڵ����ݣ�"); 
				scanf("%d",&content);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = content;
				if (InsertAfterList_DuL(p, q)){
					printf("����ɹ���\n");
			    	TraverseList_DuL(L,visit);
				} 
			    else{printf("����ʧ�ܣ�\n");} 
				system("pause");
				system("cls"); 
				break;
			}
			case 5:{
				system("cls");
            	int position, content;
            	printf("������ɾ���Ľ�㣺");
            	scanf("%d", &position);
            	if (DeleteList_DuL(FindNode(L, position), &content)) {
				printf("���ɾ���ɹ���\n");
				printf("�ý�������Ϊ:%d\n",content);	
				}else{
					printf("ɾ��ʧ�ܣ�\n");
				}
				system("pause");
				system("cls");
				break;
			} 
		} 
	}
}
