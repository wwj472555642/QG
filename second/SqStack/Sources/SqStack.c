#include <stdio.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes) {
	s->size = sizes;
	s->top = -1;// ��û��������ջʱtopΪ-1��ÿ��ջһ��+1����һֱָ��ջ�� 
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));// ����һ���ռ䣬������ 
	return SUCCESS; 
}


Status isEmptyStack(SqStack *s) {
	if (s->top == -1)
	return SUCCESS;
	else
	return ERROR;
}


Status getTopStack(SqStack *s,ElemType *e) {
	if (isEmptyStack(s))
	return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}


Status clearStack(SqStack *s) {
	if (isEmptyStack(s))
	return ERROR;
<<<<<<< HEAD
	s->size = s->top + s->size + 1;// ��ջ�Ŀռ�ָ������ 
=======
	s->size = size;// ��ջ�Ŀռ�ָ������ 
>>>>>>> d9faf681d231405c6aafd7e1436ba74aea48a39b
	s->top = -1;
	return SUCCESS;
}


Status destroyStack(SqStack *s) {
	free(s->elem);// �ͷſռ䣬����ջ 
	return SUCCESS;
}


Status stackLength(SqStack *s,int *length) {
	if (isEmptyStack(s))
	return ERROR;
	*length = s->top+1;
	return SUCCESS;
}


Status pushStack(SqStack *s,ElemType data) {
	if (!s->size)
	return ERROR;
	s->top++;// ջ��ָ��ָ����һ��λ�� 
	s->elem[s->top] = data;// ջ����ֵ 
	s->size--;// ջ�Ŀռ�-1 
	return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data) {
	if (isEmptyStack(s))
	return ERROR;
	*data = s->elem[s->top];// ȡ��ջ��Ԫ�� 
	s->top--;// ջ��ָ������ 
	s->size++;// ջ�Ŀռ�+1 
	return SUCCESS;
}
