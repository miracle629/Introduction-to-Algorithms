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

	temp = arr[left]; //temp中存的就是基准数 
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右边开始找 
		while (arr[j] >= temp && i<j)
			j--;
		//再找右边的
		printf("%d", j);
		while (arr[i] <= temp && i<j)
			i++;
		//交换两个数在数组中的位置
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
	//最终将基准数归位 
	arr[left] = arr[i];
	arr[i] = temp;

	quick_sort(arr,left, i - 1,len);//继续处理左边的，这里是一个递归的过程 
	quick_sort(arr,i + 1, right,len);//继续处理右边的 ，这里是一个递归的过程 
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