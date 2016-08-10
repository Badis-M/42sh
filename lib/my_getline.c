/*
** my_getline.c for lib in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/lib/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Mon May 30 15:16:38 2016 Alexis Moisson
** Last update Tue May 31 16:15:04 2016 Johnatan Illi
*/

#include "mysh.h"

char	*new_line(char *str, char c)
{
  char	*newstr;
  int	i;

  i = 0;
  if ((newstr = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i])
    {
      newstr[i] = str[i];
      i++;
    }
  newstr[i++] = c;
  newstr[i] = 0;
  free(str);
  return (newstr);
}

char	*get_next_line(const int fd)
{
  int	i;
  int	len;
  char	c;
  char	*line;

  len = 0;
  i = 1;
  if ((line = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  line[0] = 0;
  while (i)
    {
      if ((i = read(fd, &c, 1)) == -1)
	return (NULL);
      len = len + 1;
      if (i == 0)
	return (NULL);
      if (len == 1 && c == '\n')
	return (line);
      else if (c == '\n' || c == '\0')
	return (line);
      if ((line = new_line(line, c)) == NULL)
	return (NULL);
    }
  return (NULL);
}
