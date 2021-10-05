/* Given the head of a singly linked list, return true if it is a palindrome
 *
 * Input : head = [1,2,2,1]
 * Output : true 
 *
 * Input : head = [1,2]
 * Output : false
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

struct node *head = NULL, *prev = NULL;

node *add_node(node *head, int n)
{
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	node *p = head;

	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		while(p->next!=NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}

void display(node *head)
{
	node *temp = head;
	
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int palindrome(node *head)
{
	node *p = head, *temp = head;
	node *prev=NULL;

	while(p)
	{
		temp = temp->next;
	}
	if(temp->data != p->data)
	{
		return 0;
	}
	prev = temp;
	p = p->next;
	temp = p;

	if(prev = p)
		return 1;
}

int main()
{
	node *head = NULL;
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	for(i=0; i<n; i++)
		head = add_node(head, arr[i]);
	
	display(head);
	
	if(palindrome(head))
		printf("true\n");
	else
		printf("False\n");

	return 0;
}
