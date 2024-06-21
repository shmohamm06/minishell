#include "lexer.h"


int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd)
{
	static void	*builtins[7][2] = {
	{"echo", mini_echo},
	{"cd", mini_cd},
	{"pwd", mini_pwd},
	{"export", mini_export},
	{"unset", mini_unset},
	{"env", mini_env},
	{"exit", mini_exit}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}

void mini_echo(t_tools *tools, t_simple_cmds *simple_cmd) {
    // No operation (NOP)
    (void)tools; // This avoids unused parameter warnings
    (void)simple_cmd;
}

// Stub implementation for mini_cd
void mini_cd(t_tools *tools, t_simple_cmds *simple_cmd) {
    // NOP
    (void)tools;
    (void)simple_cmd;
}

// Stub implementation for mini_pwd
void mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd) {
    // NOP
    (void)tools;
    (void)simple_cmd;
}

// Stub implementation for mini_export
void mini_export(t_tools *tools, t_simple_cmds *simple_cmd) {
    // NOP
    (void)tools;
    (void)simple_cmd;
}

// Stub implementation for mini_exit
void mini_exit(t_tools *tools, t_simple_cmds *simple_cmd) {
    // NOP
    (void)tools;
    (void)simple_cmd;
}  


// Stub implementation for mini_unset
void mini_unset(t_tools *tools, t_simple_cmds *simple_cmd) {
    // NOP
    (void)tools;
    (void)simple_cmd;
}

// Stub implementation for mini_env
void mini_env(t_tools *tools, t_simple_cmds *simple_cmd) {

    (void)tools;
    (void)simple_cmd;
}