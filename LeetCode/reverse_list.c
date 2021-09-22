/* Given the head of a singly linked list, reverse the list and return the reversed list
 *
 * Input : head = [1, 2, 3, 4, 5]
 * Output : [5, 4, 3, 2, 1]
 */

#include<stdio.h>
#include<stdlib.h>

/* linked list structure */
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *add_node(NODE *head, int arr)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = arr;
	new->next = NULL;

	NODE *temp = head;
	
	if(temp == NULL)
		head = new;
	else
	{
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
	return head;
}

void display(NODE *head)
{
	NODE *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");

}

NODE *reverse_list(NODE *head)
{
	NODE *current = head, *prev = NULL, *next = NULL;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;

		current = next;
	}
	return prev;
}

/* main program */
int main()
{
	NODE* head = NULL;
	int i, n, arr[10];
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	for(i=0; i<n; i++)
		head = add_node(head, arr[i]);

	head = reverse_list(head);
	display(head);

	return 0;
}
