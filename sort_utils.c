#include "push_swap.h"
#include "libft/libft.h"

// void print_stack(t_stack *stack)
// { 
// 	while (stack)
// 	{
// 		printf("Index: %d, num: %d\n", stack->index, stack->num);
// 		stack = stack->next;
// 	}
// }

int square(int len)
{
    int n;

    n = 2;
    if (len < 4)
        return(1);
    else
    {
        while (n * n <= len)
        {
            if (n * n == len)
                return(n); 
            n++;
        }   
        return (n - 1);
    }
}

int counter(t_stack *b, int pos)
{
    int counter;

    counter = 0;
    while (b)
    {
        if (pos == b->index)
            return(counter);
        counter++;
        b = b->next;
    }
    return(0);
}

