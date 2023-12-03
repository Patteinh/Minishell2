/*
** EPITECH PROJECT, 2022
** cmd.c
** File description:
** commands for minishell
*/

#include <stdlib.h>
#include <stddef.h>
#include "minishell.h"

static void free_all(char **all_cmd, char *line)
{
    my_free_array(all_cmd);
    free(line);
}

int choice_cmd(char *buffer, list_t **ms)
{
    int ret = 0;
    char *line = my_clean_str(buffer, "\n");
    char **all_cmd = my_str_to_array(line, ";|");

    for (int i = 0; all_cmd[i]; i++) {
        ret = my_cmd(all_cmd[i], ms);
        ret == INVALID ? bin_cmd(all_cmd[i], ms) : 0;
        if (ret == EXIT)
            break;
    }
    free_all(all_cmd, line);
    return (ret);
}
