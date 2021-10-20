/* Given the head of a singly linked list, return the middle node of the linked list
 * If there are two middle nodes, return the second middle node.
 *
 * Example1 : Input : [1,2,3,4,5]
 * 	      Output: [3,4,5]
 * 
 * Example2 : Input : [1,2,3,4,5,6]
 * 	      Output: [4,5,6]
 */

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *middle(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;

	while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if(fast->next == NULL)
	{
		head = slow;
		return head;
	}

	else
	{
		head = slow->next;
		return head;
	}
}

int main()
{
	struct node *head = NULL;
	middle(head);
}
