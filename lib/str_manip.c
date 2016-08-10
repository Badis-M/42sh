/*
** str_manip.c for lib in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/lib/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Mon May 30 15:16:19 2016 Alexis Moisson
** Last update Sun Jun  5 23:43:40 2016 Badis Merakchi
*/

#include "mysh.h"

char	*my_epurstr(char *str)
{
  int   i;
  int   space;
  char  *newstr;

  i = 0;
  space = 0;
  if ((newstr = malloc(sizeof(char) * strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	newstr[space++] = str[i++];
      else if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i = i + 1;
	  if (str[i] != '\0')
	    newstr[space++] = ' ';
	}
    }
  newstr[space] = 0;
  return (newstr);
}

int		my_getnbr(char *str)
{
  int           len;
  long long int nbr;
  long long int power;
  short int     neg;

  power = 1;
  nbr = 0;
  neg = 1;
  if (str[0] == '-')
    {
      str++;
      neg = -1;
    }
  len = strlen(str) - 1;
  while (len >= 0)
    {
      if (str[len] < '0' || str[len] > '9')
	return (0);
      nbr = nbr + ((str[len] - '0') * power);
      power = power * 10;
      len--;
    }
  return (nbr * neg);
}

int	my_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '-' && str[i + 1] != '\0')
    i++;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

char	*concat(char *src, char *src2, char a)
{
  char	*str;
  int	i;
  int	j;

  str = malloc(sizeof(char) * (strlen(src) + (strlen(src2) + 2)));
  if (str == NULL)
    exit(-1);
  i = 0;
  j = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = a;
  i++;
  while (src2[j] != '\0')
    {
      str[i] = src2[j];
      j++;
      i++;
    }
  str[i] = '\0';
  return (str);
}
