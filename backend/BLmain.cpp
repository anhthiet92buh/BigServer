#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctime>
#include <wchar.h>
#include <cwchar>
#include <cuchar>
// #include <charconv>
#include <charconv>
#include <string_view>
#include <system_error>
#include <locale>
#include <fstream>
//...........
// #define __STDC_FORMAT_MACROS 1
#include <inttypes.h>

// #include <stdio.h>
#include <unicode/utypes.h>
#include <unicode/uchar.h>
#include <unicode/locid.h>
#include <unicode/ustring.h>
#include <unicode/ucnv.h>
#include <unicode/unistr.h>
#include <unicode/putil.h>
// #include <libpq-int.h>
//...........


using namespace std;

#ifndef UPRV_LENGTHOF
#define UPRV_LENGTHOF(array) (int32_t)(sizeof(array)/sizeof((array)[0]))
#endif


//..................
#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
// #include "/usr/include/postgresql/internal/libpq-int.h"
#endif

//---------------------------
// static char *conninfo =(char*)"host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=DB1kytu";
// const char *conninfo = "host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=DB1kytu";
const char *conninfo = "host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=fulldatabase";
static PGconn *conn;
static PGresult *res;

//Unicode
static UConverter *cnv=NULL;



//..................
static void exit_nicely(PGconn *conn){
    PQfinish(conn);
    //exit(1);
};

//Ham cua unicode
static void printUString(const char *announce, const UChar *s, int32_t length) {
    static char out[200];
    UChar32 c;
    int32_t i;
    UErrorCode errorCode=U_ZERO_ERROR;

    /*
     * Convert to the "platform encoding". See notes in printUnicodeString().
     * ucnv_fromUChars(), like most ICU APIs understands length==-1
     * to mean that the string is NUL-terminated.
     */
    ucnv_fromUChars(cnv, out, sizeof(out), s, length, &errorCode);
    if(U_FAILURE(errorCode) || errorCode==U_STRING_NOT_TERMINATED_WARNING) {
        printf("%sproblem converting string from Unicode: %s\n", announce, u_errorName(errorCode));
        return;
    }

    printf("%s%s {", announce, out);

    /* output the code points (not code units) */
    if(length>=0) {
        /* s is not NUL-terminated */
        for(i=0; i<length; /* U16_NEXT post-increments */) {
            U16_NEXT(s, i, length, c);
            printf(" %04x", c);
        }
    } else {
        /* s is NUL-terminated */
        for(i=0; /* condition in loop body */; /* U16_NEXT post-increments */) {
            U16_NEXT(s, i, length, c);
            if(c==0) {
                break;
            }
            printf(" %04x", c);
        }
    }
    printf(" }\n");
};

static void demo_C_Unicode_strings() {
    printf("\n* demo_C_Unicode_strings() --------- ***\n\n");

    static const UChar text[]={ 0x41, 0x42, 0x43, 0 };          /* "ABC" */
    static const UChar appendText[]={ 0x61, 0x62, 0x63, 0 };    /* "abc" */
    static const UChar cmpText[]={ 0x61, 0x53, 0x73, 0x43, 0 }; /* "aSsC" */
    UChar buffer[32];
    int32_t compare;
    int32_t length=u_strlen(text); /* length=3 */

    /* simple ANSI C-style functions */
    buffer[0]=0;                    /* empty, NUL-terminated string */
    u_strncat(buffer, text, 1);     /* append just n=1 character ('A') */
    u_strcat(buffer, appendText);   /* buffer=="Aabc" */
    length=u_strlen(buffer);        /* length=4 */
    printUString("should be \"Aabc\": ", buffer, -1);

    /* bitwise comparing buffer with text */
    compare=u_strcmp(buffer, text);
    if(compare<=0) {
        printf("String comparison error, expected \"Aabc\" > \"ABC\"\n");
    }

    /* Build "A<sharp s>C" in the buffer... */
    u_strcpy(buffer, text);
    buffer[1]=0xdf; /* sharp s, case-compares equal to "ss" */
    printUString("should be \"A<sharp s>C\": ", buffer, -1);

    /* Compare two strings case-insensitively using full case folding */
    compare=u_strcasecmp(buffer, cmpText, U_FOLD_CASE_DEFAULT);
    if(compare!=0) {
        printf("String case insensitive comparison error, expected \"AbC\" to be equal to \"ABC\"\n");
    }
}

//Function Print Binary variable
void pBinary(char *xpB,int32_t y){
    int32_t x;
    // y=sizeof(xpB);
    // y=50;
    printf("\nGia tri sizeof cua bien can in Binary: %d -- %d\n",y,8*y);
    printf("\n");
    for (int32_t i = y*8-1; i >=0; i--)
    {
        x=*xpB>>i;
        if (x&1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        };
        if(!(i%8)) printf(" ");
        
    };
    printf("\n");
};

void research(PGresult *res){
    printf("\n\n");
    int x,y;
    printf("Gia tri tuples = So hang cua res: %d\n",x=PQntuples(res));//Bat dau tu 0
    printf("Gia tri fields = So cot cua res: %d\n",y=PQnfields(res));//Bat dau tu 0
    printf("Gia tri PQftable = OID cua bang tu res: %d\n",PQftable(res,2));//
    printf("char *PQcmdStatus(PGresult *res): %s\n",PQcmdStatus(res));
    // printf("Gia tri PQfformat: %d\n",PQfformat(res,0));//Bat dau tu 0
    for ( int i = 0; i < y; i++)
    {
        printf("Gia tri PQfformat %d: %d\n",i,PQfformat(res,i));//Bat dau tu 0
    };

    for ( int i = 0; i < y; i++)
    {
        printf("Gia tri PQftype %d: %d\n",i,PQftype(res,i));//Bat dau tu 0
    };

    for (int i = 0; i < x; i++)
    {
        for (int z = 0; z < y; z++)
        {
            printf("Gia tri PQgetlength(%d,%d): %d\n",i,z,PQgetlength(res,i,z));//Bat dau tu 0
            pBinary(PQgetvalue(res,i,z),PQgetlength(res,i,z));
        };
        
    };

    
    
    
    // printf("Gia tri PQgetlength: %d\n",PQgetlength(res,0,0));//Bat dau tu 0
    printf("\n\n");

};



//...................
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"en_US.utf8");

    int listenfd = -1, cout=0;
    int connfd = -1;
    struct sockaddr_in server_addr;
    // string *send_buffer = new string[100];
    // string *sends= new string[500];
    char send_buffer[100];
    char sends[500];
    char send_saukhinoi[700];
    //char *queryt = (char*)"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" = 5;";
    

    time_t ticks;
    int nFields;
    char query[5000];

    //Unicode
    UErrorCode errorCode=U_ZERO_ERROR;
    //Close unicode

    cnv=ucnv_open(NULL, &errorCode);
    if(U_FAILURE(errorCode)) {
        fprintf(stderr, "error %s opening the default converter\n", u_errorName(errorCode));
        return errorCode;
    }

    ucnv_setFromUCallBack(cnv, UCNV_FROM_U_CALLBACK_ESCAPE, UCNV_ESCAPE_C, NULL, NULL, &errorCode);
    if(U_FAILURE(errorCode)) {
        fprintf(stderr, "error %s setting the escape callback in the default converter\n", u_errorName(errorCode));
        ucnv_close(cnv);
        return errorCode;
    }
    //Close unicode


    listenfd = socket(AF_INET, SOCK_STREAM,0); //Sever tao socket chuyen nhan(listen) cac ket noi tu client
    server_addr.sin_family = AF_INET;           //Server khoi tao dia chi cho rieng minh
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //Server khoi tao dia chi cho rieng minh
    server_addr.sin_port = htons(5000); //Server khoi tao dia chi cho rieng minh

    bind(listenfd, (struct sockaddr *)&server_addr,sizeof(server_addr));    //Dinh kem Ip chinh no vao socket chinh no tao ra
    listen(listenfd,1000);//Lang nghe 1000 socket client

    //khoi tao ket noi server toi database
    conn = PQconnectdb(conninfo);
    
    while (1)
    {
        // memset(send_buffer,NULL,sizeof(send_buffer));
        // sends->erase();
        // send_buffer->erase();
        memset(send_buffer,0,sizeof(send_buffer));
        memset(sends,0,sizeof(sends));
        memset(send_saukhinoi,0,sizeof(send_saukhinoi));
        
        
        //Xu ly ket noi client;
        printf("Bat dau accept: \n");
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); //Tao socket cho client
        // sends = (char*)"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" =";
        // sprintf(sends,"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" =");
        // sprintf(sends,"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" ='");
        sprintf(sends,"SELECT main_serial, x, y, z, t, one_serial, one_char FROM public.one_char where main_serial =");
        printf("Sends: %s - voi do dai: %ld",sends,sizeof(sends));
        // std::cout<<"Vua khoi tao ket noi Client den Server "<<connfd<<endl;
        // ticks = time(NULL);
        // sprintf(send_buffer, "Server phan hoi luc %s", ctime(&ticks));
        // write(connfd, send_buffer, strlen(send_buffer));
        //send(connfd,"Sever send to Client",21,0);
        // memset(send_buffer,NULL,sizeof(send_buffer));
        read(connfd,send_buffer,100);
        // sends.append(send_buffer).append(";");
        strcpy(send_saukhinoi,sends);
        int count=0;
        while((int)send_buffer[count]!=10) count++;
        send_buffer[count]=0;
        strcat(send_saukhinoi,send_buffer);


        strcat(send_saukhinoi,";");
        printf("\nChuoi sau khi noi: %s\n",send_saukhinoi);
        // printf("In tung ky tu: ");
        // for (size_t i = 0; i < 700; i++)
        // {
        //     printf("%d",(int)send_saukhinoi[i]);
        // };
        // printf("\n");
        
        
        
        // res = PQexec(conn,(char*)&sends);

        std::cout<<"\nGia tri send_buff tu client: "<<endl;
        std::cout<<sizeof(send_buffer)<<endl;
        // for (size_t i = 0; i < 100; i++)
        // {
        //     std::cout<<send_buffer[i]<<endl;
        // }
        std::cout<<(char*)"So ky tu cua send_buffer: "<<count<<endl;
        //sends->append(send_buffer).append(";");
        //std::cout<<*sends<<endl;



        res=PQexec(conn,send_saukhinoi);
        // PQprint();
        printf("Vua khoi tao res xong\n");
        printf("PQgetisnull(res,0,0): %d\n",PQgetisnull(res,0,4));
        printf("PQescapeString: %zu\n",PQescapeString(PQgetvalue(res,0,2),PQgetvalue(res,0,2),PQgetlength(res,0,2)));
        std::cout<<"PQfsize(res,0): "<<PQfsize(res,0)<<endl;
        std::cout<<"PQfsize(res,1): "<<PQfsize(res,1)<<endl;
        std::cout<<"PQfsize(res,2): "<<PQfsize(res,2)<<endl;
        std::cout<<"PQfsize(res,3): "<<PQfsize(res,3)<<endl;
        std::cout<<"PQfsize(res,4): "<<PQfsize(res,4)<<endl;
        std::cout<<"PQresultMemorySize(res): "<<PQresultMemorySize(res)<<endl;
        std::cout<<"pg_char_to_encoding(PQgetvalue(res,0,2)): "<<pg_char_to_encoding(PQgetvalue(res,0,0))<<endl;
        research(res);
        printf("PQgetlength(res,0,0) = %d\n",PQgetlength(res,0,0));
        printf("PQgetlength(res,0,1) = %d\n",PQgetlength(res,0,1));
        printf("PQgetlength(res,0,2) = %d\n",PQgetlength(res,0,2));
        printf("PQgetlength(res,0,3) = %d\n",PQgetlength(res,0,3));
        printf("PQgetlength(res,0,4) = %d\n",PQgetlength(res,0,4));
        // printf("PQgetlength(res,0,5) = %d\n",PQgetlength(res,0,5));
        /*
        // printf("PQgetlength(res,0,0) = %d\n",PQgetlength(res,1,0));
        // printf("PQgetlength(res,0,1) = %d\n",PQgetlength(res,0,1));
        // printf("PQgetlength(res,0,2) = %d\n",PQgetlength(res,0,2));
        // printf("PQgetlength(res,0,3) = %d\n",PQgetlength(res,0,3));
        // printf("PQgetlength(res,0,4) = %d\n",PQgetlength(res,0,4));
        // printf("PQgetlength(res,0,5) = %d\n",PQgetlength(res,0,5));
        // printf("*PQgetlength(res,0,1) = %d\n",*PQgetlength(res,0,0));
        // std::cout<<*PQgetlength(res,0,0)<<endl;
        // pBinary1(res);
        */
        if (PQresultStatus(res) != PGRES_TUPLES_OK)
        {
            fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
            PQclear(res);
            exit_nicely(conn);
        };
        nFields = PQnfields(res);
        printf("In nFields: %d\n",nFields);
        for (int i = 0; i < nFields; i++)
            printf("%-15s", PQfname(res, i));
        printf("\n\n");
        printf("PQtuples = %d\n\n\n",PQntuples(res));
        for (int i = 0; i < PQntuples(res); i++)
        {
            for (int j = 0; j < nFields; j++){
                printf("[%s](-- i=%d -- j=%d)\n", PQgetvalue(res, i, j),i,j);
                // std::cout<<"PQgetLen(res,i,j): "<<PQgetLen(res,i,j)<<endl;
            };
            printf("i = %d\n\n",i);
        };
        printf("------{%s}------\n",PQgetvalue(res, 0, 3));
        // printf("%lu\n",sizeof(char));

        // printf("Kiem tra byte tren du lieu: \n");
        // wchar_t xchar[100];
        // int it;
        // UChar uchar_test[100];
        // std::mbtowc(xchar,PQgetvalue(res,0,1),1);
        // std::wcout << L"In PQgetvalue(res,0,1) theo Wchar: "<<xchar<<endl;
        // printf("xxxxxxxxx%-15s", PQgetvalue(res, 0, 1));
        // printf("Kiem dinh: %d\n",it);
        // u_charsToUChars(PQgetvalue(res,0,1),uchar_test,100); /* include the terminating NUL */
        // u_UCharsToChars(uchar_test,xchar,100);
        // printf("Byte cua xchar: %s      -sizeof(xchar): ",xchar);
        // std::cout<<sizeof(xchar)<<endl;
        // printf("Byte cua int PQgetvalue(res,0,1): "); std::cout<<sizeof(PQgetvalue(res,0,1))<<endl;
        // std::cout<<"Kiem tra *PQgetvalue: ";
        // printf("---------%s--------",(char16_t)*PQgetvalue(res,0,1));
        // std::cout<<*PQgetvalue(res,0,1)<<endl;

        // printf("in xchar: \n");
        // printf("%X\n",xchar);
        char t;
        t=*PQgetvalue(res, 0, 1);
        std::cout<<"size *PQvalue: "<<sizeof(*PQgetvalue(res, 0, 1))<<endl<<"size PQvalue: "<<sizeof(PQgetvalue(res, 0, 1))<<endl;
        std::cout<<t<<" --- "<<sizeof(t)<<endl;
        int iwhile=0;
        printf("\n\n------------------------------------------------------\n");
        // while (PQgetvalue(res, 0, 1)[iwhile]!=10)
        // {
        //     printf("%c",PQgetvalue(res, 0, 0));
        //     iwhile++;
        // };
        int sizet=100;
        printf("PQgetvalue(res, 0, 0): size: %lu\n", sizeof(PQgetvalue(res, 0, 0)));
        for (iwhile = 0; iwhile < sizet; iwhile++)
        {
            printf("%c",PQgetvalue(res, 0, 0)[iwhile]);
        };
        pBinary(PQgetvalue(res, 0, 0),PQgetlength(res,0,0));
        printf("\n");
        printf("PQgetvalue(res, 0, 1): size: %lu\n", sizeof(PQgetvalue(res, 0, 1)));
        for (iwhile = 0; iwhile < sizet; iwhile++)
        {
            printf("%c",PQgetvalue(res, 0, 1)[iwhile]);
        };
        pBinary(PQgetvalue(res, 0, 1),PQgetlength(res,0,1));
        printf("\n");
        printf("PQgetvalue(res, 0, 2): size: %lu\n", sizeof(PQgetvalue(res, 0, 2)));
        for (iwhile = 0; iwhile < sizet; iwhile++)
        {
            printf("%c",PQgetvalue(res, 0, 2)[iwhile]);
        };
        pBinary(PQgetvalue(res, 0, 2),PQgetlength(res,0,2));
        printf("\n");
        printf("PQgetvalue(res, 0, 3): size: %lu\n", sizeof(PQgetvalue(res, 0, 3)));
        for (iwhile = 0; iwhile < sizet; iwhile++)
        {
            printf("%c",PQgetvalue(res, 0, 3)[iwhile]);
        };
        pBinary(PQgetvalue(res, 0, 3),PQgetlength(res,0,3));
        printf("\n");
        printf("PQgetvalue(res, 0, 4): size: %lu\n", sizeof(PQgetvalue(res, 0, 4)));
        for (iwhile = 0; iwhile < sizet; iwhile++)
        {
            printf("%c",PQgetvalue(res, 0, 4)[iwhile]);
        };
        pBinary(PQgetvalue(res, 0, 4),PQgetlength(res,0,4));
        printf("\n\n------------------------------------------------------\n");
        printf("%d\n\n",iwhile);

        wchar_t wcx=*PQgetvalue(res,0,1);
        wcout<<L"in ky tu wchar: "<<wcx<<endl;

       
        int intchar;

        // std::from_chars_result caocao = from_chars(PQgetvalue(res,0,1),PQgetvalue(res,0,1),intchar);
        // if (caocao.ec==std::errc{})
        // {
        //     std::cout<<"chuyen doi ra int: "<<intchar<<endl;
        // }else
        // {
        //     printf("Loi: %s\n",caocao.ec);
        // };
        
        
        // std::cout<<"In tu value: "<<intchar<<endl;
        char *achar[100],abc;
        achar[0]=PQgetvalue(res,0,1);
        printf("achar: %s\n",achar[0]); 
        printf("size achar: %lu\n",sizeof(achar));
        printf("*achar: %s\n",*achar);
        printf("size *achar: %lu\n",sizeof(*achar));
        // printf("achar: %h\n",*achar);
        std::cout<<"in achar theo cout: "<<achar<<endl;
        // printf("in achar theo cout: %c\n",achar);

        printf("in theo printf: %s\n",PQgetvalue(res,0,0));
        printf("in theo printf: %s\n",PQgetvalue(res,0,1));

        printf("in theo printf: %s\n",PQgetvalue(res,0,2));
        printf("in theo printf: %s\n",PQgetvalue(res,0,3));
        printf("in theo printf: %s\n",PQgetvalue(res,0,4));
        // u_printf("in theo uprintf: %s\n",PQgetvalue(res,0,1));

        std::cout<<"Test so sanh "<<endl;
        wint_t twc=5000;
        // abc=to_chars(5000);
        // printf("In abc: %hhd\n",abc);
        std::wcout<<L"in theo static_cast: "<<wchar_t(twc)<<"-- "<< sizeof(twc)<<endl;

        std::cout<<"++++++++++++++++++++"<<endl;
        char *naychar=PQgetvalue(res,0,6);
        for (int i = 0; i < PQgetlength(res,0,6); i++)
        {
            printf(" %0.2x",naychar[i]);
        };
        printf("\n");
        

        PQclear(res);

        sleep(1);
                
        close(connfd);
        // demo_C_Unicode_strings();
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    };
    
    // PQclear(res);
    // delete sends;
    // delete send_buffer;
    return 0;
}
