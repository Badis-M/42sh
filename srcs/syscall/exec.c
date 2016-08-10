/*
** exec.c for PSU in /home/illi_j/rendu/PSU/PSU_2015_42sh/srcs/
**
** Made by Johnatan Illi
** Login   <illi_j@epitech.eu>
**
** Started on  Tue May 31 11:46:03 2016 Johnatan Illi
** Last update Sun Jun  5 17:49:55 2016 Johnatan Illi
*/

#include "mysh.h"

char	*add_exec_to_path(char *path, char *exec)
{
  int	i;
  int	j;
  int	len;
  char	*str;

  i = 0;
  j = 0;
  len = strlen(path) + strlen(exec);
  if ((str = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  while (path[i])
    {
      str[i] = path[i];
      i++;
    }
  str[i] = '/';
  i++;
  while (exec[j])
    {
      str[i] = exec[j];
      i++;
      j++;
    }
  str[i] = 0;
  return (str);
}

char	*check_executable(char **exec)
{
  int	i;
  char	*str;
  char	*gpath;
  char	**path;

  i = 0;
  if (access(exec[0], X_OK) != 0)
    {
      if ((str = get_param(my_env, "PATH=")) == NULL)
	str = "/bin";
      path = str_to_wordtab(str, ':');
      if ((strncmp(exec[0], "./", 2)) == 0 || strncmp(exec[0], "/", 1) == 0)
	return (exec[0]);
      while (path[i])
	{
	  gpath = add_exec_to_path(path[i], exec[0]);
	  if (access(gpath, X_OK) == 0)
	    return (gpath);
	  i++;
	}
    }
  else
    return (exec[0]);
  return (NULL);
}

int	exec(char **cmd)
{
  int	execv;
  pid_t	pid;
  char	*exec;

  if ((exec = check_executable(cmd)) == NULL)
    return (-1);
  if (exec != NULL)
    {
      pid = fork();
      if (pid == 0)
	{
	  if ((execv = execve(exec, cmd, my_env)) == -1)
	    exit(EXIT_FAILURE);
	}
      else
	{
	  waitpid(pid, &execv, WUNTRACED);
	  check_segfault(execv);
	  if (WEXITSTATUS(execv) == 1)
	    printf("%s: %s.\n", cmd[0], "Command not found");
	  return (WEXITSTATUS(execv));
	}
    }
  return (-1);
}

void	check_segfault(int statut)
{
  if (WIFSIGNALED(statut))
    {
      if (WTERMSIG(statut) == SIGSEGV)
	fprintf(stderr, "%s\n", strerror(errno));
      if (WTERMSIG(statut) == SIGFPE)
	fprintf(stderr, "%s\n", strerror(errno));
      if (WCOREDUMP(statut))
	fprintf(stderr, "%s\n", strerror(errno));
    }
}
