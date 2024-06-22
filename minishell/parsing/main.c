#include "lexer.h"


void	print_lexer_list(t_lexer *list)
{
	while (list)
	{
		if (list->str != NULL)
		{
			printf("Token: %d, Str: %s\n", list->token, list->str);
		}
		else
		{
			printf("Token: %d, Str: NULL\n", list->token);
		}
		list = list->next;
	}
}


void print_commands(t_simple_cmds *cmds)
{
    while (cmds)
    {
        printf("Command: %s\n", cmds->str[0]);  // Print the command
        for (int i = 1; cmds->str[i] != NULL; i++)
            printf("  Arg %d: %s\n", i, cmds->str[i]);  // Print arguments

        if (cmds->builtin)
            printf("  This is a built-in function.\n");
        else
            printf("  This is not a built-in function.\n");

        printf("  Redirections: %d\n", cmds->num_redirections);
        t_lexer *redir = cmds->redirections;
        while (redir)
        {
            printf("    Redir Token: %d, File: %s\n", redir->token, redir->str);
            redir = redir->next;
        }
        cmds = cmds->next;
    }
}

int main(void)
{
    t_tools tools;
    char *input = "echo 'Hello, World!' >   output.txt";  // Static input for testing

    tools.lexer_list = NULL;
    tools.simple_cmds = NULL;
    tools.args = input;

    if (!token_reader(&tools)) {
        printf("Lexer encountered an error.\n");
        return 1;
    }

    printf("Lexer Output:\n");
    print_lexer_list(tools.lexer_list);

    if (parser(&tools) != EXIT_SUCCESS) {
        printf("Parser encountered an error.\n");
        return 1;
    }

    printf("Parsed Commands:\n");
    print_commands(tools.simple_cmds);

    ft_lexerclear(&tools.lexer_list);  // Clean up the lexer list
    ft_simple_cmdsclear(&tools.simple_cmds);  // Clean up the command structures

    return 0;
}
