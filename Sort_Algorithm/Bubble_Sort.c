#include<stdio.h>

void swap(float * a, float * b)
{
	float temp = *b;
	*b = *a;
	*a = temp;
}

void bubble_sort_1(float arr[],int len)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < len-1;i++)
	{
		for (j = 0;j < len-1-i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}	
		}
	}
}

void bubble_sort_2(float arr[], int len)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < len - 1;i++)
	{
		for (j = len - 2;j >= i;j--)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void bin_bubble_sort(float arr[], int len)
{
	int low = 0;
	int high = len - 1;
	int flag;
	int i;
	while (low < high)
	{
		flag = 0;
		for (i = low;i < high;i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
		high--;
		for (i = high;i > low;i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(&arr[i], &arr[i - 1]);
			}
		}
	}
}

int main()
{
	float arr[] = { 5,7,9,0,7.8,14,98,57,88,42.6,77,24,55,798,34,64,73,73 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort_1(arr, len);
	//bubble_sort_2(arr, len);
	bin_bubble_sort(arr, len);
	int i;
	for (i = 0;i < len;i++)
	{
		printf("%7.2f,", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}