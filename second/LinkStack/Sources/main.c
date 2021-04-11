#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "menu.h"


int main(void) {
	LinkStack s;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': {
				count++;
				system("cls");
				if (initLStack(&s))
				printf("��ʼ���ɹ���\n");
				if (!initLStack(&s))
				printf("��ʼ��ʧ�ܣ�\n");
				system("pause");
				system("cls"); 
				break;
			}
			
			case '2': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				printf("����������:");
				if (!(scanf("%d", &data))) {
				    printf("�Ƿ����룡\n");
				    printf("��ջʧ�ܣ�\n");
				    fflush(stdin);// ������뻺�����Ĵ�������
				    system("pause");
				    system("cls");
				    break;
				}
				if(pushLStack(&s, data))
				printf("��ջ�ɹ���\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '3': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				if (popLStack(&s, &data)) {
					printf("��ջ�ɹ���\n");
					printf("ջ������Ϊ��%d\n",data);
				}
				else {
					printf("��ջʧ�ܣ�\n");
					printf("ջΪ��ջ��\n"); 
			    }
				system("pause");
				system("cls"); 
				break;
			}
			
			case '4': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				ElemType data;
				if (getTopLStack(&s, &data))
				printf("ջ������Ϊ��%d\n", data);
				if (!(getTopLStack(&s, &data)))
				printf("ջΪ��ջ��\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '5': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				if (!(clearLStack(&s)))
				printf("��ʱ��Ϊ��ջ��\n");
				if (clearLStack(&s))
				printf("��ճɹ���\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				int length;
				if(!(LStackLength(&s, &length)))
				printf("��ʱΪ��ջ��\n");
				if(LStackLength(&s, &length))
				printf("��ʱջ�ĳ���Ϊ��%d\n", length);
				system("pause");
				system("cls");
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				if (isEmptyLStack(&s)) 
				printf("�ǿ�ջ��\n");
				if(!(isEmptyLStack(&s))) 
				printf("���ǿ�ջ��\n");
				system("pause");
				system("cls");
				break;
			}
			
			case '0': {
				if (!count) {
					system("cls");
					printf("���ȳ�ʼ��ջ��\n");
					system("pause");
					system("cls");
					break;
				}
				if (destroyLStack(&s))
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
