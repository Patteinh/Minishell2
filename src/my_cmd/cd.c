/*
** EPITECH PROJECT, 2022
** my_cd.c
** File description:
** my cd cmd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "minishell.h"

static void change(list_t **ms, char *new, char *index)
{
    list_t *tmp = (*ms);

    for (; tmp; tmp = tmp->next)
        if (!my_strncmp(tmp->line, index, my_strlen(index))) {
            free(tmp->line);
            tmp->line = NULL;
            tmp->line = my_strdup(new);
        }
    free(new);
}

static int error_gestion_cd(char *path)
{
    int r = 0;
    access(path, F_OK) == -1 ? my_printf("%e: %e\n", path, NO_F), r = 1 : 0;
    chdir(path) == -1 ? my_printf("%e: %e\n", path, NO_DIR), r = 1 : 0;
    free(path);
    return ((r == 0) ? (VALID) : (INVALID));
}

static int change_env_cd(list_t **ms, char *pwd)
{
    int len_pwd = my_strlen(search_index(ms, "PWD=")) + 1;
    char *buffer = malloc(sizeof(char) * (len_pwd));

    getcwd(buffer, len_pwd);
    if (search_index(ms, pwd))
        change(ms, my_strcat(pwd, buffer), pwd);
    free(buffer);
    return (VALID);
}

static int check_opt(char *cmd, char **path, list_t **ms)
{
    (*path) = (!cmd || !my_strcmp(cmd, "~")) ?
    my_strdup(search_index(ms, "HOME=")) : my_strdup(cmd);
    return (!(*path) ? (ERROR) : (SUCCESS));
}

int my_cd(char **cmd, list_t **ms)
{
    char *path;

    if (check_opt(cmd[1], &path, ms))
        return (INVALID);
    if (error_gestion_cd(path))
        return (VALID);
    return (change_env_cd(ms, "PWD="));
}
