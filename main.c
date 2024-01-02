/*
    A Simple SDDM Theme Switcher
    
    Written By: Drew Bornt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

    // Checks the args count
    if (argc != 2)
    {
        printf("Usage: ./simplethemeswitcher <\"theme name\">\n");
        return 1;
    }

    // Gets the current logged-in user's home directory
    FILE *originalSettingsFP, *newSettingsFP;
    char *originalSettingsFileName = "/etc/sddm.conf.d/default.conf";
    char *tempSettingsFileName = "/etc/sddm.conf.d/temp.txt";

    originalSettingsFP = fopen(originalSettingsFileName, "r");
    if (!originalSettingsFP)
    {
        printf("Failed to open settings file.\n Does this have read permissions?\n");
        return 1; //unsuccessful execution
    }

    newSettingsFP = fopen(tempSettingsFileName, "w");
    if (!newSettingsFP)
    {
        printf("Error writing to a new config file.\n Does this have write permissions?\n");
        return 1; //unsuccessful execution
    }

    // Takes the theme name from the commandline input
    char themeName[65];
    strncpy(themeName, argv[1], sizeof(themeName) - 1);
    themeName[sizeof(themeName) - 1] = '\0';

    // Set up a buffer for fgets
    char lineBuffer[256];

    // Sets the line we need to append in the theme file
    char lineToAdd[128];
    snprintf(lineToAdd, sizeof(lineToAdd), "Current=%s", themeName);

    // Loop through each line of the original file
    while (fgets(lineBuffer, sizeof(lineBuffer), originalSettingsFP) != NULL)
    {
        // If the line starts with this, we write to the new settings file the line with the new theme
        if (strncmp(lineBuffer, "Current=", 7) == 0)
        {
            fprintf(newSettingsFP, lineToAdd);
        }
        // If the line doesn't match that, we don't want to change the line
        else
        {
            fputs(lineBuffer, newSettingsFP);
        }
    }
    
    fclose(newSettingsFP);
    fclose(originalSettingsFP);
    
    char originalSettingsFileNameBackup[1024];
    snprintf(originalSettingsFileNameBackup, sizeof(originalSettingsFileName), "%s.bak", originalSettingsFileName);

    // Delete the original file
    rename(originalSettingsFileName, originalSettingsFileNameBackup);
    // Rename the new file to match the old
    rename(tempSettingsFileName, originalSettingsFileName);
    
    return 0; // successful execution

}