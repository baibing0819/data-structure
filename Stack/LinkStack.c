#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********�ļ�˵������ʽջ�Ļ������� 
***********���ߣ�baibing
***********ʱ�䣺2017.12.13	*********/

#define Max 3
/*1�����������ṹ�壺
	�������ݺ�ָ����һ������ָ��*/ 
/*�����ṹ��*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode

typedef struct
{
	int m;/*��ʾջ����ЧԪ�صĸ���*/
	LinkNode *top;/*����ջ�е�һ����Ч���ĵ�ַ*/ 
}LinkStack;

/*1����������ʽջ*/
LinkStack *create_empty_linkstack()
{
	LinkStack *s;
	s = (LinkStack *)malloc(sizeof(LinkStack));
	
	s->n = 0;
	s->top = NULL;
	return s;
}

/*2���ж���ʽջ�Ƿ�Ϊ��*/
int is_empty_linkstack()
{
	return s->top == NULL; 
}

/*3����ջ�������������ͷ�巨*/
void push_data_linkstack(LinkStack *s,int data)
{
	LinkNode *temp;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	temp->next = NULL;
	s->top->next = temp;
	s->n++;
}

/*4����ջ*/ 
DataType pop_data_linkstack(LinkStack *s)
{
	s->top = s->top->next->next;
	s->n--;
}

/*5�����ջ��Ԫ�ص�ֵ*/
DataType get_top_linkstack(LinkStack *s)
{
	
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
