#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt1 = ctime(&now);
   char* dt2 = ctime(&now);

   cout << "The local date and time is: " << dt1 << endl;
   cout << "The local date and time is: " << dt2 << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt1 = asctime(gmtm);
   cin.get();
   return 0;
}