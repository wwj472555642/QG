#include <stdio.h>
#include "duLinkedList.h"
DuLinkedList L;
int main(){
	while(1){
		int key;
		do{
			system("cls");
			menu();
			printf("\n����������:");
		}while(!input(&key)||key<0||key>6);
		switch(key){
			case 0:{
				system("cls");	
				if(InitList_DuL(&L)){
					printf("\n��������ɹ���\n");
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
				if(!input(&position)){
					break;
				}
				DuLinkedList p =FindNode(L,position);
				printf("\n������ڵ����ݣ�"); 
				if(!input(&content)){
					break;
				}
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
				if(!input(&position)){
					break;
				}
				DuLinkedList p =FindNode(L,position);
				printf("\n������ڵ����ݣ�"); 
				if(!input(&content)){
					break;
				}
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
            	if(!input(&position)){
					break;
				}
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
