/*
** get_env.c for 42sh in /home/alexis/Documents/GitHub/42sh-Epitech/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Tue May 10 20:32:14 2016 Alexis Moisson
** Last update Tue May 31 12:15:45 2016 Badis Merakchi
*/

#include "mysh.h"

char		*get_param(char **env, char *param)
{
  int		i;
  char		*save;
  char		*value;

  i = 0;
  if (env[0] == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if ((strncmp(env[i], param, strlen(param))) == 0)
	{
	  save = strdup(env[i]);
	  save += strlen(param);
	  value = strdup(save);
	  save -= strlen(param);
	  free(save);
	  return (value);
	}
      i++;
    }
  return (NULL);
}

char		**get_path(char **env)
{
  return (str_to_wordtab(get_param(env, "PATH="), ':'));
}
