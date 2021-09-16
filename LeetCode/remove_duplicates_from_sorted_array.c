#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	int i=0, j;
	for(j=0; j < numsSize; j++)
	{
		if(nums[j] != nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	printf("Output : %d,",i+1);
	return i+1;
}

int main()
{
	int nums[] = {0,0,1,1,1,2,2,3,3,4}, k;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int i;

	printf("Input: nums = [");
	for(i=0; i<numsSize; i++)
		printf("%d ",nums[i]);	/* printing input array */
	printf("]\n");

	k = removeDuplicates(nums, numsSize);

	printf("nums = [");
	for(i=0; i<k; i++)
		printf("%d ",nums[i]);	/* printing output array */
	printf("]\n");
}
