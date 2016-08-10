/*
** get_file.c for 42SH in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/srcs/parsing/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Sat Jun  4 15:18:45 2016 Alexis Moisson
** Last update Sun Jun  5 12:06:24 2016 Alexis Moisson
*/

#include "mysh.h"

char		*get_file(char *str, int i)
{
  char		*file;
  int		a;

  a = 0;
  if ((file = malloc(sizeof(char) * (strlen(str) - i + 1))) == NULL)
    return (NULL);
  while (str[i] && str[i] != '|' && str[i] != '<' && str[i] != '>')
    {
      file[a++] = str[i++];
    }
  file[a] = '\0';
  return (file);
}
