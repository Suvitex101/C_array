#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
int main (void)
{
	int *numbers, *evenNo, *oddNo;
	int i, evidx = 0, oddidx = 0, size;

	printf("Enter size of array: ");
	scanf("%d",&size);

	numbers = malloc(sizeof(int) * size);
	evenNo = malloc(sizeof(int) * size);
	oddNo = malloc(sizeof(int) * size);
	if (numbers == NULL || evenNo == NULL || oddNo == NULL)
		return (-1);
	
	printf("Enter numbers to be stored in the array\n");
	for (i = 0; i < size; i++)
	{
		printf("Enter number: ");
		scanf("%d",&numbers[i]);
		if (numbers[i] % 2 == 0)
		{
			evenNo[evidx] = numbers[i];
			evidx++;
		} else
		{
			oddNo[oddidx] = numbers[i];
			oddidx++;
		}
	}
	printf("The odd numbers stored in the array are: \n");
	for (i = 0; i < oddidx; i++)
	{
		printf("%d\n",oddNo[i]);
	}
	printf("The even numbers stored in the array are: \n");
	for (i = 0; i < evidx; i++)
	{
		printf("%d\n",evenNo[i]);
	}
}