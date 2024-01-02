/*
    A Simple GTK Theme Switcher
    
    Written By: Drew Bornt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileExists();

int main(int argc, char* argv[])
{
    const char *homedir = getenv("HOME");

    char filePath[1024];

    snprintf(filePath, sizeof(filePath), "%s/.config/gtk-3.0/settings.ini", homedir);

    printf("%s\n", filePath);

    if (fileExists(filePath) == 1)
    {
        printf("File opened successfully\n");
    }

    return 1;

}

int fileExists(char* filePath)
{
    FILE *file;

    if ((file = fopen(filePath, "r")))
    {
        fclose(file);
        return 1;
    }

    return 0;
}