#include "push_swap.h"
#include "libft/libft.h"

void printmatrix(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[y])
    {
        while (map[y][x])
        {
            printf("%c", map[y][x]);
            x++;
        }
        x = 0;
        y++;
    }
    printf("\n");
    return ;
}
void	freematrix(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->num = num;
	new->next = NULL;
	return (new);
}
void print_stack(t_stack *stack)
{ 
	while (stack)
	{
		printf("Content: %d\n", stack->num);
		stack = stack->next;
	}
}
t_stack *liststring(char **argv, int k) 
{
	char **matrixnum = NULL;
	t_stack *newnode;
    int j = 0;
	t_stack *temp = 0;
	int i = 0;


    matrixnum = ft_split(argv[k], ' ');
	while (matrixnum[i])
	{
		printf("matrix: %s\n", matrixnum[i]);
		i++;
	}
    if (!matrixnum)
        return(0);
    temp = ft_lstnew(ft_atoi(matrixnum[j]));
    j++;
	// printf("k-->%d\n", k);
	// print_stack(temp);
    while (matrixnum[j])
    {
	    newnode = ft_lstnew(ft_atoi(matrixnum[j]));
        if (!newnode)
            return (0);
        ft_lstadd_back (&temp, newnode);
        j++;
    }
	freematrix(matrixnum);
	return(temp);
}

t_stack *listargv(char **argv, int argc) 
{
	t_stack *newnode;
	t_stack *temp = 0;
    int k = 1;
    int i = 0;
	int counter = 0;
	
	while (argv[k] && k < argc)
	{
		i = 0;
		while (argv[k][i] != '\0')
		{
			printf("-->%c\n", argv[k][i]);
			while ((argv[k][i]) == 32)
				i++;
			while ((argv[k][i] >= '0' && argv[k][i] <= '9'))
				i++;
			while ((argv[k][i]) == 32)
				i++;
			if (argv[k][i] >= '0' && argv[k][i] <= '9')
			{
				counter++;
				i++;
			}
		}
		if (counter > 0)
		{
			newnode = liststring(&argv[k], k);
			printf("hola\n");
		}
		else 
			newnode = ft_lstnew(ft_atoi(argv[k]));
        if (!newnode)
            return (0);
        ft_lstadd_back (&temp, newnode);
		k++;
	}
	return(temp);
}

int createstack(int argc, char **argv, t_stack *a)
{
	int k = 1;
	if (argc == 2)
	{
		a = liststring(argv, k);
		if (!a)
			return(0);
	}
	else 
	{
		a = listargv(argv, argc);
		if (!a)
			return(0);
	}
	print_stack(a);
    return (1);
}
