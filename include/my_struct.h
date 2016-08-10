/*
** my_struct.h for 42sh in /home/alexis/Documents/Epitech/Semestre2/PSU/PSU_2015_42sh/include/
**
** Made by Alexis Moisson
** Login   <moisso_a@epitech.eu>
**
** Started on  Tue May 31 11:58:48 2016 Alexis Moisson
** Last update Sun Jun  5 20:21:50 2016 Alexis Moisson
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

typedef struct		s_redir
{
  int			file;
  char			*name_file;
  char			*write_file;
  char			*cmd;
}			t_redir;

typedef struct	s_cmd
{
  char		**cmd_tab;
  char		*input_file;
  char		*output_file;
  char		*double_file;
  char		*main_str;
}		t_cmd;

typedef struct	s_cmds
{
  t_cmd		*cmd;
  char		**controleur;
  char		*main_str;
}		t_cmds;

typedef struct	s_env
{
  char		*path;
  char		**stw_path;
  char		*cat_path;
  char		*oldpwd;
  char		*home;
  char		*user;

}		t_env;

#endif /* !MY_STRUCT_H_ */
