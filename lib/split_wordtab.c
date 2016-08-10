/*
** split_wordtab.c for PSU in /home/illi_j/rendu/PSU/PSU_2015_42sh/lib/
**
** Made by Johnatan Illi
** Login   <illi_j@epitech.eu>
**
** Started on  Thu Jun  2 19:26:49 2016 Johnatan Illi
** Last update Sun Jun  5 20:38:46 2016 Alexis Moisson
*/

#include "mysh.h"

int	len_controler(char *str)
{
  int	i;
  int	key;

  i = 0;
  key = 0;
  while (str[i])
    {
      if ((str[i] == '&' && str[i + 1] == '&') ||
	  (str[i] == '|' && str[i + 1] == '|'))
	key = key + 1;
      i = i + 1;
    }
  return (key + 1);
}

char	**wordtab(char **tab, int i)
{
  if (strcmp(tab[i - 1], "\0") == 0)
    tab[i - 1] = NULL;
  tab[i] = NULL;
  return (tab);
}

char	**split_wordtab(char *str)
{
  char	**tab;
  char	*newstr;
  int	line;
  int	i;

  i = 1;
  newstr = strdup(str);
  line = len_controler(newstr);
  if ((tab = malloc(sizeof(char *) * (line + 2))) == NULL)
    exit(1);
  tab[0] = newstr;
  while (i < line)
    {
      if ((*newstr == '&' && newstr[1] == '&') ||
	  (*newstr == '|' && newstr[1] == '|'))
	{
	  *newstr = 0;
	  newstr += 2;
	  if (*newstr == ' ')
	    newstr++;
	  tab[i++] = newstr;
	}
      newstr++;
    }
  return (wordtab(tab, i));
}
