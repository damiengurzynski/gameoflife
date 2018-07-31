#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_matrix(char matrix[10][11])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i <= 9)
    {
        while (j <= 10)
        {
            ft_putchar(' ');
            ft_putchar(matrix[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
}

void    ft_matrix(char matrix[10][11])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i <= 9)
    {
        while (j <= 9)
        {
            matrix[i][j] = 'x';
            j++;
        }
        matrix[i][j] = '\n';
        j = 0;
        i++;
    }
    ft_print_matrix(matrix);
}

void    ft_add_life(char matrix[10][11])
{
    matrix[1][1] = 'o';
    matrix[1][2] = 'o';
    matrix[2][2] = 'o';
    matrix[2][1] = 'o';
    matrix[2][3] = 'o';
}

int    ft_count_live(int x, int y, char matrix[10][11])
{
    int     i;
    int     j;
    int     nlive;

    j = x - 1;
    i = y - 1;
    nlive = 0;
    while (i <= (y + 2))
    {
        while (j <= (x + 2))
        {
            if (matrix[i][j] == 'o')
            {
                nlive++;
                j++;
            }
            else
                j++;
        }
        j = x - 1;
        i++;
    }
    nlive = nlive - 1;
    printf("nlive = %d\n", nlive);
    return (nlive);
}


void    ft_rules(char matrix[10][11])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i <= 10)
    {
        while (j <= 11)
        {
            if (matrix[i][j] == 'o')
            {
                if (ft_count_live(j, i, matrix) < 2 || ft_count_live(j, i, matrix) > 3)
                {
                    matrix[i][j] = 'd';
                    j++;
                }
                else
                    j++;
            }
            else
                j++;
        }
        j = 0;
        i++;
    }

}

int     main(void)
{
    char    matrix[10][11];

    ft_matrix(matrix);
    ft_putchar('\n');
    ft_add_life(matrix);
    ft_print_matrix(matrix);
    ft_putchar('\n');
    ft_rules(matrix);
    ft_print_matrix(matrix);
    return (0);
}
