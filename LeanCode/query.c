#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int lib_ver = PQlibVersion();
    printf("PQlibVersion: %d\n", lib_ver);

    PGconn *conn = PQconnectdb("host=postgres hostaddr=127.0.0.1 port=5432 user=postgres password=11520380 dbname=postgres");
    if (PQstatus(conn) == CONNECTION_BAD) {        
        fprintf(stderr, "Can't connect to Postgres: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        exit(-1);
    }

    PGresult *res = PQexec(conn, "SELECT * FROM student");    
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        printf("\n     %-10s %-10s\n", PQfname(res, 0), PQfname(res, 1));
        printf("-------------------------\n");
        int rows = PQntuples(res);    
        for(int i=0; i<rows; i++) {       
            printf("[%d]: %-10s %-10s\n", i, PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
        }   
    }       
    PQclear(res);
    PQfinish(conn);
    return 0;
}