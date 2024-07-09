#include "../minishell.h"
#include "built_ins/built_ins.h"
#include "execution/execution.h"

void take_input(t_mini *mini)
{
    init_signals(); // Initialize signals once
    g_exit_code = -1; // Initialize to prompt state

    while (1)
    { 
        // g_exit_code = -1;
        mini->rl = readline("➜  src ✗  "); // Simplified prompt for clarity
        // if(g_exit_code == 22)
        //     mini->rl = readline("➜  src ✗  "); // Simplified prompt for clarity
        if (mini->rl == NULL)
            exit_shell(mini, 0, "exit", 1);
        if (mini->rl[0] != '\0')
            add_history(mini->rl);
        ft_tokenize(mini);
        if (mini->token)
            parse_tokens(mini, mini->token);
        if (mini->l_cmd)
        {
            g_exit_code = 2;  // Indicate that a command is being processed
            parse_user_input(mini);
            g_exit_code = -1;  // Reset the command state after processing
        }
        free_mini_cycle(mini);
    }
}

int main(int argc, char **argv, char **envp)
{
    t_mini mini;

    (void)argc;
    (void)argv;
    ft_bzero(&mini, sizeof(t_mini));
    ft_parse_env(&mini, (const char **)envp);
    take_input(&mini);

    return 0;
}
