/*
** main.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/main_process/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Tue May 31 12:07:27 2016 Alexis Moisson
** Last update Sun Jun  5 20:31:39 2016 Alexis Moisson
*/

#include "mysh.h"

void	ctrl_c()
{
  my_putchar('\n');
  my_put_prompt(my_env);
  return ;
}

int	execute_cmd(t_cmd cmd, char ***env)
{
  int	exit_value;

  exit_value = 0;
  if ((exit_value = check_redirections(cmd)) != -1)
    return (exit_value);
  else if ((exit_value = check_builtins(cmd, env)) == 0)
    return (exit_value);
  else if ((exit_value = exec(cmd.cmd_tab)) == -1)
    printf("%s: Command not found.\n", cmd.cmd_tab[0]);
  else
    return (exit_value);
  return (1);
}

int	process(t_cmds cmd, char ***env)
{
  int	a;
  int	debug;
  int	j;

  a = 0;
  j = 0;
  while (cmd.cmd[j].main_str != NULL)
    {
      debug = execute_cmd(cmd.cmd[j], env);
      if (cmd.controleur[a] != NULL)
	{
	  if ((debug == 0 && strcmp(cmd.controleur[a], "||") == 0)
	      || (debug != 0 && strcmp(cmd.controleur[a], "&&") == 0))
	    j = j + 2;
	  else if ((debug != 0 && strcmp(cmd.controleur[a], "||") == 0)
		   || (debug == 0 && strcmp(cmd.controleur[a], "&&") == 0))
	    j = j + 1;
	  else
	    j = j + 1;
	  a = a + 1;
	}
      else
	j = j + 1;
    }
  return (debug);
}

int	main_process(t_cmds *cmd_tab, char ***env)
{
  int	i;
  int	exit_value;

  i = 0;
  exit_value = 0;
  while (cmd_tab[i].main_str != NULL)
    {
      exit_value = process(cmd_tab[i], env);
      i++;
    }
  return (exit_value);
}

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  t_cmds *cmd_tab;
  char	*str;
  int	exit_value;

  my_env = cpy_env(env);
  my_put_prompt(my_env);
  signal(SIGINT, ctrl_c);
  exit_value = 0;
  while ((str = get_next_line(0)))
    {
      if (str[0] != '\0')
	{
	  cmd_tab = main_parsing(str);
	  exit_value = main_process(cmd_tab, &my_env);
	}
      my_put_prompt(my_env);
    }
  my_putstr("exit\n");
  return (exit_value);
}
