#include "push_swap.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
    t_stack *a = 0;
    t_stack *b = NULL;
    if (argc < 2)
        error();
    if (!checkarguments(argv))
        error();
    if(!createstack(argc, argv, a, b))
        error();
    exit(EXIT_SUCCESS);
}
