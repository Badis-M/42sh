/*
** main_parsing.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/parsing/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Thu Jun  2 22:27:09 2016 Alexis Moisson
** Last update Sun Jun  5 19:44:32 2016 Alexis Moisson
*/

#include "mysh.h"

t_cmd	init_struct_cmd()
{
  t_cmd	cmd;

  cmd.cmd_tab = NULL;
  cmd.main_str = NULL;
  cmd.input_file = NULL;
  cmd.output_file = NULL;
  cmd.double_file = NULL;
  return (cmd);
}

t_cmds		init_struct_cmds(int nbr_cmds)
{
  t_cmds	cmds;
  int		i;

  i = 0;
  cmds.controleur = NULL;
  cmds.main_str = NULL;
  if ((cmds.cmd = malloc(sizeof(t_cmd) * (nbr_cmds + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (i < nbr_cmds)
    cmds.cmd[i++] = init_struct_cmd();
  return (cmds);
}

int	count_cmd(char	*str)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 1;
  while (str[i])
    {
      if (((str[i] == '|' && str[i + 1] == '|')
	   || (str[i] == '&' && str[i + 1] == '&'))
	  && (str[i + 2] == ' ' && str[i - 1] == ' '))
	nbr++;
      i++;
    }
  return (nbr);
}

t_cmds		*start_parsing(char *str)
{
  t_cmds	*cmds;
  char		**tab;
  int		i;
  int		len;

  i = 0;
  len = len_wordtab(str, ';');
  if ((cmds = malloc(sizeof(t_cmds) * (len + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab = str_to_wordtab(str, ';');
  while (tab[i])
    {
      cmds[i] = init_struct_cmds(count_cmd(tab[i]));
      if ((cmds[i].main_str = strdup(tab[i])) == NULL)
	exit(EXIT_FAILURE);
      i++;
    }
  cmds[i].main_str = NULL;
  free(tab[0]);
  free(tab);
  return (cmds);
}

t_cmds		*main_parsing(char *str)
{
  t_cmds	*cmds;
  int		i;

  i = 0;
  cmds = start_parsing(str);
  while (cmds[i].main_str != NULL)
    {
      cmds[i] = split_main_str(cmds[i]);
      i++;
    }
  free(str);
  return (cmds);
}
