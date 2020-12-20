#include "query_executor.h"
#include "libpq-fe.h"
#include <stdlib.h>

PGconn *connection;

void OpenConnection(const char* connectionString)
{
    connection = PQconnectdb(connectionString);
    if (PQstatus(connection) == CONNECTION_BAD) {
        printf("Cannot establish connection\n");
        exit(EXIT_FAILURE);
    }
}

const char* Execute(const char* query)
{
    if (!connection) {
        printf("Connection is not open\n");
        exit(EXIT_FAILURE);
    }

    PGresult *result = PQexec(connection, query);
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        printf("Couldn't fetch data\n");
        exit(EXIT_FAILURE);
    }

    const char* value = PQgetvalue(result, 0, 0);
    PQclear(result);
    return value;
}

void CloseConnection()
{
    PQfinish(connection);
}