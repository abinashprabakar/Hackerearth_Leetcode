/* You are given a list of N unique positive numbers ranging from 0 to (N-1). Write an algorithm to replace the value
 * of each number with its corresponding index values in the list.
 *
 * Input :
 * 	The first line of the inout consists of an integer size, representing the size of the list(N). The next line
 * 	consists of N-space seperated integers, arr[0], arr[1]....arr[N-1] representing the given list of numbers
 *
 * Output :
 * 	Print N space-seperated integers representing the list obtained by replacing the values of the numbres with
 * 	their corresponding index values in the list.
 *
 * Example:
 * 	Input :	  4
 * 		  3 2 0 1
 * 	Output :  2 3 1 0
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 19.10.2021
 * Author : Abinash
 */

#include<stdio.h>

void change(int arr[], int n)
{
	int temp[n], i;
	
	for(i=0; i<n; i++)
		temp[arr[i]] = i;

	for(i=0; i<n; i++)
		arr[i] = temp[i];
}

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);

	printf("\n");
}

int main()
{
	int arr[] = {3, 2, 0, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Input: \n");
	print(arr, n);

	change(arr, n);

	printf("Output: \n");
	print(arr, n);

	return 0;
}
