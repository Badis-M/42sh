/*
** display_success.c for lib in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/lib/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Mon May 30 15:11:06 2016 Alexis Moisson
** Last update Tue May 31 12:04:29 2016 Alexis Moisson
*/

#include "mysh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

void	my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  if (nbr > 9)
    my_putnbr(nbr / 10);
  my_putchar(nbr % 10 + '0');
}
