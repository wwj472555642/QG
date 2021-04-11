#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "menu.h"


int main(void) {
	AQueue Q;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': { // ��ʼ������ 
				count++;
				system("cls");
				InitAQueue(&Q);
				printf("��ʼ���ɹ���\n");
				system("pause");
				system("cls"); 
				break;
			}
			
			case '2': {// ��� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				} 
				printf("������������������(1����������2����С����3�����ַ�)\n");
				scanf("%d", &type);
				switch(type) { // ��ͬ�������������ֵͬ������type����� 
					case 1:{
						int data;
						printf("���������ݣ�");
						int judge = scanf("%d", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							(EnAQueue(&Q, &data));
							printf("���ӳɹ���\n");	
						}
						break;
					}
					
					case 2:{
						double data;
						printf("���������ݣ�");
						int judge = scanf("%lf", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							(EnAQueue(&Q, &data));
							printf("���ӳɹ���\n");	
						}						
						break;
					}
					
					case 3:{
						char* data;
						int judge = scanf("%s", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							EnAQueue(&Q, &data);
							printf("���ӳɹ���\n");
							while (getchar() != '\n');	
						}
						break;
					}		
					
					default:{
						printf("�������ʹ���\n");
						while(getchar() != '\n');
						break;
					}
				}
				system("pause");
				system("cls");
				break;
				
			}
			
			case '3': {// ���� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (DeAQueue(&Q)) 
					printf("���ӳɹ���\n");
				else {
					printf("����ʧ�ܣ�\n");
					printf("����Ϊ�գ�\n"); 
			    }
				system("pause");
				system("cls"); 
				break;
			}
			
			case '4': {// �����ͷ���� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyAQueue(&Q)) {
					printf("����Ϊ�գ�\n");
					system("pause");
					system("cls");					
					break;
				}
				void* data; //����ͷ������������� 
				if (datatype[Q.front] == 1) {
					data = (int*)malloc(sizeof(int));
					if (GetHeadAQueue(&Q, data))
					printf("��ͷ����Ϊ��%d\n", *(int*)data);
				} 
				if (datatype[Q.front] == 2) {
					data = (double*)malloc(sizeof(double));
					if (GetHeadAQueue(&Q, data))
					printf("��ͷ����Ϊ��%.2lf\n", *(double*)data);					
				}
				if (datatype[Q.front] == 3) {
					data = (char*)malloc(sizeof(char));
					if (GetHeadAQueue(&Q, data))
					printf("��ͷ����Ϊ��%c\n", *(char*)data);					
				}

				system("pause");
				system("cls");
				break;
			}
			
			case '5': {// ��ն��� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyAQueue(&Q))
				printf("��ʱ��Ϊ�ն��У�\n");
				else {
					ClearAQueue(&Q);
					printf("��ճɹ���\n");
				}
				system("pause");
				system("cls");
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				int length;
				length = LengthAQueue(&Q);
				printf("��ʱ���еĳ���Ϊ��%d\n", length);
				system("pause");
				system("cls");
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsEmptyAQueue(&Q)) 
				printf("�ǿն��У�\n");
				if(!(IsEmptyAQueue(&Q))) 
				printf("���ǿն��У�\n");
				system("pause");
				system("cls");
				break;
			}

			case '8': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (IsFullAQueue(&Q))
				printf("��ǰ����������\n");
				else
				printf("��ǰ����δ����\n");
				system("pause");
				system("cls");
				break;							
			}
			
			case '9': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				if (TraverseAQueue(&Q, APrint));
				else 
				printf("��ʱ����Ϊ�գ�\n");
				system("pause");
				system("cls");
				break;
			} 
			
			case '0': {
				if (!count) {
					system("cls");
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					system("cls");
					break;
				}
				DestoryAQueue(&Q);
				printf("���ٳɹ���\n");
				system("pause"); 
				return 0; 
				break;
			}
			
			default: {
				printf("�������˷Ƿ��ַ������������룡\n");
				system("pause");
				system("cls"); 
				break;
			}
		}
		 
	}	
	return 0;
}
