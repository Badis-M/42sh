/*
** manage_pwd.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/manage_env/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Tue May 31 20:50:07 2016 Alexis Moisson
** Last update Sun Jun  5 20:00:47 2016 Alexis Moisson
*/

#include "mysh.h"

void	manage_pwd(char **env)
{
  char	str[1024];

  if (getcwd(str, 1024) == NULL)
    return ;
  put_env(env, get_param(env, "PWD="), "OLDPWD=");
  put_env(env, str, "PWD=");
  return ;
}

void	switch_pwd(char **env)
{
  char	*pwd;
  char	*old_pwd;

  old_pwd = get_param(env, "OLDPWD=");
  pwd = get_param(env, "PWD=");
  put_env(env, old_pwd, "PWD=");
  put_env(env, pwd, "OLDPWD=");
  return ;
}

void	put_env(char **env, char *str, char *param)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = strlen(param);
  while (strncmp(env[i], param, k) != 0)
    i++;
  while (str[j])
    {
      env[i][k] = str[j];
      k++;
      j++;
    }
  env[i][k] = '\0';
  return ;
}
