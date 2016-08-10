/*
** exit.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/builtins/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Wed Jun  1 00:12:40 2016 Alexis Moisson
** Last update Sun Jun  5 18:37:53 2016 Johnatan Illi
*/

#include "mysh.h"

int	my_exit(char **cmd_tab)
{
  if (strcmp(cmd_tab[0], "exit") == 0)
    {
      if (cmd_tab[1] != NULL)
	{
	  if (my_isnum(cmd_tab[1]) == 0)
	    {
	      exit(my_getnbr(cmd_tab[1]));
	      return (1);
	    }
	  my_putstr("Syntax errors\n");
	  return (1);
	}
      my_putstr("exit\n");
      exit(0);
      return (0);
    }
  return (1);
}
