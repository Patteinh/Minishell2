/*
** EPITECH PROJECT, 2022
** minishell.h
** File description:
** minishell.h
*/

#include "my.h"

#ifndef _MINISHELL_H_
    #define _MINISHELL_H_

    #define PROMPT ">"
    #define ALL_CMD "exit;cd;env;unsetenv;setenv"
    #define CMD_NOT_FOUND "%e: Command not found.\n"
    #define NO_F "No such file or directory."
    #define NO_DIR "Not a directory."
    #define ENV_ERROR "env : Too many arguments\n"
    #define UNSETENV_ERROR "unsetenv: Too few arguments.\n"
    #define SETENV_ERROR "setenv: Too many arguments\n"
    #define SEGFAULT "Segmentation fault\n"
    #define SEGFAULT_DUMPED "Segmentation fault (core dumped)\n"

    #define NB_CMD 5
    #define EXIST 0
    #define NOT_EXIST 1
    #define SUCCESS 0
    #define ERROR 1
    #define EXIT_ERROR 84
    #define VALID 0
    #define INVALID 1
    #define EXIT 2

typedef struct exec_s {
    char *ipath;
    char *execp;
    char *execp2;
    char **paths;
    char **cmd;
} exec_t;

void print_env(list_t **ms);
int  is_cmd_exist(char *index, list_t **ms);
char *search_index(list_t **ms, char *index);
int  choice_cmd(char *buffer, list_t **ms);
int  my_cmd(char *cmd_tmp, list_t **ms);
int  bin_cmd(char *cmd_tmp, list_t **ms);
int  my_exit(char **cmd, list_t **ms);
int  my_cd(char **cmd, list_t **ms);
int  my_env(char **cmd, list_t **ms);
int  my_unsetenv(char **cmd, list_t **ms);
int  my_setenv(char **cmd, list_t **ms);
void free_ex(exec_t *ex);

static int (*const MY_CMD[])(char **cmd, list_t **ms) =
{my_exit, my_cd, my_env, my_unsetenv, my_setenv};

#endif
