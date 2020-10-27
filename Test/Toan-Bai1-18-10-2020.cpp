#include<iostream>
using namespace std;
    double A, B, C;
   
int main()
{    
    double A, B, C;
    // nhập gia tri A, B, C
    cin >>A>>B>>C;
    // xuat ra man hinh gia tri A, B, C
    // va pt bac nhat Ax +
    // xuat ra man hinh gia tri A, B, C
    // va pt bac nhat Ax + B = 0
    cout<<"A, B, C ="<<A<<", "<<B<<", "<<C<< endl;
    cout<<"pt bac nhat:"<<A<<"x+"<<B<<"= 0"<< endl;
   // tinh nghiem pt Ax + B = 0
   // va so sanh voi C
     if ( A != 0){
        double x = (-B)/A; // x la nghiem cua pt bac nhat
      // xuat ra nghiem cua pt bac nhat
         if ((double) x > (double) C){
        
        cout<<"C < x="<<-B/A<<endl;
        cout<<"C/x ="<<C/x<<"&"<<"x/C ="<< x/C<<"&"<<"C*x ="<<C*x<<endl;
        cout<<"C-x ="<<C-x<<"&"<<"x-C ="<<x-C<<"&"<<"x+C ="<<x+C<<endl;
        }
         else {
            if ( x == C){
            cout<<"C = x ="<<-B/A<<endl;
            cout<<"x-C = C-x =0"<<endl;
            cout<<"x/C = C/x = 1"<< endl;
            cout<<"x+C =" <<x+C<<"&"<<"x*C ="<<x*C<<endl;
            }
            else {
            cout<<"C > x ="<<-B/A<<endl;
            cout<<"C-x ="<<C-x<<"&"<<"x-C ="<< x-C<<endl;
            cout<<"C+x ="<<C+x<<"&"<<"C*x ="<<C*x<<endl;
            cout<<"C/x ="<<C/x<<"&"<<"x/C ="<<x/C<<endl;
            };
             
                   };
            }
     else {
    cout<<"không tồn tai pt bac nhat"<<endl;
          };
    
    return 0;
}