/* Given an integer array nums and an integer val, remove all occurences of val in nums in-place. The relative order of
 * the elements may be changed.
 * 
 * Since it is impossible to change the length of the array in some languages, you must instead have the result be
 * placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first
 * k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 *
 * Input: nums = [3,2,2,3], val = 3
 *	Output: nums = [2,2,_,_]
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 16.09.2021
 * Author : Abinash
 */

#include<stdio.h>

int removeElement(int* nums, int numssize, int val)
{
	int i = 0, j = 0;
	while(j < numssize)
	{
		if(nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
		j++;
	}
	printf("Output : %d",i);
	return i;
}

int main()
{
	int nums[] = {3,2,2,3}, val = 3, i,k;	
	int numssize = sizeof(nums) / sizeof(nums[0]);

	printf("Input : nums = [");
	for(i=0; i<numssize; i++)
		printf("%d ",nums[i]);	/* Printing input array */
	printf("]\n");

	k = removeElement(nums, numssize, val);

	printf(" ,nums = [");
	for(i=0; i < k; i++)
		printf("%d ",nums[i]);	 /* Printing after removing the elements */
	printf("]\n"); 
	return 0;
}


