/*
** echo.c for echo in /home/quentin/rendu/Other/PSU_2015_42sh/srcs/builtins
**
** Made by Quentin
** Login   <quentin@epitech.net>
**
** Started on  Fri Jun 03 20:05:03 2016 Quentin
** Last update Sun Jun  5 18:36:32 2016 Alexis Moisson
*/

#include "mysh.h"

void	my_puts(char **cmd)
{
  int	i;

  i = 1;
  while (cmd[i] != NULL)
    {
      my_putstr(cmd[i]);
      if (cmd[i + 1] != NULL)
	my_putchar(' ');
      i++;
    }
  return ;
}

int	echo(char **cmd)
{
  if (strncmp(cmd[0], "echo", 4) == 0)
    {
      if (cmd[1] != NULL)
	{
	  if (strcmp(cmd[1], "-n") == 0)
	    my_puts(cmd + 1);
	  else
	    {
	      my_puts(cmd);
	      my_putchar('\n');
	    }
	}
      else
	my_putchar('\n');
      return (0);
    }
  return (1);
}
