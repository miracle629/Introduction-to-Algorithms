#include<stdio.h>

void swap(float * a, float * b)
{
	float temp = *b;
	*b = *a;
	*a = temp;
}

void quick_sort(float arr[],int left, int right,int len)
{
	int i, j, t, temp;
	int num;
	if (left>right)
		return;

	temp = arr[left]; //temp�д�ľ��ǻ�׼�� 
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ�� 
		while (arr[j] >= temp && i<j)
			j--;
		//�����ұߵ�
		printf("%d", j);
		while (arr[i] <= temp && i<j)
			i++;
		//�����������������е�λ��
		printf("%d", i);
		if (i<j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		for (num = 0;num < len;num++)
		{
			printf("%7.2f,", arr[num]);
		}
		printf("\n");
	}
	//���ս���׼����λ 
	arr[left] = arr[i];
	arr[i] = temp;

	quick_sort(arr,left, i - 1,len);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quick_sort(arr,i + 1, right,len);//���������ұߵ� ��������һ���ݹ�Ĺ��� 
}

int main()
{
	float arr[] = { 6,1,2,7,9,11,4,5,10,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr,0, len-1,len);
	int i;
	for (i = 0;i < len;i++)
	{
		printf("%7.2f,", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}