#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********�ļ�˵������ʽ���еĻ������� 
***********���ߣ�baibing
***********ʱ�䣺2017.12.13	*********/

#define Max 3

/*�����ṹ��*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

typedef struct 
{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

/*1�������ն���*/
LinkQueue* create_empty_linkqueue()
{
	LinkQueue *q = NULL;
	q = (LinkQueue *)malloc(sizeof(LinkQueue));
	q->front = (LinkNode *)malloc(sizeof(LinkNode));
	q->rear = (LinkNode *)malloc(sizeof(LinkNode));
	
	q->front = q->rear = NULL;
	return q;
}

/*2���ж϶����Ƿ�Ϊ��*/
int is_empty_queue(LinkQueue *q)
{
	return q->front == NULL;
}  

/*3�����*/
void enqueue(LinkQueue *q,int data)
{		
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp->data = data;
	if(is_empty_queue(q))
	{
		q->front = temp;/*��һ�ν����ݸ���ͷ*/
		q->rear = temp;	
	}
	else
	{
		q->rear->next = temp;
		q->rear = q->rear->next;
	}
}

/*4������:ɾ��ͷ��㣬ʹ��һ������Ϊ�µ�ͷ���*/
int dequeue(LinkQueue *q)
{
	LinkNode *temp = NULL;
	int value;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	if(q->front == NULL)
		return;
		
	temp = q->front;
	value = temp->data;	
		
	q->front = q->front->next;
	free(temp);
	
	return value;
}

/*5����ӡ����*/
void printf_LinkQueue(LinkQueue *q)
{
	printf("\n��ǰ�������ݣ�\n");
	LinkNode *temp = NULL;
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	
	temp = q->front;
	while(temp != q->rear)
	{
		printf("%d\n",temp->data);
		temp = temp->next;	
	}
	printf("%d\n",temp->data);/*q->rearҲ��ֵ*/
	printf("\n");
}

int main()
{
	int i = 0;
	int temp;
	LinkQueue *q;
	
	q = create_empty_linkqueue();

	for(i=0;i<5;i++)
	{
		enqueue(q,i);
	} 
	printf_LinkQueue(q);
	
	for(i=0;i<3;i++)
	{
		temp = dequeue(q);
		printf("%d\n",temp);
	}
	temp = dequeue(q);
	printf("%d\n",temp);
	printf_LinkQueue(q);
	for(i=0;i<5;i++)
	{
		enqueue(q,i);
	} 
	printf_LinkQueue(q);
	for(i=0;i<3;i++)
	{
		temp = dequeue(q);
		printf("%d\n",temp);
	}
	printf_LinkQueue(q);
}
