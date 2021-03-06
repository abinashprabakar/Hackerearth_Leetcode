/* You are given an integer array nums and you have to return a new counts array. The counts array has the property
 * where counts[i] is the number of smaller elements to the right of nums[i] 
 *
 * Example 1 :
 * 		Input : nums = [5,2,6,1]
 * 		Output : [2,1,1,0]
 *
 * 		Explanation :
 * 		To the right of 5 there are 2 smaller elements ( 2 and 1)
 * 		To the right of 2 there is only 1 smaller element (1)
 * 		To the right of 6 there is 1 smaller element (1)
 * 		To the right of 1 there is 0 smaller element.
 *
 * Example 2 :
 * 		Input : nums = [-1,-1]
 * 		Output : [0,0]
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 14.10.2021
 * Author : Abinash
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
        int height;
        int val;
        struct node *l, *r;
        int count; //duplicated node count beacuse of duplicated input nums
        int sub_count; //totol count includes both all child node counts & self
};

struct node *new_node(int val)
{
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));
        memset(new, 0, sizeof(struct node));
        new->height = 1;
        new->val = val;
        new->count = 1;
        new->sub_count = 1;

        return new;
}

static int max(int a, int b)
{
        return a > b ? a : b;
}

static int get_height(struct node *root)
{
        if (!root)
                return 0;
        return root->height;
}

static int get_sub_count(struct node *root)
{
        if (!root)
                return 0;
        return root->sub_count;
}

static int get_balance_factor(struct node *root)
{
        if (!root)
                return 0;
        return get_height(root->l) - get_height(root->r);
}

struct node *rotate_right(struct node *root)
{
        struct node *l = root->l;
        root->l = l->r;
        l->r = root;

        root->sub_count = get_sub_count(root->l) + get_sub_count(root->r) + root->count;
        l->sub_count = get_sub_count(l->l) + get_sub_count(l->r) + l->count;

        root->height = max(get_height(root->l), get_height(root->r)) + 1;
        l->height = max(get_height(l->l), get_height(l->r)) + 1;

        return l;
}

struct node *rotate_left(struct node *root)
{
        struct node *r = root->r;
        root->r = r->l;
        r->l = root;

        root->sub_count = get_sub_count(root->l) + get_sub_count(root->r) + root->count;
        r->sub_count = get_sub_count(r->l) + get_sub_count(r->r) + r->count;

        root->height = max(get_height(root->l), get_height(root->r)) + 1;
        r->height = max(get_height(r->l), get_height(r->r)) + 1;

        return r;
}

struct node *avl_balance(struct node *root)
{
        int bf, child_bf;

        bf = get_balance_factor(root);
        if (bf > 1) {
                child_bf = get_balance_factor(root->l);
                if (child_bf >= 0) {
                        root = rotate_right(root);
                } else {
                        root->l = rotate_left(root->l);
                        root = rotate_right(root);
                }
        } else if (bf < -1) {
                child_bf = get_balance_factor(root->r);
                if (child_bf <= 0) {
                        root = rotate_left(root);
                } else {
                        root->r = rotate_right(root->r);
                        root = rotate_left(root);
                }
        }

        return root;
}

struct node *insert_node(struct node *root, int val)
{
        if (!root) {
                root = new_node(val);
                return root;
        }

        if (root->val == val) {
                root->count++;
        } else if (root->val > val) {
                root->l = insert_node(root->l, val);
        } else {
                root->r = insert_node(root->r, val);
        }
        root->sub_count++;

        root->height = max(get_height(root->l), get_height(root->r)) + 1;
        root = avl_balance(root);

        return root;
}

int get_small_count(struct node *root, int val)
{
        int count = 0;

        if (!root)
                return 0;

        if (root->val == val)
                count += get_sub_count(root->l);
        else if (root->val < val) {
                count = count + root->count + get_sub_count(root->l);
                count += get_small_count(root->r, val);
        } else {
                count += get_small_count(root->l, val);
        }

        return count;
}

void free_node(struct node *root)
{
        if (!root)
                return;
        if (root->l)
                free_node(root->l);
        if (root->r)
                free_node(root->r);
        free(root);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
        struct node *root = NULL;
        int *rt = (int *)malloc(sizeof(nums[0]) * numsSize);

        int i;
        for (i = numsSize - 1; i >= 0; i--) {
                root = insert_node(root, nums[i]);
                rt[i] = get_small_count(root, nums[i]);
        }
        *returnSize = numsSize;

        free_node(root);
        
        return rt;
}

int main()
{
	return 0;
}
