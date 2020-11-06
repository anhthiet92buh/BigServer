#include <iostream>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

void NamNhuan(int nam){




};
void NamKoNhuan(int nam){};
void Nam(int nam){};
void Thang(int nam){};
void Ngay(int nam){};
void Gio(int nam){};
int LayPhanNguyen(double x){
    return (int)x;
};
void InFullTimeSCN(int Nam, int Thang, int Ngay, int gio, int phut, int s){
    cout<< gio<<":"<<phut<<":"<<s<<"--- Ngay "<<Ngay<<" Thang "<<Thang<<" Nam "<<Nam<<" SCN."<<endl;
};

void InFullTimeTCN(int Nam, int Thang, int Ngay, int gio, int phut, int s){
    cout<< gio<<":"<<phut<<":"<<s<<"--- Ngay "<<Ngay<<" Thang "<<Thang<<" Nam "<<-Nam<<" TCN."<<endl;
};

int main ()
{   
    //Nhap vao so bat ky - Quy uoc la so ngay
    float a; 
    cin >> a;
    
    // Don vi quy uoc
    int y = 1900;   // y la nam moc theo quy uoc
    float n = 365.24217;    // n so ngay cua 1 nam

    // Xu ly nam
    int d = y + a/n;    // so nam lay phan nguyen
    double b = a/n; // so nam lay ca phan du chua + voi 1900
    //cout << b <<endl;

    double z = fabs((b-LayPhanNguyen(b))*n); // lay gia tri tuyet doi cua ngay
    //cout << z;

    int t =LayPhanNguyen(1+z); // Ngay lam tron
    //cout << t;
    double i = 1 + z; // Ngay trong nam lay ca phan du

    // Xu ly gio, phut, giay
    int gio = (i - t) * 24 ;
    float GIO;
    GIO = (i -t) * 24 ;
    int phut;
    phut = (GIO - gio) * 60 ;
    float PHUT;
    PHUT = (GIO - gio) * 60 ;
    int giay;
    giay = (PHUT - phut) * 60 ;
    int ngay ;
    gio = (i - t) * 24 ;
    phut = (GIO - gio)*60 ;
    giay = (PHUT - phut) * 60 ;


   // tim nam nhuan va nam ko nhuan
   cout<<"CT dang vao vong so sanh d"<<endl;
    if(d>=0)
    {
      if ((d % 4 == 0) && (d % 100 !=0) || (d % 400 == 0))
      {
        if( t>=1 && t<=31)  InFullTimeSCN(d,1,t,gio,phut,giay);
        if( t>31 && t<=60)  InFullTimeSCN(d,2,t-31,gio,phut,giay);
        if( t>60 && t<=91)  InFullTimeSCN(d,3,t-60,gio,phut,giay);
        if( t>91 && t<=121) InFullTimeSCN(d,4,t-91,gio,phut,giay);
        if( t>121 && t<=152) InFullTimeSCN(d,5,t-121,gio,phut,giay);
        if( t>152 && t<=182) InFullTimeSCN(d,6,t-152,gio,phut,giay);
        if( t>182 && t<=213) InFullTimeSCN(d,7,t-182,gio,phut,giay);
        if( t>213 && t<=244) InFullTimeSCN(d,8,t-213,gio,phut,giay);
        if( t>244 && t<=274) InFullTimeSCN(d,9,t-244,gio,phut,giay);
        if( t>274 && t<=305) InFullTimeSCN(d,10,t-274,gio,phut,giay);
        if( t>305 && t<=335) InFullTimeSCN(d,11,t-305,gio,phut,giay);
        if( t>335 && t<=366) InFullTimeSCN(d,12,t-335,gio,phut,giay);
        
      }
      else
      {
        if( t>=1 && t<=31)  InFullTimeSCN(d,1,t,gio,phut,giay);
        if( t>31 && t<=59)  InFullTimeSCN(d,2,t-31,gio,phut,giay);
        if( t>59 && t<=90)  InFullTimeSCN(d,3,t-59,gio,phut,giay);
        if( t>90 && t<=120) InFullTimeSCN(d,4,t-90,gio,phut,giay);
        if( t>120 && t<=151) InFullTimeSCN(d,5,t-120,gio,phut,giay);
        if( t>151 && t<=181) InFullTimeSCN(d,6,t-151,gio,phut,giay);
        if( t>181 && t<=212) InFullTimeSCN(d,7,t-181,gio,phut,giay);
        if( t>212 && t<=243) InFullTimeSCN(d,8,t-212,gio,phut,giay);
        if( t>243 && t<=273) InFullTimeSCN(d,9,t-243,gio,phut,giay);
        if( t>273 && t<=304) InFullTimeSCN(d,10,t-273,gio,phut,giay);
        if( t>304 && t<=334) InFullTimeSCN(d,11,t-304,gio,phut,giay);
        if( t>334 && t<=365) InFullTimeSCN(d,12,t-334,gio,phut,giay);
        
      };
      
    }
    else // neu d < 0
    {

      if ((d % 4 == 0) && (d % 100 != 0) || (d % 400 == 0))
      {
        if( t>=1 && t<=31)  InFullTimeTCN(d,1,t,gio,phut,giay);
        if( t>31 && t<=60)  InFullTimeTCN(d,2,t-31,gio,phut,giay);
        if( t>60 && t<=91)  InFullTimeTCN(d,3,t-60,gio,phut,giay);
        if( t>91 && t<=121) InFullTimeTCN(d,4,t-91,gio,phut,giay);
        if( t>121 && t<=152) InFullTimeTCN(d,5,t-121,gio,phut,giay);
        if( t>152 && t<=182) InFullTimeTCN(d,6,t-152,gio,phut,giay);
        if( t>182 && t<=213) InFullTimeTCN(d,7,t-182,gio,phut,giay);
        if( t>213 && t<=244) InFullTimeTCN(d,8,t-213,gio,phut,giay);
        if( t>244 && t<=274) InFullTimeTCN(d,9,t-244,gio,phut,giay);
        if( t>274 && t<=305) InFullTimeTCN(d,10,t-274,gio,phut,giay);
        if( t>305 && t<=335) InFullTimeTCN(d,11,t-305,gio,phut,giay);
        if( t>335 && t<=366) InFullTimeTCN(d,12,t-335,gio,phut,giay);
      }
      
      else
      {
        if( t>=1 && t<=31)  InFullTimeTCN(d,1,t,gio,phut,giay);
        if( t>31 && t<=59)  InFullTimeTCN(d,2,t-31,gio,phut,giay);
        if( t>59 && t<=90)  InFullTimeTCN(d,3,t-59,gio,phut,giay);
        if( t>90 && t<=120) InFullTimeTCN(d,4,t-90,gio,phut,giay);
        if( t>120 && t<=151) InFullTimeTCN(d,5,t-120,gio,phut,giay);
        if( t>151 && t<=181) InFullTimeTCN(d,6,t-151,gio,phut,giay);
        if( t>181 && t<=212) InFullTimeTCN(d,7,t-181,gio,phut,giay);
        if( t>212 && t<=243) InFullTimeTCN(d,8,t-212,gio,phut,giay);
        if( t>243 && t<=273) InFullTimeTCN(d,9,t-243,gio,phut,giay);
        if( t>273 && t<=304) InFullTimeTCN(d,10,t-273,gio,phut,giay);
        if( t>304 && t<=334) InFullTimeTCN(d,11,t-304,gio,phut,giay);
        if( t>334 && t<=365) InFullTimeTCN(d,12,t-334,gio,phut,giay);

      }
      
        
    }
    
    return 0;
}