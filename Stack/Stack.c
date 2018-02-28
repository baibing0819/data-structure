#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********�ļ�˵������ջ�Ļ������� 
***********���ߣ�baibing
***********ʱ�䣺2017.12.13	*********/

#define Max 3

typedef struct
{
	int buf[Max];
	int top;
}stack_t;

/*1�������ն���*/
stack_t *create_empty_stack()
{
	stack_t *q;
	q = (stack_t *)malloc(sizeof(stack_t));
	
	q->top = -1;
	return q;
}

/*2���ж϶����Ƿ�Ϊ��*/
int is_empty_stack(stack_t *q)
{
	return q->top == -1;
} 

/*3���ж϶����Ƿ�����:����ֻ��һ���洢�ռ�ʱΪ��*/
int is_full_stack(stack_t *q)
{
	return q->top == Max-1;/*ע������Խ��*/
} 

/*4����ջ*/
void push_stack(stack_t *q,int value)
{
	q->top += 1; 
	q->buf[q->top] = value;
	printf("%d",q->buf[q->top]);
}

/*5������*/
int pop_stack(stack_t *q)
{
	int temp;
		
	temp = q->buf[q->top];
	printf("%d",q->buf[q->top]);
	q->top -= 1;
	
	return temp;
}

int main()
{
	static int i = 7;
	int j = 2;
	stack_t *q;
	
	q = create_empty_stack();
	
	while(j--)
	{
		while(!is_full_stack(q))
		{
			push_stack(q,i);
			i++;	
		}	
		while(!is_empty_stack(q))
		{
			pop_stack(q);	
		}
		putchar('\n');
	}
}
