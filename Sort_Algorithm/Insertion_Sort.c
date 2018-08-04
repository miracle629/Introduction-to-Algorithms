#include<stdio.h>

void swap(float * a, float * b)
{
	float temp = *b;
	*b = *a;
	*a = temp;
}

void print_num(float arr[], int len)
{
	int i;
	for (i = 0;i < len;i++)
	{
		printf("%7.2f,", arr[i]);
	}
	printf("\n");
}


//≤Â»Î≈≈–Ú
//O(n^2)
void insert_sort(float arr[],int len)
{
	int i = 0, j = 0;
	float get;
	for (i = 1;i < len;i++)
	{
		get = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j]>get)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = get;
	}
}

//’€∞Î≤Â»Î≈≈–Ú
//O(n*log2(n))
void binary_insert_sort(float arr[],int len)
{
	int i = 0, j = 0;
	float get;
	int low, high;
	int m;
	for (i = 1;i < len;i++)
	{
		get = arr[i];
		high = i - 1;
		low = 0;
		while (low <= high)
		{
			m = (high + low) / 2;
			if (arr[m] < get)
			{
				low = m + 1;
			}
			else
			{
				high = m - 1;
			}
		}
		for (j = i - 1;j >= low;j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[low] = get;
	}
}

//œ£∂˚≈≈–Ú
//O(n*log2(n))
void shell_sort(float arr[], int len)
{
	int gap = 0;
	while (gap < len)
	{
		gap = 3 * gap + 1;
	}
	int i = 0, j = 0;
	float get;
	while (gap > 0)
	{
		for (i = gap;i < len;i++)
		{
			get = arr[i];
			j = i - gap;
			while (j >= 0 && arr[j]>get)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = get;
		}
		gap = (gap - 1) / 3;
	}	
}

int main()
{
	float arr[] = { 5,7,9,0,7.8,14,98,57,88,42.6,77,24,55,798,34,64,73,73 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//insert_sort(arr, len);
	//binary_insert_sort(arr, len);
	shell_sort(arr, len);
	print_num(arr, len);
	system("pause");
	return 0;
}