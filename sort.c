#include "push_swap.h"
#include "libft/libft.h"

int *bubble_sort(int *ordennums)
{
    int i;
    int aux;

    i = 0;
    aux = 0;
    while (ordennums[i] && ordennums[i + 1])
    {
        if (ordennums[i] > ordennums[i + 1])
        {
            aux = ordennums[i];
            ordennums[i] = ordennums[i + 1];
            ordennums[i + 1] = aux;
        }
        i++;
    }
    return(ordennums);
}

int *issorter(int *ordennums)
{
    int i = 0;

    while (ordennums[i] && ordennums[i + 1])
    {
        if (ordennums[i] < ordennums[i + 1])
            i++;
        else
        {
            ordennums = bubble_sort(ordennums);
            i = 0;
        }
    }
    // while (ordennums[j])
    // {
    //     printf("%d\n", ordennums[j]);
    //     j++;
    // }
    return(0);
}

t_stack *setindex(t_stack *a, int *ordernums)
{

}
