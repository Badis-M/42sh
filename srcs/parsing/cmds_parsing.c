/*
** cmds_parsing.c for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/parsing/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Fri Jun  3 15:23:30 2016 Alexis Moisson
** Last update Sun Jun  5 23:38:25 2016 Badis Merakchi
*/

#include "mysh.h"

int		count_controleur(char *str)
{
  int		i;
  int		nbr;

  i = 0;
  nbr = 0;
  while (str[i])
    {
      if ((str[i] == '|' && str[i + 1] == '|')
	  || (str[i] == '&' && str[i + 1] == '&'))
	nbr++;
      i++;
    }
  return (nbr);
}

int		check_controleur(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '|' && str[i + 1] == '|')
	{
	  if (str[0] == '|' || str[strlen(str) - 1] == '|'
	      || str[i - 1] != ' ' || str[i + 2] != ' ')
	    {
	      fprintf(stderr, "Invalid null command.\n");
	      return (0);
	    }
	}
      if (str[strlen(str) - 1] == '&' && str[strlen(str) - 2] == '&')
	{
	  fprintf(stderr, "Invalid null command.\n");
	  return (0);
	}
      i++;
    }
  return (1);
}

char		**add_controlleur(char *str)
{
  char		**controleur;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (check_controleur(my_epurstr(str)) == 0)
    return (NULL);
  if ((controleur = malloc(sizeof(char *)
			   * (count_controleur(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i + 1] && str[i] != '&' && str[i] != '|'
	     && str[i + 1] != '&' && str[i + 1] != '|')
	i++;
      if (str[i] == '&' && str[i + 1] == '&')
	controleur[j++] = strdup("&&");
      else if (str[i] == '|' && str[i + 1] == '|')
	controleur[j++] = strdup("||");
      i++;
    }
  controleur[j] = NULL;
  return (controleur);
}

t_cmd		parse_simple_cmd(t_cmd cmd)
{
  int		i;

  i = 0;
  while (cmd.main_str[i] && cmd.main_str[i] != '>'
	 && cmd.main_str[i] != '|' && cmd.main_str[i] != '<')
    i++;
  cmd.cmd_tab = str_to_wordtab(my_epurstr(strndup(cmd.main_str, i)), ' ');
  if (cmd.main_str[i] == '>' && cmd.main_str[i + 1] == ' ')
    cmd.output_file = my_epurstr(get_file(cmd.main_str, i + 1));
  else if (cmd.main_str[i] == '>' && cmd.main_str[i + 1] == '>')
    cmd.double_file = my_epurstr(get_file(cmd.main_str, i + 2));
  else if (cmd.main_str[i] == '<' && cmd.main_str[i + 1] == ' ')
    cmd.input_file = my_epurstr(get_file(cmd.main_str, i + 1));
  else
    {
      cmd.input_file = NULL;
      cmd.output_file = NULL;
      cmd.double_file = NULL;
    }
  free(cmd.main_str);
  return (cmd);
}

t_cmds		split_main_str(t_cmds cmds)
{
  char		**tab;
  int		i;

  i = 0;
  tab = split_wordtab(cmds.main_str);
  while (tab[i])
    {
      cmds.cmd[i].main_str = strdup(tab[i]);
      cmds.cmd[i] = parse_simple_cmd(cmds.cmd[i]);
      i++;
    }
  cmds.cmd[i].main_str = NULL;
  cmds.controleur = add_controlleur(cmds.main_str);
  free(tab[0]);
  free(tab);
  return (cmds);
}
