/*
** EPITECH PROJECT, 2022
** choice_cmd.c
** File description:
** choice commands
*/

#include <stddef.h>
#include "minishell.h"

static int check_spaces_tabs(char **cmd, char **all)
{
    if (cmd[0] == NULL || !my_strcmp(cmd[0], " ") ||
    !my_strcmp(cmd[0], "\t") || !my_strcmp(cmd[0], "\0")) {
        my_free_array(all);
        my_free_array(cmd);
        return (ERROR);
    }
    return (SUCCESS);
}

int my_cmd(char *cmd_tmp, list_t **ms)
{
    char **all = my_str_to_array(ALL_CMD, ";");
    int idx = 0;
    int ret;
    char **cmd = my_str_to_array(cmd_tmp, " \t");

    if (check_spaces_tabs(cmd, all))
        return (ERROR);
    for (; idx != NB_CMD; idx++)
        if (!my_strcmp(cmd[0], all[idx]))
            break;
    ret = (idx != NB_CMD) ? MY_CMD[idx](cmd, ms) : INVALID;
    my_free_array(all);
    my_free_array(cmd);
    return (ret);
}
