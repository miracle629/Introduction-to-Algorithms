#include<stdio.h>

int main()
{
	float arr[] = { 3,6,67,6,86,40.5,57,33,43,98,75 };
	int i = 0;
	int j = 0;
	int minIndex = 0;
	float temp = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	for(i=0;i<length;i++)
	{
		minIndex = i;
		for(j=i+1;j<length;j++)
		{
			if(arr[j]<=arr[minIndex])
			{
				minIndex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	for(i=0;i<length;i++)
	{
		printf("%6.2f,",arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}