#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm *timer_settime;
    time_t timehientai;
    time(&timehientai);
    
    timer_settime = gmtime(&timehientai);
    printf("Thoi gian hien tai: %d",timer_settime->tm_isdst);




    return 0;
}
