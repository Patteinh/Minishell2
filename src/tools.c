/*
** EPITECH PROJECT, 2022
** set_create.c
** File description:
** set and create tools
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"

void print_env(list_t **ms)
{
    list_t *tmp = (*ms);

    for (; tmp; tmp = tmp->next)
        my_printf("%s\n", tmp->line);
}

int is_cmd_exist(char *index, list_t **ms)
{
    list_t *tmp = (*ms);

    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index)))
            return (EXIST);
    return (NOT_EXIST);
}

char *search_index(list_t **ms, char *index)
{
    list_t *tmp = (*ms);

    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index)))
            return (&tmp->line[my_strlen(index)]);
    return (NULL);
}

void free_ex(exec_t *ex)
{
    my_free_array(ex->cmd);
    free(ex);
}
