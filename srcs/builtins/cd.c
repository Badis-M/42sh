/*
** cd.c for cd in /home/merakc_b/rendu/42sh/PSU_2015_42sh/srcs/
**
** Made by Badis Merakchi
** Login   <merakc_b@epitech.eu>
**
** Started on  Mon May 30 15:33:34 2016 Badis Merakchi
** Last update Sun Jun  5 18:51:35 2016 Alexis Moisson
*/

#include "mysh.h"

int		cd(char **cmd)
{
  int	exit_value;

  exit_value = 0;
  if (strcmp(cmd[0], "cd") == 0)
    {
      if (cmd[1] != NULL)
	{
	  if (strcmp(cmd[1], "-") == 0)
	    {
	      chdir(get_param(my_env, "OLDPWD="));
	      switch_pwd(my_env);
	    }
	  else if (strcmp(cmd[1], "-") != 0)
	    exit_value = condi_cd(my_env, cmd);
	}
      else
	{
	  chdir(get_param(my_env, "HOME="));
	  manage_pwd(my_env);
	}
      return (exit_value);
    }
  return (1);
}

int	condi_cd(char **env, char **cmd)
{
  struct stat	file;

  if (stat(cmd[1], &file) == -1)
    {
      printf("%s: %s.\n", cmd[1], strerror(errno));
      return (1);
    }
  else if (open(cmd[1], O_DIRECTORY) == -1)
    {
      printf("%s: %s.\n", cmd[1], strerror(errno));
      return (1);
    }
  else if (stat(cmd[1], &file) == 0 && open(cmd[1], O_DIRECTORY) != -1)
    {
      chdir(cmd[1]);
      manage_pwd(env);
      return (0);
    }
  return (0);
}
