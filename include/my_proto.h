/*
** my_proto.h for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/include/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Wed Jun  1 16:55:51 2016 Alexis Moisson
** Last update Sun Jun  5 20:38:53 2016 Alexis Moisson
*/

#ifndef MY_PROTO_H_
# define MY_PROTO_H_

# ifndef LIB_PROTO
#  define LIB_PROTO

char	**wordtab(char **tab, int i);
int	len_controler(char *str);
char	**split_wordtab(char *str);
void	my_putchar_error(char c);
void	my_putstr_error(char *str);
void	my_putnbr_error(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putnbr(int nbr);
int     my_getnbr(char *str);
int	len_wordtab(char *str, char key);
char    *my_epurstr(char *str);
char	**str_to_wordtab(char *str, char key);
char	*new_line(char *str, char c);
char	*get_next_line(const int fd);
int	my_isnum(char *str);

# endif /* !LIB_PROTO */

# ifndef MAIN_PROTO
#  define MAIN_PROTO

int	process(t_cmds cmd, char ***env);
int	check_builtins(t_cmd cmd, char ***env);
int	execute_cmd(t_cmd cmd, char ***env);
int	check_redirections(t_cmd cmd);
char	*get_param(char **env, char *param);
int	main_process(t_cmds *cmd_tab, char ***env);
void	my_put_prompt(char **env);
t_cmd	*tab_to_strut(char **tab, char *str);
int	execute_builtins(char ***env, t_cmd cmd_tab);

# endif /* !MAIN_PROTO */

# ifndef REDIR_PROTO
#  define REDIR_PROTO

int		redir_right_str(char **cmd, char *name_file);
int		dble_redir_right_str(char **cmd, char *name_file);
int		redir_left(char **cmd, char *name_file);
void		dble_redir_left_str(void);
void		simple_pipe(t_cmd *cmd, char **env);
void		double_pipe(void);

# endif /* !REDIR_PROTO */

# ifndef SYSCALL_PROTO
#  define SYSCALL_PROTO

char	*add_exec_to_path(char *path, char *exec);
char	*check_executable(char **exec);
int	exec(char **cmd);
void	check_segfault(int statut);

#endif /* !SYSCALL_PROTO */

# ifndef BUILTINS_PROTO
#  define BUILTINS_PROTO

int	all_unsetenv(char **cmd, char ***env);
char	*concat(char *src, char *src2, char a);
char	**cpy_env(char **env);
void	put_env(char **env, char *pwd, char *param);
void	switch_pwd(char **env);
void	manage_pwd(char **env);
int	condi_cd(char **env, char **cmd);
int	tab_len(char **tab);
int	my_unsetenv(char **cmd, char ***env);
int	my_setenv(char **cmd, char ***env);
int	cd(char **cmd);
int	echo(char **cmd);
int	my_exit(char **cmd_tab);

# endif /* BUILTINS_PROTO */

# ifndef PARSING_PROTO
#  define PARSING_PROTO

int		count_controleur(char *str);
int		check_controleur(char *str);
char		**add_controlleur(char *str);
t_cmd		parse_simple_cmd(t_cmd cmd);
t_cmds		split_main_str(t_cmds cmds);
char		*get_file(char *str, int i);
t_cmd		init_struct_cmd();
t_cmds		init_struct_cmds(int nbr_cmds);
int		count_cmd(char	*str);
t_cmds		*start_parsing(char *str);
t_cmds		*main_parsing(char *str);

# endif  /* PARSING_PROTO */

#endif /* !MY_PROTO_H_ */
