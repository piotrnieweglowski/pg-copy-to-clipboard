#include "config_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Config* ReadConfiguration(const char* filePath)
{
    Config* cfg = malloc(sizeof(Config));
    FILE* filePointer;
    int bufferLength = 500;
    char buffer[bufferLength];
    filePointer = fopen(filePath, "r");
    while(fgets(buffer, bufferLength, filePointer)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (buffer[0] == '#')
            continue;
        if (strstr(buffer, "SELECT") != NULL)
            cfg->query = strdup(buffer);
        if (strstr(buffer, "dbname=") != NULL)
            cfg->connectionString = strdup(buffer);
    }

    fclose(filePointer);
    return cfg;
}