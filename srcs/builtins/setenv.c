/*
** setenv.c for setenv in /home/merakc_b/rendu/42sh/PSU_2015_42sh/srcs/builtins/
**
** Made by Badis Merakchi
** Login   <merakc_b@epitech.eu>
**
** Started on  Tue May 31 16:03:54 2016 Badis Merakchi
** Last update Sun Jun  5 18:06:28 2016 Alexis Moisson
*/

#include "mysh.h"

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      puts(tab[i]);
      i++;
    }
}

int	my_setenv(char **cmd, char ***env)
{
  int	i;

  i = 0;
  if (strcmp(cmd[0], "setenv") != 0)
    return (1);
  if (strcmp(cmd[0], "setenv") == 0 && cmd[1] == NULL)
    {
      aff_tab(*env);
      return (0);
    }
  while ((*env)[i] && strncmp((*env)[i], cmd[1], strlen(cmd[1])))
    i++;
  if ((*env)[i] == NULL)
    {
      *env = realloc(*env, (sizeof(char *) * (tab_len(*env) + 2)));
      (*env)[i + 1] = NULL;
    }
  else
    free((*env)[i]);
  if (cmd[2] != NULL)
    (*env)[i] = concat(cmd[1], cmd[2], '=');
  else
    (*env)[i] = concat(cmd[1], "", '=');
  return (0);
}

char	**cpy_env(char **env)
{
  int	i;
  char	**new_env;

  i = 0;
  new_env = malloc((tab_len(env) + 1) * (sizeof(char *)));
  while (env[i] != NULL)
    {
      new_env[i] = strdup(env[i]);
      i++;
    }
  new_env[i] = NULL;
  return (new_env);
}

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      i++;
    }
  return (i);
}
