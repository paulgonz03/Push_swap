#include "push_swap.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
    t_stack *a = 0;
    // t_stack *b = 0;
    if (argc < 2)
        return(0);
    if (!checkarguments(argv))
        return(ft_printf("Error checkarguments\n"), 1);
    if(!createstack(argc, argv, a))
        return(ft_printf("Error createstack\n"), 1);

}