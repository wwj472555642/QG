#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#include "menu.h"


<<<<<<< HEAD
=======
int size;
>>>>>>> d9faf681d231405c6aafd7e1436ba74aea48a39b
int main(void) {
	SqStack s;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': {
				count++;
				system("cls");
				printf("������ջ�Ĵ�С:");
				if (scanf("%d", &size)) {
					if (initStack(&s, size))
				    printf("��ʼ���ɹ���\n");
				}
				else
				printf("����Ƿ��ַ�����ʼ��ʧ�ܣ�\n");
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
				if (!s.size && s.top != -1) 
				printf("��ջʧ�ܣ��Ѿ���ջ��\n");
				if(pushStack(&s, data))
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
				if (popStack(&s, &data)) {
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
				if (getTopStack(&s, &data))
				printf("ջ������Ϊ��%d\n", data);
				if (!(getTopStack(&s, &data)))
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
				if (isEmptyStack(&s))
				printf("��ʱ��Ϊ��ջ��\n");
				if (clearStack(&s))
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
				if(!(stackLength(&s, &length)))
				printf("��ʱΪ��ջ��\n");
				if(stackLength(&s, &length))
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
				if (isEmptyStack(&s)) 
				printf("�ǿ�ջ��\n");
				if(!(isEmptyStack(&s))) 
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
				if (destroyStack(&s))
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
}
