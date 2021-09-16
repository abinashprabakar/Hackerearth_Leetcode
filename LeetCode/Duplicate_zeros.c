/* Given a fixed length array arr, duplicate each occurence of zero, shifting the remaining elements to the right.
 *
 * Input : arr = [1,0,2,3,0,4,5,0]
 * Output : [1,0,0,2,3,0,0,4]
 * Explanation : After calling your function, the input array is modified to : [1,0,0,2,3,0,0,4]
 *
 * Constraints :
 * 	1 <= arr.length <= 10^4
 * 	0 <= arr[i] <= 9
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 16.09.2021
 * Author : Abinash
 */

#include<stdio.h>

int duplicateZeros(int *arr, int size)
{
	int i,j;
	for(i=0; i<size; i++)
	{
		if(arr[i] == 0)
		{
			for(j = size-1; j>i; j--)
			{
				arr[j] = arr[j-1];
			}
			i++;	/* pointing to next element */
		}
	}
}

int main()
{
	int arr[] = {1,0,2,3,0,4,5,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	printf("Input : arr = [");
	
	for(i=0; i<size; i++)
		printf("%d ",arr[i]);	/* displaying input array */
	printf("]\n");

	duplicateZeros(arr, size);	/* duplicateZero function call */

	printf("Output : [");

	for(i=0; i<size; i++)
		printf("%d ",arr[i]);	/* displaying output (duplicateZeros) array */
	printf("]\n");
	return 0;
}
