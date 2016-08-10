/*
** main_process.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/main_process/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Sat Jun  4 22:24:00 2016 Alexis Moisson
** Last update Sun Jun  5 18:16:01 2016 Alexis Moisson
*/

#include "mysh.h"

int	check_builtins(t_cmd cmd, char ***env)
{
  int	exit_value;

  exit_value = 1;
  if ((exit_value = cd(cmd.cmd_tab)) == 0)
    return (exit_value);
  else if ((exit_value = echo(cmd.cmd_tab)) == 0)
    return (exit_value);
  else if ((exit_value = my_exit(cmd.cmd_tab)) == 0)
    return (exit_value);
  else if ((exit_value = my_setenv(cmd.cmd_tab, env)) == 0)
    return (exit_value);
  else if ((exit_value = my_unsetenv(cmd.cmd_tab, env)) == 0)
    return (exit_value);
  return (1);
}

int		check_redirections(t_cmd cmd)
{
  int	exit_value;

  exit_value = 0;
  if (cmd.input_file != NULL)
    {
      exit_value = redir_left(cmd.cmd_tab, cmd.input_file);
      return (exit_value);
    }
  else if (cmd.output_file != NULL)
    {
      exit_value = redir_right_str(cmd.cmd_tab, cmd.output_file);
      return (exit_value);
    }
  else if (cmd.double_file != NULL)
    {
      exit_value = dble_redir_right_str(cmd.cmd_tab, cmd.double_file);
      return (exit_value);
    }
  return (-1);
}
