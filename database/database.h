#ifndef DATABASE_H
#define DATABASE_H

// #ifdef __cplusplus
// extern "C"
// {
// #endif

#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ThuVienVN/tuioxyz_struct.h"


//---------------------------
static char *conninfo =(char*)"host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=11520380 dbname=DB1kytu";
static PGconn *conn;
static PGresult *res;
static oxyz1c result;





//---------------------------------------------------
static void exit_nicely(PGconn *conn){

    PQfinish(conn);
    //exit(1);
};

oxyz1c *getOneChar(char *conninfo)
{
    int nFields;
    int i, j;

    conn = PQconnectdb(conninfo);
    res = PQexec(conn, "SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" = 5;");

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

        // for (i = 0; i < PQntuples(res); i++)
        // {
        //     for (j = 0; j < nFields; j++)
        //         printf("%-15s", PQgetvalue(res, i, j));
        //     printf("\n");
        // };


        result.id_Logic=(int64_t)PQgetvalue(res,0,0);
        result.value = (char)PQgetvalue(res,0,1);
        result.x = (int64_t)PQgetvalue(res,0,2);
        result.y = (int64_t)PQgetvalue(res,0,3);
        result.z = (int64_t)PQgetvalue(res,0,4);



        return &result;

        //PQclear(res);
    };

    //PQfinish(conn);
    //return res;
}







// #ifdef __cplusplus
// }
// #endif


#endif