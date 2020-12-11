#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char query_string[256];
    PGconn *conn;
    PGresult *res;
    int i;
    printf("Start");

    conn = PQconnectdb("dbname = postgres host = 127.0.0.1:49902 port = 5432 user = postgres password = 11520380");
    if(PQstatus(conn)==CONNECTION_BAD){
        printf("Ko ket noi dc vs database");
        printf(PQerrorMessage(conn));
        exit(1);
    };

    res = PQexec(conn,query_string);
    if(PQresultStatus(res)!=PGRES_TUPLES_OK){
        printf("Chon query sai");
        PQclear(res);
        PQfinish(conn);
        exit(1);
    };

    for(i=0;i<PQntuples(res);i++){
        printf("%s",PQgetvalue(res,i,0));
        PQclear(res);
        PQfinish(conn);
        return 0;
    };
}