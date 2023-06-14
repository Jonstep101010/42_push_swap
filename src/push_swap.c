#include "push_swap.h"

t_stack *init_stack(t_stack **head, int data)
{
	t_stack *temp;
	temp = (t_stack*)malloc(sizeof(t_stack));
	temp->data=data;
	temp->next=temp;
	temp->prev=temp;
	*head = temp;
	return (*head);
}

void append(t_stack** head_ref, t_stack (**tail_ref), int new_data) {
	// 1. allocate node
	if (!*head_ref)
		return;
	t_stack* new_node = malloc(sizeof(t_stack));
	t_stack* last = *head_ref; /* used in step 5*/
	// 2. put in the data
	new_node->data = new_data;
	// 3. This new node is going to be the last node, so make next of it as NULL
	new_node->next = *head_ref;
	// 4. If the list is empty, make new node as head
	// 5. Else traverse till the last node
	while (last->next != *head_ref)
		last = last->next;
	// 6. Change the next of last node
	last->next = new_node;
	// 7. Make last node as previous of new node
	// new_node->prev = last;
	// 8. Change next of New_node's next node
	// new_node->next->prev = new_node;
	*tail_ref = last->next;
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	// t_stack	b;
	// char	***s = NULL;
	int		*arr;
	t_stack	*nodeiter;
	// int		i;
	// i = 0;
	// argc--;
	// arr = calloc(sizeof(int), 20);
	int i = 0;
	arr = calloc(20, sizeof(int));
	// printf("%s\n", argv[i + 2]);
	while (argv[i + 1] != 0 && argc)
	{
		arr[i] = ft_atoi((ft_split(argv[i + 1], ' ')[0]));
		i++;
	}
	init_stack(&a.head, *arr);
	printf("%d\n\n", a.data);
	while (i--)
	{
		append(&a.head, &a.tail, *(arr++));
		// printf("%d\n", *(++arr));
		// arr++;
	}
	nodeiter = a.head;
	while (nodeiter != a.tail)
	{
		nodeiter = nodeiter->next;
		printf("%d\n", nodeiter->data);
	}
	printf("\ntail =%d\n", a.tail->data);
	// i = 0;
	// while (arr[i])
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// i = 0;
	// while (arr[i])
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// i = 0;
	// while (arr[i])
	// {
	// 	printf("arr[%d] = %d\n", i,arr[i]);
	// 	i++;
	// }
	// printf("%s", argv[1]);
	// while (i < (ft_strlen(argv[1]) - 1)  && argc >= 2)
	// {
	// 	if (i == 0)
	// 		s = ft_split(argv[1], ' ');
	// 	while (s[i])
	// 	{
	// 		arr[i] = ft_atoi(s[i]);
	// 		i++;
	// 	}
	// }
	// i = 0;
	// while (arr[i])
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// init_stack(&a.head, arr[0]);
	// printf("%d\n", a.data);
	// printf("arr[i] = %d\n", arr[1]);
	// ft_printf("%s\n", argv[1]);
	// while (i >= 0 && ft_isdigit((int)argv[i]))
	// {
	// 	ft_printf("%d\n", argv[i]);
	// 	i--;
	// }arr);
	// ft_isdigit((int) argv[0]);
	// ft_printf("number of args provided: %d\n", i);
	// if (argc)
	// {
	// 	ft_printf("argc > 1\n");
	// 	ft_printf("argc: %d\n", argc);
	// 	ft_printf(argv[1]);
	// }
	return (0);
}


	// init_stack(&a.head, arr[0]);
	// printf("%d\n", a.data);
	// printf("arr[i] = %d\n", arr[1]);
	// ft_printf("%s\n", argv[1]);
	// while (i >= 0 && ft_isdigit((int)argv[i]))
	// {
	// 	ft_printf("%d\n", argv[i]);
	// 	i--;
	// }arr);
	// ft_isdigit((int) argv[0]);
	// ft_printf("number of args provided: %d\n", i);
	// if (argc)
	// {
	// 	ft_printf("argc > 1\n");
	// 	ft_printf("argc: %d\n", argc);
	// 	ft_printf(argv[1]);
	// }