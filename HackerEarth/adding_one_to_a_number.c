/* input : 2   --> no of inputs
 * 	   456
 * 	   123
 *
 * output : 457
 * 	    124
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 15.09.2021
 * Author : Abinash
 */

#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",n+1);
	}
	return 0;
}
