/*
** EPITECH PROJECT, 2022
** env.c
** File description:
** my env cmd
*/

#include <stddef.h>
#include <stddef.h>
#include "minishell.h"

int my_env(char **cmd, list_t **ms)
{
    cmd[1] ? my_putstr(ENV_ERROR) : print_env(ms);
    return (VALID);
}
