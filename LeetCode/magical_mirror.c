/* Charlie has a magical mirror that shows the right-rotated vesions of a given word. To generate different right
 * rotations of a word, the word is written in a circle in a clockwise ordfer and read it starting from any given
 * character in a clockwise order until all the characters are covered. For example, in the word "sample", if we start
 * with "p", we get the right rotated word as "plesam".
 *
 * Write an algorithm to output 1 if the word1 is a right rotation of word2 otherwise output 1.
 *
 * Example:
 * 		Input : sample
 * 		Output : plesam
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 19.10.2021
 * Author : Abinash
 */

#include<stdio.h>
#include<string.h>

void rightRotate(char str[])
{
	int i, j, k;
	int len = strlen(str);
	char temp[len];

	for(i=0; i<len; i++)
	{
		j = i;	/* Current index in str */
		k = 0;	/* Current index in temp */

		/* copying the second part from the letter 'p' */
		while(str[j] != '\0')
		{
			temp[k] = str[j];	/* copying letters "ple" */
			k++;
			j++;
		}

		/* copying the first part from the point of rotation */
		j = 0;
		while(j < i)
		{
			temp[k] = str[j];	/* copying letters "sam" */
			k++;
			j++;
		}

		if(temp[0] == 'p')
		{
			printf("%s", temp);	/* print the word "sample" */
			break;
		}
	}
	printf("\n");
}

/* main program */
int main()
{
	char str[] = "sample";
	rightRotate(str);

	return 0;
}
