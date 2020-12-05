/* Day la chuong trinh dinh ngia lai thoi gian theo tieu chuan rieng cua nguoi Viet Nam phat trien dua tren tieu chuan c++ 2020:
    - Version 1.0
    - Goc thoi gian la: 01/01/2000
    - Moc thoi gian 0 la thoi diem dau tien cua ngay 01/01/2000
    - Gia tri 1 chinh la ngay 01/01/2000
    - Neu he thong ko co dong ho se tra ve gia tri 0
    - Lay ngay lam chuan de quy doi ra don vi thoi gian khac
    - Don vi nho nhat la Giay, Lon nhat la Nam
    - Luu y: Su dung chu ky 4 nam 1461 Ngay de tim ra thoi gian
*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vntime>


//ofstream ffull("Full.txt");

// namespace nguoi Viet Nam
namespace vn{
    double deltaX = 0.000001;   //Sai so tieu chuan
    // Kieu cau truc Time cua nguoi Viet Nam
    struct vntime
    {
        int sec_vn=0;// So giay trong 1 phut tu 0 den 60, mac dinh la 0
        int min_vn=0;// So phut trong 1 gio tu 0 den 60, mac dinh la 0
        int hour_vn=0;// So gio trong 1 ngay tu 0 den 24, mac dinh la 0
        int mday_vn=0;// So ngay trong thang tu 1 den 31, mac dinh la 0
        int mon_vn=0;// Thang trong nam tu 1 den 12, mac dinh la 0
        int year_vn=0;// Nam, Nam bat dau 2000, mac dinh la 2000
        int wday_vn=0;// Ngay trong tuan, bat dau tu thu 2 den cn tuong ung tu 0 den 8, mac dinh la 0
        int yday_vn=0;// Ngay trong nam tu 0 den 366, mac dinh la 0
    };
    struct RealTime
    {
        /* data */
    };
    

    vntime ngay_goc_vn(vntime *pt, int a, int b){
            pt->sec_vn = 0;
            pt->min_vn = 0;
            pt->hour_vn = 0;
            pt->mday_vn = 1;
            pt->mon_vn = 1;
            pt->year_vn = b;
            pt->wday_vn = 7;
            pt->yday_vn = 1;
            return *pt;
    };
    const char *ThuTrongTuan_Duong(int *x){
        switch (*x)
        {
        case 0:{
            return "Thu6";
            break;
        }
        case 1: {
            return "Thu7";
            break;
        }case 2: {
            return "CN";
            break;
        }case 3: {
            return "Thu2";
            break;
        }case 4: {
            return "Thu3";
            break;
        }case 5: {
            return "Thu4";
            break;
        }case 6: {
            return "Thu5";
            break;
        }
        default:
            return "Fail Duong";
            break;
        }
    };
    const char *ThuTrongTuan_Am(int *x){
        switch (*x)
        {
        case 0:{
            return "Thu7";
            break;
        }
        case -1: {
            return "Thu6";
            break;
        }case -2: {
            return "Thu5";
            break;
        }case -3: {
            return "Thu4";
            break;
        }case -4: {
            return "Thu3";
            break;
        }case -5: {
            return "Thu2";
            break;
        }case -6: {
            return "CN";
            break;
        }
        default:
            return "Fail Am";
            break;
        }
    };
    void chuyen_doi_trong_nam_nhuan(vntime *pt, int *ngaytrongnam, int *yearMoc, int *weekday){
        pt->year_vn=*yearMoc;
        pt->yday_vn=*ngaytrongnam;
        pt->wday_vn=*weekday;

        if (*ngaytrongnam<=31)
        {
            pt->mday_vn=*ngaytrongnam;
            pt->mon_vn = 1;            
        };
        if ((*ngaytrongnam>31)&&(*ngaytrongnam<=60))
        {
            pt->mday_vn=*ngaytrongnam-31;
            pt->mon_vn = 2;
        };
        if ((*ngaytrongnam>60)&&(*ngaytrongnam<=91))
        {
            pt->mday_vn=*ngaytrongnam-60;
            pt->mon_vn = 3;
        };
        if ((*ngaytrongnam>91)&&(*ngaytrongnam<=121))
        {
            pt->mday_vn=*ngaytrongnam-91;
            pt->mon_vn = 4;
        };
        if ((*ngaytrongnam>121)&&(*ngaytrongnam<=152))
        {
            pt->mday_vn=*ngaytrongnam-121;
            pt->mon_vn = 5;
        };
        if ((*ngaytrongnam>152)&&(*ngaytrongnam<=182))
        {
            pt->mday_vn=*ngaytrongnam-152;
            pt->mon_vn = 6;
        };
        if ((*ngaytrongnam>182)&&(*ngaytrongnam<=213))
        {
            pt->mday_vn=*ngaytrongnam-182;
            pt->mon_vn = 7;
        };
        if ((*ngaytrongnam>213)&&(*ngaytrongnam<=244))
        {
            pt->mday_vn=*ngaytrongnam-213;
            pt->mon_vn = 8;
        };
        if ((*ngaytrongnam>244)&&(*ngaytrongnam<=274))
        {
            pt->mday_vn=*ngaytrongnam-244;
            pt->mon_vn = 9;
        };
        if ((*ngaytrongnam>274)&&(*ngaytrongnam<=305))
        {
            pt->mday_vn=*ngaytrongnam-274;
            pt->mon_vn = 10;
        };
        if ((*ngaytrongnam>305)&&(*ngaytrongnam<=335))
        {
            pt->mday_vn=*ngaytrongnam-305;
            pt->mon_vn = 11;
        };
        if ((*ngaytrongnam>335)&&(*ngaytrongnam<=366))
        {
            pt->mday_vn=*ngaytrongnam-335;
            pt->mon_vn = 12;
        };
    };
    void chuyen_doi_trong_nam_thuong(vntime *pt, int *ngaytrongnam, int *yearMoc, int *weekday,int *ngaytrongchuky){
        if((*ngaytrongchuky>366)&&(*ngaytrongchuky<=731)) pt->year_vn=*yearMoc+1;
        if((*ngaytrongchuky>731)&&(*ngaytrongchuky<=1096)) pt->year_vn=*yearMoc+2;
        if((*ngaytrongchuky>1096)&&(*ngaytrongchuky<=1461)) pt->year_vn=*yearMoc+3; 
        //pt->year_vn=*yearMoc;
        pt->yday_vn=*ngaytrongnam;
        pt->wday_vn=*weekday;

        if (*ngaytrongnam<=31)
        {
            pt->mday_vn=*ngaytrongnam;
            pt->mon_vn = 1;            
        };
        if ((*ngaytrongnam>31)&&(*ngaytrongnam<=59))
        {
            pt->mday_vn=*ngaytrongnam-31;
            pt->mon_vn = 2;
        };
        if ((*ngaytrongnam>59)&&(*ngaytrongnam<=90))
        {
            pt->mday_vn=*ngaytrongnam-59;
            pt->mon_vn = 3;
        };
        if ((*ngaytrongnam>90)&&(*ngaytrongnam<=120))
        {
            pt->mday_vn=*ngaytrongnam-90;
            pt->mon_vn = 4;
        };
        if ((*ngaytrongnam>120)&&(*ngaytrongnam<=151))
        {
            pt->mday_vn=*ngaytrongnam-120;
            pt->mon_vn = 5;
        };
        if ((*ngaytrongnam>151)&&(*ngaytrongnam<=181))
        {
            pt->mday_vn=*ngaytrongnam-151;
            pt->mon_vn = 6;
        };
        if ((*ngaytrongnam>181)&&(*ngaytrongnam<=212))
        {
            pt->mday_vn=*ngaytrongnam-181;
            pt->mon_vn = 7;
        };
        if ((*ngaytrongnam>212)&&(*ngaytrongnam<=243))
        {
            pt->mday_vn=*ngaytrongnam-212;
            pt->mon_vn = 8;
        };
        if ((*ngaytrongnam>243)&&(*ngaytrongnam<=273))
        {
            pt->mday_vn=*ngaytrongnam-243;
            pt->mon_vn = 9;
        };
        if ((*ngaytrongnam>273)&&(*ngaytrongnam<=304))
        {
            pt->mday_vn=*ngaytrongnam-273;
            pt->mon_vn = 10;
        };
        if ((*ngaytrongnam>304)&&(*ngaytrongnam<=334))
        {
            pt->mday_vn=*ngaytrongnam-304;
            pt->mon_vn = 11;
        };
        if ((*ngaytrongnam>334)&&(*ngaytrongnam<=365))
        {
            pt->mday_vn=*ngaytrongnam-334;
            pt->mon_vn = 12;
        };
    };
    void TimNgay(vntime *pt,int *yearMoc, int *weekDay, int *ngaytrongchuky){
        int dayofyear;
        if(*ngaytrongchuky<=366) chuyen_doi_trong_nam_nhuan(pt,ngaytrongchuky,yearMoc,weekDay);
        if((*ngaytrongchuky>366)&&(*ngaytrongchuky<=731)) {
            dayofyear=*ngaytrongchuky-366;
            chuyen_doi_trong_nam_thuong(pt,&dayofyear,yearMoc,weekDay,ngaytrongchuky);
        };
        if((*ngaytrongchuky>731)&&(*ngaytrongchuky<=1096)){
            dayofyear=*ngaytrongchuky-731;
            chuyen_doi_trong_nam_thuong(pt,&dayofyear,yearMoc,weekDay,ngaytrongchuky);
        };
        if((*ngaytrongchuky>1096)&&(*ngaytrongchuky<=1461)){
            dayofyear=*ngaytrongchuky-1096;
            chuyen_doi_trong_nam_thuong(pt,&dayofyear,yearMoc,weekDay,ngaytrongchuky);
        };
    };


};


// In Ngay thang nam Gio phut Giay
void InTime(vn::vntime *pt,int *weekday, int a){

    if (a>0)
    {
        std::cout<<vn::ThuTrongTuan_Duong(weekday)<<" = "<<"Thu "<<pt->wday_vn<<" Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
    };
    if (a<0)
    {
        std::cout<<vn::ThuTrongTuan_Am(weekday)<<" = "<<"Thu "<<pt->wday_vn<<" Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
    };
    if (a=0)
    {
        std::cout<<"Thu "<<pt->wday_vn<<" Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
    };
    

    //std::cout<<"Thu "<<pt->wday_vn<<" Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
};

using namespace std;
using namespace vn;

int main(int argc, char const *argv[])
{
    vntime *pt, t;
    pt = &t;
    //--------------------------------
    int a,b=2000;  
    //cin >> a;   // Nhap vao so ngay
    //cin >> b;   // Nhap vào năm gốc
    //------------------------------------
    ofstream ffull;
    ffull.open("Full.txt",ios::out);

    

    for (int i = -5000; i <=5000; i++)
    {
        /*if (i==-5)
        {
            ffull<<"So_Ngay_a"<<" "<<"Ngay_Moc"<<" "<<"Nam_Moc"<<" "<<"Ngay_trong_chu_ky"<<" "<<"Thu_trong_tuan"<<endl;
        };*/
        
        a=i;
        cout<<"a = "<<a<<"---";
        //if(i<0) sleep(1);
    
    

    //---------------------------------
    //Xu ly du lieu

    if (a==0)
    {
        ngay_goc_vn(pt,a,b);
        InTime(pt,NULL,a);
        ffull<<a<<" "<<"T"<<pt->wday_vn<<" "<<pt->mday_vn<<" "<<pt->mon_vn<<" "<<pt->year_vn<<" "<<pt->hour_vn<<" "<<pt->min_vn<<" "<<pt->sec_vn<<std::endl;
    }else
    {

        int *slck4n, solanchuky4nam      = int(a/1461); // Lay chu ky 4 nam de tinh toan tim ra Time
        //cout<<"Solanchu ky 4 nam: "<<solanchuky4nam<<" - sizeo int: "<<sizeof(int)<<endl;
        slck4n=&solanchuky4nam;

        int *day_Moc,ngayMoc;
        day_Moc=&ngayMoc;
        //cout<<"Ngay Moc: "<<*day_Moc<<endl;

        int *year_Moc, namMoc;
        year_Moc = &namMoc;
        //cout<<"Nam Moc: "<<*year_Moc<<endl;

        int *day_chuky, ngaytrongchuky;
        day_chuky = &ngaytrongchuky;
        //cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;
        
        int *week_day, dayofweek=a%7;
        week_day = &dayofweek;
        //cout<<"Ngay trong Tuan: "<<*week_day<<endl;

        int *DayOfYear,ngaytrognam;
        DayOfYear=&ngaytrognam;



        if (a>0)
        {
            /* Truong hop a>0 */
            *day_Moc = int(*slck4n*1461);
            
            
            if (a==*day_Moc)
            {
                *year_Moc = int(b+*slck4n*4-4);
                *day_Moc=*day_Moc-1461;
            }else
            {
                *year_Moc = int(b+*slck4n*4);
            };
            
            //cout<<"Ngay Moc: "<<*day_Moc<<endl;
            
            //*year_Moc = int(b+*slck4n*4);
            //cout<<"Nam Moc: "<<*year_Moc<<endl;
            

            ngaytrongchuky = int(a-*day_Moc);
            //cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;

            

            

            //ffull<<a<<" "<<*day_Moc<<" "<<*year_Moc<<" "<<*day_chuky<<" "<<*week_day<<" "<<ThuTrongTuan_Duong(week_day)<<endl;

            TimNgay(pt,year_Moc,week_day,day_chuky);
            InTime(pt,week_day,a);
            ffull<<a<<" "<<vn::ThuTrongTuan_Duong(week_day)<<" "<<"T"<<pt->wday_vn<<" "<<pt->mday_vn<<" "<<pt->mon_vn<<" "<<pt->year_vn<<" "<<pt->hour_vn<<" "<<pt->min_vn<<" "<<pt->sec_vn<<std::endl;



        }else if (a<0)
        {
            /* Truong hop a<0 */
            ngayMoc = int(*slck4n*1461-1461);
            //cout<<"Ngay Moc: "<<*day_Moc<<endl;

            
            if (a-*day_Moc==1461)
            {
               *day_Moc=*day_Moc+1461;
               namMoc = int(b+*slck4n*4);
            }else
            {
                namMoc = int(b+*slck4n*4-4);
            };
            
            //namMoc = int(b+*slck4n*4-4);
            //cout<<"Nam Moc: "<<*year_Moc<<endl;

            ngaytrongchuky = int(a-*day_Moc+1);
            //cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;
            //ffull<<a<<" "<<*day_Moc<<" "<<*year_Moc<<" "<<*day_chuky<<" "<<*week_day<<" "<<ThuTrongTuan_Am(week_day)<<endl;

            TimNgay(pt,year_Moc,week_day,day_chuky);
            InTime(pt,week_day,a);
            cout<<pt->hour_vn<<"-----------------------------------------------------------------------"<<endl;
            ffull<<a<<" "<<vn::ThuTrongTuan_Am(week_day)<<" "<<"T"<<pt->wday_vn<<" "<<pt->mday_vn<<" "<<pt->mon_vn<<" "<<pt->year_vn<<" "<<pt->hour_vn<<" "<<pt->min_vn<<" "<<pt->sec_vn<<std::endl;


        }else
        {
            cout<<"Chương Trình Bị Lỗi"<<endl;
        };

                
    };




    
    };
    
    ffull.close();

    return 0;
}