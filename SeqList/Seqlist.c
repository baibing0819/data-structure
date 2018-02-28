#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********����˵����˳���Ľ��������������
***********���ߣ�baibing
***********ʱ�䣺2017.12.13	*********/

#define Max 20

typedef struct
{
	int data[Max];
	int n; 
}Seqlist;

/*����˳���*/
Seqlist *Create_Seqlist()
{
	Seqlist *l = NULL;
	
	l = (Seqlist *)malloc(sizeof(Seqlist));
	if(l == NULL)
	{
		printf("malloc Error!\n");	
		return NULL;
	}
	
	memset(l,0,sizeof(Seqlist));/*�˴�����ʼ��������ܷ�*/
	
	return l;
}

/*�ж�˳����Ƿ�����*/
int is_full_Seqlist(Seqlist *l)
{
	return l->n == Max ? 1:0;
}

/*��ʼ����������*/
void insert_data_Seqlist(Seqlist *l,int *a,int length)
{
	int i;
	
	for(i = 0;i<length;i++)
	{
		if((is_full_Seqlist(l))!= 1)
		{
			l->data[i] = a[i];
			l->n ++;/*������Ŀ����*/
		}		
		else
		{
			printf("line is full!\n");
			return;	
		}
	}
}

/*�����ݲ��뵽ָ��λ��*/
void insert_dataToPos_Seqlist(Seqlist *l,int data,int pos)
{
	int i;
	
	if((is_full_Seqlist(l))!= 1)
	{
		for(i = (Max-2);i>-1;i--)
		{
			if(pos == i)
			{
				l->data[i+1] = l->data[i];
				l->data[i] = data;
				l->n++;/*������Ŀ����*/
				return;
			}
			else
			{
				l->data[i+1] = l->data[i];	
			}
		}
	}
}

/*ɾ��ָ��λ�õ�����*/
void delete_PosData_Seqlist(Seqlist *l,int pos)
{
	int i,j;
	
	for(i=0;i<Max;i++)
	{
		if(i == (pos+1))
		{
			for(j=pos;j<Max;j++)
			{
				l->data[j] = l->data[i++];	
			}
			l->n --;
			return;
		}
	}
}

/*ɾ������*/
void delete_data_Seqlist(Seqlist *l,int data)
{
	int i=0,j=0;
	
	for(i=0;i<Max;i++)
	{
		if(l->data[i] != data)
		{
			l->data[j] = l->data[i];
			j++;
		}	
		else
		{
			l->n --;	
		}
	}
}

/*����*/
void sort_Seqlist(Seqlist *l )
{
	int i,j;
	int temp;
	
	for(i=0;i<l->n;i++)
	{
		for(j=0;j<l->n;j++)
		{
			if(l->data[i]<l->data[j])
			{
				temp = l->data[i];
				l->data[i] = l->data[j];
				l->data[j] = temp;
			}	
		}	
	}
}

/*��ӡ����*/
void print_Seqlist(Seqlist *l)
{
	char i;
	
	for(i=0;i<l->n;i++)
	{
		printf("%d",l->data[i]);	
		putchar('\n');
	}
	
	printf("complete!\n\n");
}

int main()
{
	Seqlist *l = NULL;
	int Data[6] = {11,33,22,55,55,44};
	
	l = Create_Seqlist();
	insert_data_Seqlist(l,Data,sizeof(Data)/sizeof(int));
	print_Seqlist(l);
	sort_Seqlist(l);
	print_Seqlist(l);
	
	insert_dataToPos_Seqlist(l,31,3);
	printf("���һ��Ԫ��\n");
	print_Seqlist(l);
	sort_Seqlist(l);
	printf("������\n");
	print_Seqlist(l);
	delete_PosData_Seqlist(l,3);
	printf("ɾ��ָ��λ������\n"); 
	print_Seqlist(l);
	delete_data_Seqlist(l,55);
	printf("ɾ������\n"); 
	print_Seqlist(l);
	
	return 0;
}
