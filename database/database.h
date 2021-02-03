#ifndef DATABASE_H
#define DATABASE_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//---------------------------
static char *conninfo ="host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=11520380 dbname=DB1kytu";
static PGconn *conn;
static PGresult *res;






//---------------------------------------------------
static void exit_nicely(PGconn *conn){

    PQfinish(conn);
    //exit(1);
};

void getOneChar(char *conninfo)
{
    int nFields;
    int i, j;

    conn = PQconnectdb(conninfo);

    if (PQstatus(conn)!=CONNECTION_OK){

        fprintf(stderr,"Connection to database failed: %s",PQerrorMessage(conn));
        exit_nicely(conn);
    }else
    {
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
        //PQclear(res);
    };

    PQfinish(conn);
    //return res;
}







#ifdef __cplusplus
}
#endif


#endif