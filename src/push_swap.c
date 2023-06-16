#include "push_swap.h"

// t_stack *init_stack(t_stack **head, int data)
// {
// 	t_stack *temp;
// 	temp = (t_stack*)malloc(sizeof(t_stack));
// 	temp->data=data;
// 	temp->next=temp;
// 	temp->prev=temp;
// 	*head = temp;
// 	return (*head);
// }

int	main(int argc, char *argv[])
{
	t_stack	a;
	if (argc >= 2)
		parse_input(&a, argv);
	print_stack(&a);
	append(&a, 99);
	print_stack(&a);
	swap(&a);
	print_stack(&a);
	return (0);
}


	// ft_printf("next(%d)\n", stack->next->data);
	// ft_printf("prev %d tail %d\n", (stack->head->prev->data), stack->tail->data);
	// ft_printf("\nswap(%d)\n", stack->next->data);

// arr[i] = ft_atoi((ft_split(argv[i + 1], ' ')[0]));
	// int		*arr;
	// arr = calloc(20, sizeof(int));
	// while (argv[i + 1] != 0 && argc)
	// {
	// 	populate(&a, ft_atoi((ft_split(argv[i + 1], ' ')[0])));
	// 	i++;
	// }
	
// ft_printf("%d\n", arr[i]);
	// ft_printf("next %d n n %d\n", (a.head->next->data), (a.head->next->next->data));
	// ft_printf("prev %d p p %d\n", (a.head->prev->data), (a.head->prev->prev->data));
	// ft_printf("%d\n\n", a.data);
	// t_stackiter = a.head;
	// a.tail = a.head->prev;
	// ft_printf("next %d n n %d\n", (a.head->next->data), (a.head->next->next->data));
	// // ft_printf("prev %p tail %p\n", (a.head->prev), a.tail);
	// // ft_printf("prev %p tail %p\n", (a.head->prev), a.tail);
	// ft_printf("prev %d tail %d\n", (a.head->prev->data), a.tail->data);
	// ft_printf("here\nprev %d tail %d\n", (a.head->next->data), a.tail->data);
	// // while (t_stackiter != a.tail)
	// // {
	// // 	t_stackiter = t_stackiter->next;
	// // 	ft_printf("%d\n", t_stackiter->data);
	// // }
	// // swap_a(&a);