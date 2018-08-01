#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
            if (matrix[i][j] == 'd')
            {
                matrix[i][j] = '.';
                ft_putchar(' ');
                ft_putchar(matrix[i][j]);
                j++;
            }
            else if (matrix[i][j] == 'c')
            {
                matrix[i][j] = 'o';
                ft_putchar(' ');
                ft_putchar(matrix[i][j]);
                j++;
            }
            else
            {
                ft_putchar(' ');
                ft_putchar(matrix[i][j]);
                j++;
            }
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
            matrix[i][j] = '.';
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
    matrix[2][2] = 'o';
    matrix[3][2] = 'o';
    matrix[4][2] = 'o';
    matrix[4][1] = 'o';
    matrix[3][0] = 'o';

    matrix[6][6] = 'o';
    matrix[7][6] = 'o';
    matrix[8][6] = 'o';
}

int    ft_count_live(int x, int y, char matrix[10][11])
{
    int     istart;
    int     iend;
    int     jstart;
    int     jtmp;
    int     jend;
    int     nlive;

    nlive = 0;
    if ((x - 1) < 0)
    {
        jstart = x;
        jtmp = x;
    }
    else
    {
        jstart = x - 1;
        jtmp = x - 1;
    }
    if ((x + 1) == '\n')
        jend = x;
    else
        jend = x + 1;
    if ((y - 1) < 0)
        istart = y;
    else
        istart = y - 1;
    if ((y + 1) == '\n')
        iend = y;
    else
        iend = y + 1;
    while (istart <= iend)
    {
        while (jstart <= jend)
        {
            if (matrix[istart][jstart] == 'o' || matrix[istart][jstart] == 'd')
            {
                nlive++;
                jstart++;
            }
            else
                jstart++;
        }
        jstart = jtmp;
        istart++;
    }
    nlive = nlive - 1;
//    printf("nlive = %d\n", nlive);
    return (nlive);
}


void    ft_rules(char matrix[10][11])
{
    int i;
    int j;
    int xsituation;

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
            else if (matrix[i][j] == '.')
            {
                xsituation = ft_count_live(j, i, matrix) + 1;
                if (xsituation == 3)
                {
                    matrix[i][j] = 'c';
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
    int     a;
    char    matrix[10][11];
    
    a = 1;
    system("clear");
    ft_matrix(matrix);
    ft_putchar('\n');
    usleep(100000);
    system("clear");
    ft_add_life(matrix);
    while (a = 1)
    {
        ft_print_matrix(matrix);
        ft_putchar('\n');
        usleep(100000);
        system("clear");
        ft_rules(matrix);
        ft_print_matrix(matrix);
        usleep(100000);
        system("clear");
    }
    
    return (0);
}
