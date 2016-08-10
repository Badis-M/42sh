/*
** str_to_wordtab.c for PSU in /home/illi_j/rendu/PSU/PSU_2015_42sh/lib
**
** Made by johnatan illi
** Login   <illi_j@epitech.net>
**
** Started on  Mon May 30 15:39:31 2016 johnatan illi
** Last update Sun Jun  5 16:40:57 2016 Alexis Moisson
*/

#include "mysh.h"

int	len_wordtab(char *str, char key)
{
  int	space;
  int	i;

  space = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == key)
	space = space + 1;
      i = i + 1;
    }
  return (space + 1);
}

char	**str_to_wordtab(char *str, char key)
{
  char	**tab;
  char	*new_str;
  int	line;
  int	i;

  i = 1;
  new_str = strdup(my_epurstr(str));
  line = len_wordtab(new_str, key);
  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  tab[0] = new_str;
  while (i < line)
    {
      if (*new_str == key)
	{
	  *new_str = 0;
	  new_str++;
	  tab[i++] = new_str;
	}
      new_str++;
    }
  if (strcmp(tab[i - 1], "\0") == 0)
    tab[i - 1] = NULL;
  tab[i] = NULL;
  return (tab);
}
