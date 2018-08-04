#include<stdio.h>

void swap(float * a, float * b)
{
	float temp = *b;
	*b = *a;
	*a = temp;
}

void max_heap(float arr[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
		{
			son++;
		}
		if (arr[dad] > arr[son])
		{
			return;
		}
		else
		{
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
}

void heap_sort(float arr[], int len)
{
	int i;
	for(i = len / 2 - 1;i >= 0;i--)
	{
		max_heap(arr, i, len - 1);
	}
	for (i = len - 1;i > 0;i--)
	{
		swap(&arr[0], &arr[i]);
		max_heap(arr, 0, i - 1);
	}
}

int main()
{
	float arr[] = { 5,7,9,0,7.8,14,98,57,88,42.6,77,24,55,798,34,64,73,73 };
	int len = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, len);
	int i;
	for (i = 0;i < len;i++)
	{
		printf("%7.2f,", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}