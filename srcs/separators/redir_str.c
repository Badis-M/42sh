/*
** redir_str.c for redir_str.c in /home/merakc_b/rendu/42sh/PSU_2015_42sh/srcs/
**
** Made by Badis Merakchi
** Login   <merakc_b@epitech.eu>
**
** Started on  Mon May 30 15:33:46 2016 Badis Merakchi
** Last update Sun Jun 05 18:11:06 2016 maucha_a
*/

#include "mysh.h"

int		redir_right_str(char **cmd, char *name_file)
{
  int 		file;
  int 		file_save;
  int		excmd;

  if ((file = open(name_file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
      fprintf(stderr, "%s: %s.\n", name_file, strerror(errno));
      return (1);
    }
  file_save = dup(1);
  dup2(file, 1);
  close(file);
  excmd = exec(cmd);
  dup2(file_save, 1);
  return (excmd);
}

int		dble_redir_right_str(char **cmd, char *name_file)
{
  int		file;
  int		file_save;
  int 		excmd;

  if ((file = open(name_file, O_WRONLY | O_CREAT | O_APPEND, 00644)) == -1)
    {
      fprintf(stderr, "%s: %s.\n", name_file, strerror(errno));
      return (1);
    }
  file_save = dup(1);
  dup2(file, 1);
  close(file);
  excmd = exec(cmd);
  dup2(file_save, 1);
  return (excmd);
}

int		redir_left(char **cmd, char *name_file)
{
  int		file;
  int		file_save;
  int		excmd;

  if ((file = open(name_file, O_RDONLY)) == -1)
    {
      fprintf(stderr, "%s: %s.\n", name_file, strerror(errno));
      return (1);
    }
  file_save = dup(0);
  dup2(file, 0);
  close(file);
  excmd = exec(cmd);
  dup2(file_save, 0);
  return (excmd);
}
