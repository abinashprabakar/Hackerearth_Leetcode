/* Given the head of a linked list, remove the nth node from the end of the list and return its head
 *
 * Input : head = [1, 2, 3, 4, 5], n = 2
 * Output : [1, 2, 4, 5]
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *add_node(NODE *head, int arr)
{
	NODE *new = (NODE *)malloc(sizeof(NODE*));
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
		new = temp->next;
	}
}

NODE* remove_node(NODE *head, int n)
{
		NODE *current = head, *prev = NULL;
		while(current != NULL)
		{
			if(current->data == n)
			{
				if(current == head)
				{
					head = current->next;
					current = head;
				}
				else
				{
					prev->next = current->next;
					current = current->next;
				}
			}
			else
			{
				prev = current;
				current = current->next;
			}

		}
		return head;
}

void display(NODE *head)
{
	NODE *temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/* main program */
int main()
{
	NODE *head = NULL;
	int n, i, val, arr[10];
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	for(i=0; i<n; i++)
		head = add_node(head, arr[i]);
	
	display(head);
	head = remove_node(head,val);
	display(head);

	return 0;
}
