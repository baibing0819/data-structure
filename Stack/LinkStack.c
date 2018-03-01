#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********�ļ�˵������ʽջ�Ļ������� 
***********���ߣ�baibing
***********ʱ�䣺2017.12.13	*********/

#define Max 3
/*1�����������ṹ�壺
	����ջ�ṹ��ͽ��*/ 
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

typedef struct
{
	int n;/*��ʾջ����ЧԪ�صĸ���*/
	LinkNode *top;/*����ջ�е�һ����Ч���ĵ�ַ*/ 
}LinkStack;

/*1����������ʽջ*/
LinkStack *create_empty_linkstack()
{
	LinkStack *s = NULL;
	s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = (LinkNode *)malloc(sizeof(LinkNode));/*����һ��ע��ҲҪ��������ռ�
												��ɲ���Ұָ�룬�ǳ�����*/
	
	s->n = 0;
	s->top->next = NULL;
	return s;
}

/*2���ж���ʽջ�Ƿ�Ϊ��*/
int is_empty_linkstack(LinkStack *s)
{
	return s->top->next == NULL; 
}

/*3����ջ�������������ͷ�巨����ջ����������ͷ���*/
void push_data_linkstack(LinkStack *s,int data)
{		
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	temp->next = s->top->next;
	s->top->next = temp;
	s->n++;/*�൱��ջ��λ�õı仯*/
}

/*4����ջ�������ڵ�����ɾ�����Ĳ���*/ 
LinkNode* pop_data_linkstack(LinkStack *s)
{
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp = s->top->next;
	
	if((s->top->next == NULL) || (s->top == NULL))
		return;
		
	s->top->next = s->top->next->next;
	s->n--;
	
	return temp;
}

/*5�����ջ��Ԫ�ص�ֵ*/
int get_top_linkstack(LinkStack *s)
{
	if(s->top->next == NULL)
		return;
	
	printf("\nstack->top = %d\n",s->top->next->data);
	return s->top->next->data;
}

/*6����ӡ�������ݣ�����ÿ����㲢������ǵ�������*/
void printf_LinkStack(LinkStack *s)
{
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if((s->top->next == NULL) || (s->top == NULL))
		return;
		
	temp = s->top->next;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);	
		temp = temp->next;
	}
	
	printf("\n\n");
}

int main()
{
	int i = 0;
	LinkStack *s = NULL;
	LinkNode *p = NULL;
	LinkNode *del = NULL;
	
	p = (LinkNode *)malloc(sizeof(LinkNode));
	del = (LinkNode *)malloc(sizeof(LinkNode));
	
	s = create_empty_linkstack();
	
	for(i = 0;i<5;i++)
	{
		push_data_linkstack(s,i);
	}
	printf_LinkStack(s);
	
	for(i=0;i<3;i++)
	{
		p = pop_data_linkstack(s);
		printf("%d\n",p->data);
		del = p;
		free(del);	
	}
	
	get_top_linkstack(s);
}
