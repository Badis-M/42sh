/*
** prompt.c for 42sh in /home/alexis/Documents/GitHub/42sh-Epitech/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Tue May 10 15:40:43 2016 Alexis Moisson
** Last update Sun Jun  5 18:30:28 2016 Alexis Moisson
*/

#include "mysh.h"

void		my_put_prompt(char **env)
{
  char		*user;
  char		*pwd;

  my_putstr(RED);
  my_putstr("| ");
  my_putstr(GREY);
  if ((user = get_param(env, "USER=")) == NULL)
    my_putstr("42sh-Epitech");
  else
    my_putstr(user);
  my_putstr(RED);
  my_putstr(" || ");
  my_putstr(GREY);
  if ((pwd = get_param(env, "PWD=")) == NULL)
    my_putstr("~/");
  else
    my_putstr(pwd);
  my_putstr(RED);
  my_putstr(" $>  ");
  my_putstr(DEFAULT_COLOR);
  free(user);
  free(pwd);
}
