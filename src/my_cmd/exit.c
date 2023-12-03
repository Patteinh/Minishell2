/*
** EPITECH PROJECT, 2022
** exit.c
** File description:
** my exit cmd
*/

#include "minishell.h"

int my_exit(char **cmd, list_t **ms)
{
    (void)cmd;
    (void)ms;
    my_putstr("exit\n");
    return (EXIT);
}
