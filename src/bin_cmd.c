/*
** EPITECH PROJECT, 2022
** bin_cmd.c
** File description:
** bin commands
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <dirent.h>
#include "minishell.h"

static void check_segfault(int ret)
{
    if (WIFSIGNALED(ret) != 0) {
        if ((WTERMSIG(ret) == 11) && (__WCOREDUMP(ret) == 0))
            my_perror(SEGFAULT);
        else if ((WTERMSIG(ret) == 11) && (__WCOREDUMP(ret) != 0))
            my_perror(SEGFAULT_DUMPED);
    }
}

static char **create_env(list_t **ms)
{
    char **env;
    list_t *tmp = (*ms);
    int len = 0;
    int i = 0;

    for (; tmp; tmp = tmp->next)
        len++;
    tmp = (*ms);
    env = malloc(sizeof(char *) * (len + 1));
    for (; tmp; tmp = tmp->next, i++)
        env[i] = my_strdup(tmp->line);
    env[i] = NULL;
    return (env);
}

static void exec_cmd(list_t **ms, char *exec_cmd, char **cmd)
{
    pid_t cpid;
    pid_t chpid;
    cpid = fork();
    int ret = 0;
    char **env = create_env(ms);

    if (cpid == 0)
        execve(exec_cmd, cmd, env) != -1 ? exit(SUCCESS) : 0;
    else if (cpid > 0)
        ((chpid = wait(&ret)) < 0) ? my_perror("wait"), exit(SUCCESS) : 0;
    check_segfault(ret);
    my_free_array(env);
}

static int launch_bin(list_t **ms, exec_t *ex, int i, DIR *path)
{
    struct dirent *file;

    while ((file = readdir(path)))
        if (!my_strcmp(file->d_name, ex->cmd[0])) {
            ex->execp = my_strcat(ex->paths[i], "/");
            ex->execp2 = my_strcat(ex->execp, file->d_name);
            my_free_array(ex->paths);
            exec_cmd(ms, ex->execp2, ex->cmd);
            free(ex->execp);
            free(ex->execp2);
            return (SUCCESS);
        }
    return (ERROR);
}

int bin_cmd(char *cmd_tmp, list_t **ms)
{
    exec_t *ex = malloc(sizeof(exec_t));
    ex->cmd = my_str_to_array(cmd_tmp, " \t\v\f\r");
    ex->ipath = search_index(ms, "PATH=");
    ex->paths = my_str_to_array(ex->ipath, ":");
    DIR *path;

    for (int i = 0; ex->paths[i]; i++) {
        path = opendir(ex->paths[i]);
            if (path && !launch_bin(ms, ex, i, path)) {
                free_ex(ex);
                closedir(path);
                return (SUCCESS);
            }
        closedir(path);
    }
    my_printf(CMD_NOT_FOUND, ex->cmd[0]);
    my_free_array(ex->paths);
    free_ex(ex);
    return (ERROR);
}
