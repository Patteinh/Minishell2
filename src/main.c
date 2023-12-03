/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

static int help(void)
{
    my_putstr("Bad usage !\nUSE : ./mysh");
    return (EXIT_ERROR);
}

static int shell(char **env)
{
    list_t *ms = NULL;
    char *buffer = NULL;
    size_t size = 0;

    my_fill_list(&ms, env);
    write(1, &(PROMPT), 1);
    while (getline(&buffer, &size, stdin) != -1) {
        if (choice_cmd(buffer, &ms) == EXIT)
            break;
        write(1, &(PROMPT), 1);
    }
    my_free_list(ms);
    free(buffer);
    return (SUCCESS);
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac == 1)
        return (shell(env));
    return (help());
}
