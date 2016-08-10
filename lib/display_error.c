/*
** display_error.c for lib in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/lib/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Mon May 30 15:11:06 2016 Alexis Moisson
** Last update Tue May 31 12:04:24 2016 Alexis Moisson
*/

#include "mysh.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(2, str, i);
}

void	my_putnbr_error(int nb)
{
  if (nb < 0)
    {
      my_putchar_error('-');
      nb = -nb;
    }
  if (nb > 9)
    my_putnbr_error(nb / 10);
  my_putchar_error(nb % 10 + '0');
}
