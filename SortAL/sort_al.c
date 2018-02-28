#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********�ļ�˵�����˴������㷨 
***********���ߣ�baibing
***********ʱ�䣺2018.1.29	*********/ 
void printf_array(int *arr,int num);

/*1��ֱ�Ӳ������򣺼�����R0��R1��R2��R3��R4���δ�������� 
	��1���������һ����R0�����������У�ʣ�ಿ��Ϊ����������
	��2������ѡȡδ�������飬�Ӻ���ǰ������ֱ�����뵽�������к��ʵ�λ��*
	ʱ�临�Ӷȣ�O(N^2)	�ռ临�Ӷȣ�O(1)*/
void insert_sort(int *array,int num)
{
	int i,j;
    int temp;
    
	for(i=1;i<num;i++)
	{
		temp = array[i];
		for(j=i;j>0 && array[j-1]>temp;j--) 
		{
			array[j] = array[j-1];
		}		
		array[j] = temp;
	}
	
	printf_array(array,num);	
}

/*2��ѡ������������δ������������ҵ�������С�����ݣ����������ʼλ��
	Ȼ���������ʣ�ಿ��������С�����ݣ�һ�μ�����ʼλ֮��
	ʱ�临�Ӷȣ�O(N^2)		�ռ临�Ӷ�O(1)*/
void select_sort(int *array,int num)
{
	int i=0,j=0,k = 0;
	int temp=0;
		
	for(k=0;k<num;k++)
	{
		for(i=k;i<num;i++)
		{
			if(array[i]>temp)/*�ҵ����ֵ������λ��*/
			{
				temp = array[i];	
				array[i] = array[j];
				array[j] = temp; 
			}
		}		
		j+=1;
		temp = array[j];
	}
	
	printf_array(array,num);
}

/*3��ð�������㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�
	��1)�����������������Ƚϣ����ǰ��Ⱥ�����򽻻��������ݣ�����һ��ѭ�������һ��Ϊ��������
	(2)�ظ���һ������֤��ÿһ�����ݶ����ȽϹ���ֱ��û���κ�һ��������Ҫ�ٱȽ�
	ʱ�临�Ӷȣ�O(N^2)		�ռ临�Ӷ�(1)*/ 
void bubble_sort(int *array,int num)
{
	int i=0,j=0;
	int temp;
	
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}		
		}	
	}
	
	printf_array(array,num);
}

/*4���鲢�������ֺ��壺�ȵݹ��ϲ�
	(1)���Ƚ������������ͨ���ݹ�ķ����ֽ��������������
		�ݹ���ֹ������������������зֽ�ɵ���������Ӽ� 
	(2)Ȼ�������������кϲ���һ���������У��ϲ�ʱ���ֱ�������ָ��ָ�������������е�ͷ��
	�Ƚ�ָ��ָ���Ԫ�ش�С������С��һ��ֱ�ӷŵ��µ��������ɾ��ԭ�����Ԫ�أ�������ƶ�
	ָ�룬ֱ����һ��û��Ԫ�أ���ֱ�Ӱ���һ��ʣ�µ�����ֱ�Ӳ嵽�ϲ�����ĺ��漴��*/
void Merge_Sort(int *array,int *temp,int left,int mid,int right)
{
	int *new_array;
	
	
}	

void Merge_Array(int *array,int left,int *temp,int right)
{ 
	int mid;

	if(left<right)
	{
		mid = (left+right)/2;
		Merge_Array(array,left,temp,mid);/*������*/	
		Merge_Array(array,mid+1,temp,right);/*������*/
		Merge_Sort(array,temp,left,mid,right);/*�ϲ�*/
	}
}

/*��ӡ����*/
void printf_array(int *arr,int num)
{
	int i = 0;
	
	for(i = 0;i<num;i++)
	{
		printf("%d\n",arr[i]);	
	}
	printf("\n\n");
}

//���ж�����������a[first...mid]��a[mid...last]�ϲ���
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //�������
		mergesort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
	}
}

int main()
{
	int num =0;
	int array[5] = {3,8,1,4,6};
	int *temp;
		
	temp = array;
	num = sizeof(array)/sizeof(int); 
	
	//insert_sort(array,num);
	//select_sort(array,num);
	//bubble_sort(array,num);
	//Merge_Array(array,0,temp,4);
	mergesort(array,0,4,temp);
	printf_array(array,num);
	
	return 0;
}
