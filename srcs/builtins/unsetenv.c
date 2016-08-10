/*
** unsetenv.c for unsetenv in /home/merakc_b/rendu/42sh/PSU_2015_42sh/srcs/builtins/
**
** Made by Badis Merakchi
** Login   <merakc_b@epitech.eu>
**
** Started on  Thu Jun  2 22:14:09 2016 Badis Merakchi
** Last update Sun Jun  5 18:43:05 2016 Alexis Moisson
*/

#include "mysh.h"

int	my_unsetenv(char **cmd, char ***env)
{
  int	i;

  i = 0;
  if (strcmp(cmd[0], "unsetenv") != 0)
    return (1);
  if (strcmp(cmd[0], "unsetenv") == 0 && cmd[1] == NULL)
    {
      puts("unsetenv: Too few arguments.");
      return (1);
    }
  if (strcmp(cmd[1], "*") == 0)
    all_unsetenv(cmd, env);
  while ((*env)[i] && strncmp((*env)[i], cmd[1], strlen(cmd[1])))
      i++;
  if ((*env)[i] != NULL)
    {
      free((*env)[i]);
      while ((*env)[i + 1] != NULL)
	{
	  (*env)[i] = (*env)[i + 1];
	  i++;
	}
    }
  (*env)[i] = NULL;
  return (0);
}

int	all_unsetenv(char **cmd, char ***env)
{
  int	i;

  i = 0;
  if (strcmp(cmd[0], "unsetenv") != 0)
    return (0);
  if (strcmp(cmd[0], "unsetenv") == 0 && strcmp(cmd[1], "*") == 0)
    {
      free((*env)[i]);
      while ((*env)[i + 1] != NULL)
	{
	  (*env)[i] = NULL;
	  i++;
	}
    }
  (*env)[i] = NULL;
  return (1);
}
