#include <iostream>
#include <time.h>
using namespace std;

int main()
{   
    int td=clock();
    int a; // khai bao a la so giay nhap vao
    cin >> a; 
    // 1/1/1970 la moc 0 
    float NGAY = 365.24217; // so ngay chuan trong nam
    float *e = &NGAY;
    if (a>=0)
    {   
        int ngay_tuongung = 1+ a/86400;
        int *n = &ngay_tuongung;
        double Ngay_tuongung = 1 + (static_cast <double>(a) / static_cast <double>(86400));
        double *N = &Ngay_tuongung;
        int nam = 1970 + (*N / *e);
        int *y = &nam;
        //cout<< nam<<endl;
        double Nam = 1970 + (*N / *e);
        double *Y = &Nam;
        int ngay =  (*Y - *y)*(*e);
        int gio = (*N - *n)* 24;
        int *g = &gio;
        double Gio = (*N -*n)*24;
        double *G = &Gio;
        int phut = (*G - *g)*60;
        int *p = &phut;
        double Phut = (*G - *g)*60;
        double *P = &Phut;
        int giay = 1+ (*P - *p)*60;
        int ngay_cua_thang;
        //cout << gio<<": "<< phut <<": "<< giay<< endl;
        if ((nam % 4 == 0) && (nam % 100 !=0) || (nam % 400 == 0))
        {
            if( ngay>=1 && ngay<=31)
            {
                ngay_cua_thang = ngay;
                cout << "ngay=="  << ngay_cua_thang << " thang 1" << " nam "<< nam << endl;
                cout << gio<<":"<< phut<<":"<<giay<< endl;
                
            }
            if( ngay>31 && ngay<=60)
            {
                ngay_cua_thang = ngay - 31;
                
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 2" << " nam "<< nam << endl;
            }
            if( ngay>60 && ngay<=91)
            {
                ngay_cua_thang = ngay - 60;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 3" << " nam "<< nam << endl;
            }
            if( ngay>91 && ngay<=121)
            {
                ngay_cua_thang= ngay - 91;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 4" << " nam "<< nam << endl;
            }
            if( ngay>121 && ngay<=152)
            {
                ngay_cua_thang = ngay - 121;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 5" << " nam "<< nam << endl;
            }
            if( ngay>152 && ngay<=182)
            {
                ngay_cua_thang = ngay - 152;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 6" << " nam "<< nam << endl;
            }
            if( ngay>182 && ngay<=213)
            {
                ngay_cua_thang = ngay - 182;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang7 " << " nam "<< nam << endl;
            }
            if( ngay>213 && ngay<=244)
            {
                ngay_cua_thang = ngay- 213;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang 8" << " nam "<< nam << endl;
            }
            if( ngay>244 && ngay<=274)
            {
                ngay_cua_thang= ngay- 244;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 9" << " nam "<< nam << endl;
            }
            if( ngay>274 && ngay<=305)
            {
                ngay_cua_thang = ngay- 274;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 10" << " nam "<< nam << endl;
            }
            if( ngay>305 && ngay<=335)
            {
                ngay_cua_thang = ngay - 305;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" << ngay_cua_thang << " thang 11" << " nam "<< nam << endl;
            }
            if( ngay>335 && ngay<=366)
            {
                ngay_cua_thang = ngay - 335;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 12" << " nam "<< nam << endl;
            }
        }
        else
        {
           if( ngay>=1 && ngay<=31)
            {
                ngay_cua_thang = ngay;
                cout << "ngay=="  << ngay_cua_thang << " thang 1" << " nam "<< nam << endl;
                cout << gio<<":"<< phut<<":"<<giay<< endl;
                
            }
            if( ngay>31 && ngay<=59)
            {
                ngay_cua_thang = ngay - 31;
                
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 2" << " nam "<< nam << endl;
            }
            if( ngay>59 && ngay<=90)
            {
                ngay_cua_thang = ngay - 59;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 3" << " nam "<< nam << endl;
            }
            if( ngay>90 && ngay<=120)
            {
                 ngay_cua_thang= ngay - 90;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 4" << " nam "<< nam << endl;
            }
            if( ngay>120 && ngay<=151)
            {
                ngay_cua_thang = ngay - 120;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 5" << " nam "<< nam << endl;
            }
            if( ngay>151 && ngay<=181)
            {
                ngay_cua_thang = ngay - 151;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 6" << " nam "<< nam << endl;
            }
            if( ngay>181 && ngay<=212)
            {
                ngay_cua_thang = ngay - 181;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang7 " << " nam "<< nam << endl;
            }
            if( ngay>212 && ngay<=243)
            {
                ngay_cua_thang = ngay- 212;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang 8" << " nam "<< nam << endl;
            }
            if( ngay>243 && ngay<=273)
            {
                ngay_cua_thang= ngay- 243;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 9" << " nam "<< nam << endl;
            }
            if( ngay>273 && ngay<=304)
            {
                ngay_cua_thang = ngay- 273;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 10" << " nam "<< nam << endl;
            }
            if( ngay>304 && ngay<=334)
            {
                ngay_cua_thang = ngay - 304;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay==" << ngay_cua_thang << " thang 11" << " nam "<< nam  << endl;
            }
            if( ngay>334 && ngay<=365)
            {
                ngay_cua_thang = ngay - 334;
                cout<< gio<<":"<< phut<<":"<<giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 12" << " nam "<< nam << endl;
            }
        };
        
    }
    if (a<0) cout << "SOSANH"<< endl;
    {
        int ngay_tuongung =  a/86400;
        int *n = &ngay_tuongung;
       // cout << "ngay tuong ung: " <<*n<< endl;
        double Ngay_tuongung = (static_cast <double>(a) / static_cast <double>(86400));
        double *N = &Ngay_tuongung;
        int nam =(double) 1970 + (double)(*N / *e);
        //cout<< "???"<< nam<< endl;
        int *y = &nam;
        //cout<< nam<<endl;
        double Nam = 1970 + (*N / *e);
        double *Y = &Nam;
        int ngay = (*Y - *y)*(*e);
        //cout << "ngay: "<< ngay<< endl;
        double Ngay = (*Y - *y)*(*e);
        //cout << "Ngay: "<< Ngay<< endl;
        int gio =24+ (*N - *n)* 24;
        int *g = &gio;
        double Gio =24+ (*N -*n)*24;
        double *G = &Gio;
        int phut =(*G - *g)*60;
        int *p = &phut;
        double Phut = (*G - *g)*60;
        double *P = &Phut;
        int giay = 1+ (*P - *p)*60;
        int ngay_cua_thang;
       // cout << gio<<": "<< phut <<": "<< giay<< endl;
        if ((nam % 4 == 0) && (nam % 100 !=0) || (nam % 400 == 0)) 
        {
            if( ngay>335&& ngay<=366)
            {
                ngay_cua_thang = ngay - 335;
                cout << "ngay=="  << ngay_cua_thang << " thang 12" << " nam "<< nam << endl;
                cout << gio <<":"<< phut <<":"<<giay<< endl;
                
            }
            if( ngay>305 && ngay<=335)
            {
                ngay_cua_thang = ngay - 305;
                
                cout<< gio <<":"<< phut <<":"<<giay << endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 11" << " nam "<< nam << endl;
            }
            if( ngay>274 && ngay<=305)
            {
                ngay_cua_thang = ngay - 274;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 10" << " nam "<< nam << endl;
            }
            if( ngay>244 && ngay<=274)
            {
                ngay_cua_thang= ngay - 244;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 9" << " nam "<< nam << endl;
            }
            if( ngay>213 && ngay<=244)
            {
                ngay_cua_thang = ngay - 213;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 8" << " nam "<< nam << endl;
            }
            if( ngay>182 && ngay<=213)
            {
                ngay_cua_thang = ngay - 182;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 7" << " nam "<< nam << endl;
            }
            if( ngay>152 && ngay<182)
            {
                ngay_cua_thang = ngay - 152;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang6 " << " nam "<< nam << endl;
            }
            if( ngay>121 && ngay<=152)
            {
                ngay_cua_thang = ngay - 121;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang 5" << " nam "<< nam << endl;
            }
            if( ngay>91 && ngay<=121)
            {
                ngay_cua_thang= ngay- 91;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 4" << " nam "<< nam << endl;
            }
            if( ngay>60&& ngay<=91)
            {
                ngay_cua_thang = ngay- 60;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 3" << " nam "<< nam << endl;
            }
            if( ngay>31 && ngay<=60)
            {
                ngay_cua_thang =ngay - 31;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" << ngay_cua_thang << " thang 2" << " nam "<< nam << endl;
            }
            if( ngay>=1 && ngay<=31)
            {
                ngay_cua_thang =ngay - 1;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 1" << " nam "<< nam << endl;
            }
        }
        else  cout<<"so sanh tiep"<< endl;
        {
            if( ngay>334&& ngay<=365)
            {
                ngay_cua_thang = ngay - 334;
                cout << "ngay=="  << ngay_cua_thang << " thang 12" << " nam "<< nam << endl;
                cout << gio <<":"<< phut <<":"<<giay<< endl;
                
            }
            if( ngay>304 && ngay<=334)
            {
                ngay_cua_thang = ngay - 304;
                
                cout<< gio <<":"<< phut <<":"<<giay << endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 11" << " nam "<< nam << endl;
            }
            if( ngay>273 && ngay<=304)
            {
                ngay_cua_thang = ngay - 273;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 10" << " nam "<< nam << endl;
            }
            if( ngay>243 && ngay<=273)
            {
                ngay_cua_thang= ngay - 243;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 9" << " nam "<< nam << endl;
            }
            if( ngay>212 && ngay<=243)
            {
                ngay_cua_thang = ngay - 212;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 8" << " nam "<< nam << endl;
            }
            if( ngay>181 && ngay<=212)
            {
                ngay_cua_thang = ngay - 181;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 7" << " nam "<< nam << endl;
            }
            if( ngay>151 && ngay<181)
            {
                ngay_cua_thang = ngay - 151;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang6 " << " nam "<< nam << endl;
            }
            if( ngay>120 && ngay<=151)
            {
                ngay_cua_thang = ngay - 120;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang  << " thang 5" << " nam "<< nam << endl;
            }
            if( ngay>90 && ngay<=120)
            {
                ngay_cua_thang= ngay- 90;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 4" << " nam "<< nam << endl;
            }
            if( ngay>59&& ngay<=90)
            {
                ngay_cua_thang = ngay- 59;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" <<  ngay_cua_thang << " thang 3" << " nam "<< nam << endl;
            }
            if( ngay>31 && ngay<=59)
            {
                ngay_cua_thang =ngay - 31;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay==" << ngay_cua_thang << " thang 2" << " nam "<< nam << endl;
            }
            if( ngay>=1 && ngay<=31)
            {
                ngay_cua_thang =ngay - 1;
                cout << gio<<": "<< phut <<": "<< giay<< endl;
                cout<< "ngay=="  <<  ngay_cua_thang << " thang 1" << " nam "<< nam << endl;
            }
        };
        

    }
    
    cout << clock()-td<<"Time CT";
    return 0;
}
