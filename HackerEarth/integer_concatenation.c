/* Input: The input consist of three space seperated integers- input1,input2, input3 representing the three four-digit numbers.
*  Output: print an integer representing the concatenation of four digits where 
*				
*	-- first digit represents the smallest digit in the thousands place of all three numbers,
*	-- second digit represents the largest digit in the hundreds place of all three numbers,
*	-- third digit represents the largest digit in the tens place of all three numbers,
*	-- fourth digit represents the largest digit in the units place of all three numbers.
*
* input: 3521 2452 1352
* Output: 1522
*
* Email : abinashprabakaran@gmail.com
* Date : 30.09.2021
* Author : Abinash
*/

#include<stdio.h>   

int power(int a,int b)
{
	int val = 1;
	if(b==0)
	{
		return 1;
	}
	while(b)
	{
		val = val *a;
		b--;
	}
	return val;
}

/* main program */
int main()
{
	int input[3],result=0,i,j,cnt;
	printf("Enter the input numbers: ");
	
	for(i=0;i<3;i++)
	{
		scanf("%d",&input[i]);	/* getting input from the user. eg : 3521 2452 1352 */
	}


	for(i=0;i<4;i++)
	{
		cnt = 0;
		if(i % 2 == 0)
		{
			for(j=0; j<3; j++)
			{
				if(cnt < (input[j] % 10))
				{
					cnt = input[j] % 10;
				}
				input[j] = input[j] / 10;
			}
			result = cnt * power(10,i) + result;
		}
		else
		{
			cnt = input[0] % 10;
			input[0] = input[0] / 10;
			for(j=1; j<3; j++)
			{
		        	if(cnt > (input[j] % 10))
		                {
					cnt = input[j] % 10;
				}
				input[j] = input[j] / 10;
			}
		  	result = cnt * power(10,i) + result;
		}
	}

	printf("result: %d\n",result);

	return 0;
}
