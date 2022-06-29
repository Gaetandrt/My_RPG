/*
** EPITECH PROJECT, 2022
** my
** File description:
** strlen
*/

#include "source.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
