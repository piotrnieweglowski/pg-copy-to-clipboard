#include <stdio.h>
#include <stdlib.h>
#include "query_executor.h"
#include "clipboard.h"
#include "config_reader.h"

int main() 
{
    const char* value;
    Config* cfg = ReadConfiguration("app.cfg");
    OpenConnection(cfg->connectionString);
    value = Execute(cfg->query);
    CloseConnection();
    SetClipboardText(value);
    printf("%s", value);
    free(cfg);
    exit(EXIT_SUCCESS);
}