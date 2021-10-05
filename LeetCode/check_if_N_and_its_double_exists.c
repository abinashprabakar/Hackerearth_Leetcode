/* Given an array of integers, check if there exists two integers N and M such that N is the double of M
 * (i.e., N = 2 * M)
 * More formally check if there exists two indices i and j such that:
 *		i != j
 *		0 <= i, j < arr.length
 *		arr[i] == 2 * arr[j]
 *
 * Example 1:	
 * 		Input: arr = [10,2,5,3]
 * 		Output: True
 * 		Explanation : N = 10 is the double of M = 5,that is, 10 = 2 * 5.
 *
 * Example 2:
 * 		Input: arr = [3,1,7,11]
 * 		Output: False
 * 		Explanation : In this case does not exist N and M, such that N = 2 * M.
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 28.09.2021
 * Author : Abinash 
 */
#include<stdio.h>
#include<stdlib.h>
int checkifExist(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < arr[i]; arr[i+1])
		{
		if(arr[i] * 2 == j)
		{
			printf("true\n");
		}
		}
	}
}

int main()
{
	int arr[4], i;
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Enter the 4 elements\n");
	for(i=0; i<size; i++)
		scanf("%d",&arr[i]);
	checkifExist(arr,size);
	return 0;
}
