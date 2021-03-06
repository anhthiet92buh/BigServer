#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
#endif
static void exit_nicely(PGconn *conn){

    PQfinish(conn);
    //exit(1);
};

int main(int argc, char const *argv[])
{
    const char *conninfo;
    PGconn *conn;
    PGresult *res;
    int nFields;
    int i, j;
    char a[100];

    scanf("%s",a);
    printf("%s\n",a);

    printf("Bat dau khai bao xong\n");

    if (argc>1)
    {
        conninfo = argv[1];
    }else
    {
        conninfo = "host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=DB1kytu";
    };

    printf("Gan dia chi conninfo xong\n");

    conn = PQconnectdb(conninfo);

    if (PQstatus(conn)!=CONNECTION_OK)
    {
        fprintf(stderr,"Connection to database failed: %s",PQerrorMessage(conn));
        exit_nicely(conn);
    };
    printf("Kiem tra connect xong\n");

    res = PQexec(conn, "SELECT pg_catalog.set_config('search_path', '', false)");

    if ( PQresultStatus(res) != PGRES_TUPLES_OK )
    {
        fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    };
    printf("SELECT pg_catalog.set_config xong\n");

    PQclear(res);

    res = PQexec(conn, "BEGIN");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    };
    PQclear(res);
    printf("Bat dau connect xong \n");

    // res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from pg_database");
    // if (PQresultStatus(res) != PGRES_COMMAND_OK)
    // {
    //     fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
    //     PQclear(res);
    //     exit_nicely(conn);
    // };
    // PQclear(res);

    //res = PQexec(conn, "FETCH ALL in myportal");
    //char t[50]="SELECT "idBigLogic", value, x, y, z FROM public.oxyz1c where "idBigLogic" = 5;";
    // char *chr;
    // strcat(chr,
    res = PQexec(conn, "SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" = 5;");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    };

    nFields = PQnfields(res);
    printf("%d\n",nFields);
    for (i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");

    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    };
    PQclear(res);


    res = PQexec(conn, "CLOSE myportal");
    PQclear(res);

    res = PQexec(conn, "END");
    PQclear(res);

    PQfinish(conn);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
