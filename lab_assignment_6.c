#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//code here
	//write a recursive binary search algorithim
	//start with both high and low find the midpoint
	//if the value is lower then the new midpoint set 
	// the new max to the midpoint 
	//if higher do the opposite
	//we can assume the array is sorted?
	int mid;
	if(low <= high) {
		mid = (low + high) / 2;
		if( mid == value) {
			return mid;
		} else if (mid > high) {
			high = mid;
			search(numbers, low, high, value);
		} else if (low > mid) {
			low = mid;
			search(numbers, low, high, value);
		}
	}
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}