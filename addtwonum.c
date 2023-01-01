
//  Definition for singly-linked list.
typedef	struct ListNode {
     int val;
     struct ListNode *next;
 };

#include<stdlib.h>
#include<stdio.h>

struct ListNode	*ft_lstlast(struct ListNode *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

struct ListNode	*ft_lstnew(int content)
{
	struct ListNode	*node;

	node = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!node)
		return (NULL);
	node->val = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(struct ListNode **lst, struct ListNode *new)
{
	struct ListNode	*current;

	if (!*lst)
		*lst = new;
	else
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *new;
	new = NULL;
	int r = 0, c;
	while (l1 && l2)
	{
		c = l1->val + l2->val;
		ft_lstadd_back(&new, ft_lstnew(c % 10));
		if (c > 9)
		{
			if (l1->next)
				l1->next->val += 1;
			else if (l2->next)
				l2->next->val += 1;
            else
				ft_lstadd_back(&new, ft_lstnew(1));

		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		if (l1->val > 9 && l1->next)
			l1->next->val +=1;
		ft_lstadd_back(&new, ft_lstnew(l1->val % 10));
		if (l1->next == NULL && l1->val > 9)
			ft_lstadd_back(&new, ft_lstnew(1));
		l1 = l1->next;
	}
	while (l2)
	{
		if (l2->val > 9 && l2->next)
			l2->next->val +=1;
		ft_lstadd_back(&new, ft_lstnew(l2->val % 10));
		if (l2->next == NULL && l2->val > 9)
			ft_lstadd_back(&new, ft_lstnew(1));
		l2 = l2->next;
	}
	return new;
}