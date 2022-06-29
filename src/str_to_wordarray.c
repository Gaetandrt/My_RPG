/*
** EPITECH PROJECT, 2022
** strtowordarray
** File description:
** rpg
*/

#include "source.h"

char *readfile(char *filepath)
{
    struct stat sb;
    const char *filename = filepath;
    FILE *myfile = fopen(filename, "r");
    if (!myfile)
        exit(EXIT_FAILURE);
    if (stat(filename, &sb) == -1)
        exit(84);
    char *filecontent = malloc(sb.st_size);
    fread(filecontent, sb.st_size, 1, myfile);
    return filecontent;
}

void printab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

int nb_carac(char *str, char delim)
{
    int space = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == delim) {
            space++;
        }
    }
    return (space);
}

char **allocate(char *str, char delim)
{
    int i = 0;
    char **tabstr = malloc((nb_carac(str, delim) + 2) * sizeof(char *));

    while (i < nb_carac(str, delim) + 2) {
        tabstr[i] = malloc((my_strlen(str) + 1) * sizeof(char));
        i++;
    }
    return (tabstr);
}

char **my_str_to_word_array(char *mystr, char delim)
{
    char *str = readfile(mystr);
    char **tabstr = allocate(str, delim);
    int i = 0;
    int a = 0;
    int b = 0;

    while (str[i] != '\0') {
        if (str[i] == delim) {
            tabstr[a][b] = '\0';
            b = 0;
            a++;
            i++;
        }
        tabstr[a][b] = str[i];
        i++;
        b++;
    }
    tabstr[a][b] = '\0';
    tabstr[a] = NULL;

    return (tabstr);
}
