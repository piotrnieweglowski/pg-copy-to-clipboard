typedef struct config {
    char* connectionString;
    char* query;
} Config;

Config* ReadConfiguration(const char* filePath);