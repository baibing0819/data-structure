#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********�ļ�˵�����������Ļ������� 
***********���ߣ�baibing
***********ʱ�䣺2017.3.5	*********/ 

/*1�����������ṹ�壺
	�����洢�����ݺ�ָ�����Һ��ӵ�ָ�롣�������������������Ĳ�α���*/ 
typedef struct bnode
{
	char data;
	struct bnode *L_Child;
	struct bnode *R_Child;
}BTree_T;

typedef struct node
{
	struct bnode *t_data;
	struct node *next; 
}LinkNode;

typedef struct qnode
{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

/*2������ռ�:���½�������������ռ�*/
BTree_T* malloc_btree(BTree_T *root,char data)
{
	root = (BTree_T *)malloc(sizeof(BTree_T));
	
	if(root == NULL)
	{
		printf("malloc failed!\n");
		return;	
	}
	
	root->L_Child = NULL;
	root->R_Child = NULL;
	root->data = data;
	
	return root; 
} 

/*3��������ȫ�����������õݹ�ķ������������ڵ�,Ȼ�������Һ���
	����˵����a[]:���������  num:��ǰ�������  n�����������(2^z-1)
	�������ӽ�����㣺2*num <= n���Һ��ӽ�����㣺2*num+1<=n*/
BTree_T *create_full_binary_tree(char a[],int num,int n)
{
	BTree_T *root;
	
	root = malloc_btree(root,a[num]);
	
	if(2*num <= n)
	{
		root->L_Child = (BTree_T*)create_full_binary_tree(a,2*num,n);
	}
	
	if(2*num+1 <= n)
	{
		root->R_Child = (BTree_T*)create_full_binary_tree(a,2*num+1,n);
	}
	
	return root;
}

/*4���������������,�õݹ鰴�����ҵ�˳�����α���������*/
void preorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	printf("%c",root->data);
	preorder_traversal(root->L_Child);
	preorder_traversal(root->R_Child);
}

/*5���������������,�õݹ鰴����ҵ�˳�����α���������*/
void inorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	inorder_traversal(root->L_Child);
	printf("%c",root->data);
	inorder_traversal(root->R_Child);
}

/*6���������������,�õݹ鰴���Ҹ���˳�����α���������*/
void postorder_traversal(BTree_T *root)
{
	if(root == NULL)
		return;
	
	postorder_traversal(root->L_Child);
	postorder_traversal(root->R_Child);
	printf("%c",root->data);
}

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
void enqueue(LinkQueue *q,BTree_T *t)
{		
	LinkNode *temp = NULL;
	
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp->t_data = (BTree_T *)malloc(sizeof(BTree_T));
	
	temp->t_data = t;
	temp->next = NULL;/*ע������һ��Ҫ��һ�����ָ��NULL����Ȼ�ᵼ�¶���
					ָ��ָ��Ұ��ַ�������ӳ��ӻ��ң�ָ���ܷɵȽ��*/
	
	if(is_empty_queue(q))
	{
		q->front = temp;/*��һ�ν����ݸ���ͷ*/
		q->rear = temp;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
	}
}

/*4������:ɾ��ͷ��㣬ʹ��һ������Ϊ�µ�ͷ���*/
BTree_T * dequeue(LinkQueue *q)
{
	LinkNode *temp = NULL;
	BTree_T *t = NULL;
	
	temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp->t_data = (BTree_T *)malloc(sizeof(BTree_T));
	t = (BTree_T *)malloc(sizeof(BTree_T));
	
	if(q->front == NULL)
		return;
		
	temp = q->front;
	t = temp->t_data;	
		
	q->front = q->front->next;
	free(temp);
	
	return t;
}

/*7����α���������:����ʹ�������ӣ�Ȼ��ѭ���ж϶����Ƿ�Ϊ�գ���Ϊ�գ�
	��ʼ���ӣ�����ȡ����Ԫ��ָ��Ľ�㣬������������Һ��ӵ�Ԫ�أ�ֱ��
	����Ϊ��*/
void levelorder_traversal(BTree_T *root)
{ 	
	LinkQueue *q;
	BTree_T *t;
	t = (BTree_T *)malloc(sizeof(BTree_T));
	t = root;
	
	q = create_empty_linkqueue();
	enqueue(q,t);
	while(!is_empty_queue(q))
	{
		t = dequeue(q);
		printf("%c",t->data);
	
		if(t->L_Child)
			enqueue(q,t->L_Child);
		if(t->R_Child)
			enqueue(q,t->R_Child);
	}
}

/*8�������˳������ͨ�����������õݹ�ķ������������ڵ�,Ȼ�������Һ���
	����˵����a[]:���������  num:��ǰ�������  n�����������(2^z-1)
	�������ӽ�����㣺2*num <= n���Һ��ӽ�����㣺2*num+1<=n*/
BTree_T *create_binary_tree(char a[],int num,int n)
{
	BTree_T *root;
	
	if(a[num] != ' ')
	{
		root = malloc_btree(root,a[num]);		
	}
	else
	{
		return NULL;
	}
	
	root->L_Child = (BTree_T*)create_full_binary_tree(a,2*num,n);

	root->R_Child = (BTree_T*)create_full_binary_tree(a,2*num+1,n);
	
	return root;
}

/*9����������ͨ�����������õݹ�ķ������������ڵ�,Ȼ�������Һ���
	����˵����a[]:���������  num:��ǰ�������  n�����������(2^z-1)
	�������ӽ�����㣺2*num <= n���Һ��ӽ�����㣺2*num+1<=n*/
void preorder_create_binary_tree(BTree_T *root,char a[],int num)
{
	char ch = a[num++];
		
	if(ch == ';')
	{
		return;	
	}
	
	if(ch !=' ')
	{
		root = (BTree_T*)malloc(sizeof(BTree_T));
		root->data = ch;
		preorder_create_binary_tree(root->L_Child,a,num);
		preorder_create_binary_tree(root->R_Child,a,num);	
	}
	else
	{
		root = NULL;
		num++;
	}
}

int main()
{
	char a[] = {-1,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
	char a1[] = {-1,'A','B','D',' ','C','E','F'};
	char a2[] = {-1,'A','B',' ','C',' ',' ','D','E',' ',' ','F',' ',' ',';'};
	int num = 1;/*���������һ���1��ʼ����*/
	BTree_T *root;
	
	//root = create_full_binary_tree(a,num,sizeof(a)/sizeof(a[0])-1);
	root = create_binary_tree(a1,num,sizeof(a1)/sizeof(a1[0])-1);
	//preorder_create_binary_tree(root,a2,num);
	
	preorder_traversal(root);
	printf("\n\n");
	inorder_traversal(root);
	printf("\n\n");
	postorder_traversal(root);
	printf("\n\n");
	levelorder_traversal(root);
	printf("\n\n");

	return 0;
}
