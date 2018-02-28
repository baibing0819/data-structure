#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********�ļ�˵��������ѭ������Ļ������� 
***********���ߣ�baibing
***********ʱ�䣺2018.2.23	*********/ 

/*1�����������ṹ�壺
	�������ݺ�ָ����һ������ָ��*/ 
/*�����ṹ��*/
typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

/*2������������ͷ��β
	����ͷ��㣬ָ����ָ���Լ�����ʱû������*/
LinkNode *create_LinkNode()
{
	LinkNode *head = NULL;
	
	head = (LinkNode*)malloc(sizeof(LinkNode));
	
	if(head == NULL)
	{
		printf("malloc failed!\n");
		return;
	}
	head->next = head;/*�뵥����ͬ��*/
	
	return head;
}

/*3��ͷ�巨��ÿ�β������ݶ���ͷ����ͷ����ĵ�һ�����
	֮��������ݣ�Ҳ������ͷ����ָ����ָ���²���Ľ�㣬
	�²���Ľ��ָ����ָ��ͷ���ԭ��ָ��Ľ�㣬����β���
	ָ��ͷ��㣬��ʱ���²���Ľ���Ϊͷ���֮��ĵ�һ�����*/ 
void insert_to_head_data(LinkNode *head,int data)
{
	LinkNode *temp = NULL;
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	if(temp == NULL)
	{
		printf("malloc failed!\n");
		return;	
	}
	
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

/*4����ӡ�������ݣ�����ÿ����㲢������ǵ�������*/
void printf_LinkList(LinkNode *head)
{
	LinkNode *temp = NULL;
	
	if(head == NULL || head->next == head)
	{
		printf("LinkList is NULL!\n\n");	
	}
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp = head->next;
	while(temp != head)/*�뵥����ͬ��*/
	{
		printf("%d\n",temp->data);
	//	printf("%d\n\n",temp->next);	
		temp = temp->next;
	}
	
	printf("\n\n");
}

/*5��β�巨�������ҵ���������һ����㣬Ȼ����
	���һ������ָ����ָ���²���Ľ�㣬�Ӷ��½��ָ��head*/ 
void insert_to_trail(LinkNode *head,int data)
{
	LinkNode *temp = NULL;
	LinkNode *temp1 = NULL;
	
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp1 = (LinkNode*)malloc(sizeof(LinkNode));
	if((temp == NULL)||(temp1 == NULL))
	{
		printf("malloc failed!\n");
		return;	
	}
	temp1 = head;
	
	while(temp1->next != head)/*�뵥����ͬ��*/
	{
		temp1 = temp1->next;	
	}
	
	temp1->next = temp;
	temp->data = data;
	temp->next = head;/*�뵥����ͬ��*/
}

/*6������������ݣ��������������������ǰ�ǿս����бȽϣ��������ݱȽ������
	Сʱ���Ͳ��뵱ǰ���֮ǰ*/
void insert_order_LinkList(LinkNode *head,int data)
{
	LinkNode *temp;
	LinkNode *Cur;
	LinkNode *Pre;

	Cur = (LinkNode*)malloc(sizeof(LinkNode));
	Pre = (LinkNode*)malloc(sizeof(LinkNode));/*����ǰ�̽����Ϊ�˷����������ͷ���͵�һ�����֮��*/
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp->data = data;
	Pre = head;
	Cur = Pre->next;
	
	while((Cur != head)&&(temp->data > Cur->data))/*�뵥����ͬ��*/
	{
		Pre = Pre->next;
		Cur = Cur->next;
	}
	
	temp->next = Cur;
	Pre->next = temp;
	printf_LinkList(head);
}

/*7��ɾ��һ������: ����Ҫɾ���������������еĽ����бȽϣ����������ͬ����ɾ��
	�ý������ݣ�Ҳ�����øý���ǰһ�����ָ��ý��ĺ�һ����㣩���������
	�Ƚϲ�ͬ��������Ƽ����Ƚϣ�ֱ������β��
	ע�⣺Ҫ��ɾ����Ľ���ͷţ���ֹ�ڴ�й¶*/
void delete_data_LinkList(LinkNode *head,int data)
{
	LinkNode *front;
	LinkNode *rear;
	
	front = (LinkNode*)malloc(sizeof(LinkNode));
	front = head;
	rear = (LinkNode*)malloc(sizeof(LinkNode));
	rear = head->next;
	
	if(head->next == head)/*�뵥����ͬ��*/
	{
		return;	
	}
	
	while(front->next != head)/*�뵥����ͬ��*/
	{
		if(rear->data != data)
		{
			front = front->next;
			rear = rear->next;	
		}
		else
		{
			front->next = rear->next;
			free(rear);
			break;
		}		
	}
	
	printf_LinkList(head);
}

/*8��ɾ��������ͬ�����ݣ�ѭ��������ǰ������������������������Ƿ�
	��ͬ�������ͬ����ɾ�����߿�ǰ�Ľ�㡣��������������ǰ��㣬ֱ��
	��������ϡ�*/
void delete_same_LinkList(LinkNode *head)
{
	LinkNode *front;
	LinkNode *rear;
	LinkNode *temp;
	
	
	front = (LinkNode*)malloc(sizeof(LinkNode));
	front = head->next;
	rear = (LinkNode*)malloc(sizeof(LinkNode));
	rear = front->next;
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp = head;
	
	while((rear != head)||(front !=head))/*�뵥����ͬ��*/
	{
		if(front->data == rear->data)
		{
			temp->next = front->next;/*ɾ����ǰ�������ǿ����һ������ֹ�ҵ���ͬ��㲢ɾ������ģ�Ȼ�����ֻ
										����֮��ĵ��º�����������ͬ�Ľ�㣬���޷��жϳ���*/
			front = front->next;
			rear = front->next;/*�����������Ƚ�*/
			if(rear == head)/*�뵥����ͬ��*/
				return;
		}
		else
		{
			rear = rear->next;/*�����ͬ������һ������뵱ǰ���Ƚ�*/
			if(rear == head)/*�뵥����ͬ��*/
			{
				temp = front;/*������û����ͬ��㣬��(����)��һ����ǰ��㣬����ѭ�������Ƚ�*/
				front = front->next;
				if(front == head)
					return;
				rear = front->next;	
				if(rear == head)
					return;	/*��ʾ�ѱ��������һ����㲢û����ͬ����
							��������������if�жϳ����൱��
							if(data == (void)*)*/
			}	
		}
	}
}

/*9����������е����ݣ�����ͷ��㣬���������нڵ�ɾ���ͷ�*/
void clear_LinkList(LinkNode *head)
{
	LinkNode *temp;
	LinkNode *temp1;
	
	if(head == NULL)
		return;
		
	temp = head->next;
	while(temp != head)
	{
		temp1 = temp->next;
		free(temp);
		temp = temp1;		
	}
	
	head->next = head;/*�뵥����ͬ��*/
	printf_LinkList(head);
}


/*10��ͷ�巨���������½���������Ϊ�գ�ԭ������δ�������ɾ����������������������
	��ͷ(ͷ�巨)��ʹ����Ϊ��������*/
void head_converse_LinkList(LinkNode *head)
{	
	LinkNode *Temp = NULL;
	LinkNode *New_P = NULL;
	
	Temp = (LinkNode*)malloc(sizeof(LinkNode));
	Temp = head->next;
	head->next = head;
	New_P = (LinkNode*)malloc(sizeof(LinkNode));
	
	while(Temp != head)/*�뵥����ͬ��*/
	{
		New_P = Temp;
		Temp = Temp->next;
		
		New_P->next = head->next;
		head->next = New_P;	
	}
	
	printf_LinkList(head);
}

LinkNode* rec_converse_LinkList(LinkNode *head,LinkNode *s_head)
{	
	/*�ݹ���ֹ����������Ϊ�ջ�������������һ�����
		�ݹ���ֹ�����������һ�������Ϊ�µ�ͷ��㣬���顱ʱ����
		�µ�ͷ��㣬ʵ������*/
	LinkNode *New_Head;
	
	New_Head = (LinkNode*)malloc(sizeof(LinkNode));
	
	if(head->next == s_head)
		return head;
		
	New_Head = rec_converse_LinkList(head->next,s_head);/*�ݹ�*/ 
	
	/*����*/
	head->next->next = head;
	head->next = s_head;/*�뵥����ͬ��*/
    
    return New_Head;
}

/*11���ݹ鷨���õ��������Ƚ���ǰ������ͷ��������������õݹ麯�����ҳ�ʣ����������
	һ����㲢������Ϊ�µ�ͷ��㣬����ʣ������������󣬽�֮ǰ�����ͷ��������ͷ���
	֮ǰ���γ�����������*/
void rec_converse(LinkNode *head)
{
	LinkNode *s_head; 
	s_head = (LinkNode*)malloc(sizeof(LinkNode));
	
	s_head = head;	/*����ԭʼͷ���*/
	head = head->next;
	
	head = rec_converse_LinkList(head,s_head);
	s_head->next = head; /*��ͷ����������������*/ 
	printf_LinkList(s_head);	
}

/*12����ȡ������*/
int GetListLength(LinkNode *head)
{
	int num = 0;
	LinkNode *temp;
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	
	temp = head->next;
	while(temp != head)/*�뵥����ͬ��*/
	{
		temp = temp->next;
		num++;
	}
	
	return num;/*������ͷ���*/
} 

/*13���������򣺲���ð�����򷽷�*/ 
void sort_linklist(LinkNode *head)
{
	int num=0,i=0,j=0;
	int temp_data;
	LinkNode *Front;
	LinkNode *Rear;
	LinkNode *s_head;
	
	Front = (LinkNode*)malloc(sizeof(LinkNode));
	Rear = (LinkNode*)malloc(sizeof(LinkNode));
	s_head = (LinkNode*)malloc(sizeof(LinkNode));
	
	s_head = head;/*����ͷ���*/
	num = GetListLength(head);
	
	for(i=0;i<num-1;i++)
	{
		Front = s_head->next;
		Rear = Front->next;	
		
		for(j=0;j<num-i-1;j++)
		{
			if(Front->data > Rear->data)
			{
				temp_data = Rear->data;
				Rear->data = Front->data;
				Front->data = temp_data;	
			}	
			Rear = Rear->next;
			Front = Front->next;
		}	
	}
	
	printf("Sort Test:\n");
	printf_LinkList(head);
}

 
int main()
{
	LinkNode *head;
	int i;
	
	head = create_LinkNode();
	for(i=1;i<6;i++)
	{
		insert_to_head_data(head,i);		
	}
	printf_LinkList(head);

	for(i=6;i<11;i++)
	{
		insert_to_trail(head,i);		
	}
	printf_LinkList(head);

	insert_to_trail(head,7);
	insert_order_LinkList(head,7);
	delete_data_LinkList(head,6); 
	delete_same_LinkList(head);
	printf_LinkList(head);
	head_converse_LinkList(head);
	rec_converse(head);
	sort_linklist(head);
	clear_LinkList(head);
	
	return 0;
}

