/* You have given two integer arrays num1, num2, sorted in non-decreasing order, and two integers m and n representing
 * the number of elements in num1 and num2 respectively.
 *
 * Merge num1 and num2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, but instead be stored inside the array num1. To 
 * accomodate this, num1 has a length of m+n, where first m elements denote the elements that should be merged, and the
 * last n elements are set to 0 and should be ignored. num2 has a length of n
 * 
 * Input : nums1 = [1,2,3,0,0,0], m=3, nums2 = [2,5,6], n=3
 * Output : [1,2,2,3,5,6]
 * Explanation : The arrays we are merging are [1,2,3] and [2,5,6]
 *               The resultant of the merge is [1,2,2,3,5,6]
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 16.09.2021
 * Author : Abinash
 */

#include<stdio.h>

void merge(int* nums1, int nums1size, int m, int* nums2, int nums2size, int n)
{
	int i, j, temp;
	
	for(i=m, j=0; i < nums1size; i++, j++)
		nums1[i] = nums2[j];		/* merging nums2 to nums1 */

	/* sorting the array using bubble sort */
	for(i=0; i<nums1size; i++)
	{
		for(j=0; j < nums1size - i; j++)
		{
			if(nums1[j] > nums1[j+1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j+1];
				nums1[j+1] = temp;
			}
		}
	}
}

int main()
{
	int nums1[] = {1,2,3,0,0,0};
	int nums2[] = {2,5,6};
	int m = 3, n = 3, i;
	int nums1size = sizeof(nums1) / sizeof(nums1[0]);	/* assigning size for nums1 */
	int nums2size = sizeof(nums2) / sizeof(nums2[0]);	/* assigning size for nums2 */

	printf("Input : nums1 = [");
	for(i=0; i<nums1size; i++)
		printf("%d ",nums1[i]);		/* printing the input array nums1 */
	printf("]\n");

	printf("\tnums2 = [");
	for(i=0; i<nums2size; i++)
		printf("%d ",nums2[i]);		/* printing the input array nums2 */
	printf("]\n");

	merge(nums1, nums1size, m, nums2, nums2size, n);	/* merge function call */

	printf("Output : [");
	for(i=0; i<nums1size; i++)
		printf("%d ",nums1[i]);		/* printing the merge sorted array */
	printf("]\n");

	return 0;
}
