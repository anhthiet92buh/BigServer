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
// namespace nguoi Viet Nam
namespace vn{
    double deltaX = 0.000001;   //Sai so tieu chuan
    // Kieu cau truc Time cua nguoi Viet Nam
    struct vntime
    {
        int sec_vn;// So giay trong 1 phut tu 0 den 60, mac dinh la 0
        int min_vn;// So phut trong 1 gio tu 0 den 60, mac dinh la 0
        int hour_vn;// So gio trong 1 ngay tu 0 den 24, mac dinh la 0
        int mday_vn;// So ngay trong thang tu 1 den 31, mac dinh la 0
        int mon_vn;// Thang trong nam tu 1 den 12, mac dinh la 0
        int year_vn;// Nam, Nam bat dau 2000, mac dinh la 2000
        int wday_vn;// Ngay trong tuan, bat dau tu thu 2 den cn tuong ung tu 0 den 8, mac dinh la 0
        int yday_vn;// Ngay trong nam tu 0 den 366, mac dinh la 0
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
            return "Thu 6";
            break;
        }
        case 1: {
            return "Thu 7";
            break;
        }case 2: {
            return "Chu Nhat";
            break;
        }case 3: {
            return "Thu 2";
            break;
        }case 4: {
            return "Thu 3";
            break;
        }case 5: {
            return "Thu 4";
            break;
        }case 6: {
            return "Thu 5";
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
            return "Thu 7";
            break;
        }
        case -1: {
            return "Thu 6";
            break;
        }case -2: {
            return "Thu 5";
            break;
        }case -3: {
            return "Thu 4";
            break;
        }case -4: {
            return "Thu 3";
            break;
        }case -5: {
            return "Thu 2";
            break;
        }case -6: {
            return "Chu Nhat";
            break;
        }
        default:
            return "Fail Am";
            break;
        }
    };
    void chuyen_doi_trong_nam_nhuan(vntime *pt, int *ngaytrongchuky, int *yearMoc, int *weekday){
        pt->year_vn=*yearMoc;
        pt->yday_vn=*ngaytrongchuky;
        pt->wday_vn=*weekday;

        if (*ngaytrongchuky<=31)
        {
            pt->mday_vn=*ngaytrongchuky;
            pt->mon_vn = 1;            
        };
        if ((*ngaytrongchuky>31)&&(*ngaytrongchuky<=60))
        {
            pt->mday_vn=*ngaytrongchuky-31;
            pt->mon_vn = 2;
        };
        if ((*ngaytrongchuky>60)&&(*ngaytrongchuky<=91))
        {
            pt->mday_vn=*ngaytrongchuky-60;
            pt->mon_vn = 3;
        };
        if ((*ngaytrongchuky>91)&&(*ngaytrongchuky<=121))
        {
            pt->mday_vn=*ngaytrongchuky-91;
            pt->mon_vn = 4;
        };
        if ((*ngaytrongchuky>121)&&(*ngaytrongchuky<=152))
        {
            pt->mday_vn=*ngaytrongchuky-121;
            pt->mon_vn = 5;
        };
        if ((*ngaytrongchuky>152)&&(*ngaytrongchuky<=182))
        {
            pt->mday_vn=*ngaytrongchuky-152;
            pt->mon_vn = 6;
        };
        if ((*ngaytrongchuky>182)&&(*ngaytrongchuky<=213))
        {
            pt->mday_vn=*ngaytrongchuky-182;
            pt->mon_vn = 7;
        };
        if ((*ngaytrongchuky>213)&&(*ngaytrongchuky<=244))
        {
            pt->mday_vn=*ngaytrongchuky-213;
            pt->mon_vn = 8;
        };
        if ((*ngaytrongchuky>244)&&(*ngaytrongchuky<=274))
        {
            pt->mday_vn=*ngaytrongchuky-244;
            pt->mon_vn = 9;
        };
        if ((*ngaytrongchuky>274)&&(*ngaytrongchuky<=305))
        {
            pt->mday_vn=*ngaytrongchuky-244;
            pt->mon_vn = 10;
        };
        if ((*ngaytrongchuky>305)&&(*ngaytrongchuky<=335))
        {
            pt->mday_vn=*ngaytrongchuky-244;
            pt->mon_vn = 11;
        };
        if ((*ngaytrongchuky>335)&&(*ngaytrongchuky<=366))
        {
            pt->mday_vn=*ngaytrongchuky-244;
            pt->mon_vn = 12;
        };
    };



};


// In Ngay thang nam Gio phut Giay
void InTime(vn::vntime *pt){

    std::cout<<"Thu "<<pt->wday_vn<<" Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
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

    

    for (int i = -5; i <=5; i++)
    {
        if (i==-5)
        {
            ffull<<"So_Ngay_a"<<" "<<"Ngay_Moc"<<" "<<"Nam_Moc"<<" "<<"Ngay_trong_chu_ky"<<" "<<"Thu_trong_tuan"<<endl;
        };
        
        a=i;
        cout<<"a = "<<a<<endl;
        if(i<0) sleep(1);
    
    

    //---------------------------------
    //Xu ly du lieu

    if (a==0)
    {
        ngay_goc_vn(pt,a,b);
        InTime(pt);
    }else
    {

        int *slck4n, solanchuky4nam      = int(a/1461); // Lay chu ky 4 nam de tinh toan tim ra Time
        cout<<"Solanchu ky 4 nam: "<<solanchuky4nam<<" - sizeo int: "<<sizeof(int)<<endl;
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
        cout<<"Ngay trong Tuan: "<<*week_day<<endl;



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
            
            cout<<"Ngay Moc: "<<*day_Moc<<endl;
            
            //*year_Moc = int(b+*slck4n*4);
            cout<<"Nam Moc: "<<*year_Moc<<endl;
            

            ngaytrongchuky = int(a-*day_Moc);
            cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;

            ffull<<a<<" "<<*day_Moc<<" "<<*year_Moc<<" "<<*day_chuky<<" "<<*week_day<<" "<<ThuTrongTuan_Duong(week_day)<<endl;

            chuyen_doi_trong_nam_nhuan(pt,day_chuky,year_Moc,week_day);
            InTime(pt);










        }else if (a<0)
        {
            /* Truong hop a<0 */
            ngayMoc = int(*slck4n*1461-1461);
            cout<<"Ngay Moc: "<<*day_Moc<<endl;

            
            if (a-*day_Moc==1461)
            {
               *day_Moc=*day_Moc+1461;
               namMoc = int(b+*slck4n*4);
            }else
            {
                namMoc = int(b+*slck4n*4-4);
            };
            
            //namMoc = int(b+*slck4n*4-4);
            cout<<"Nam Moc: "<<*year_Moc<<endl;

            ngaytrongchuky = int(a-*day_Moc+1);
            cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;
            ffull<<a<<" "<<*day_Moc<<" "<<*year_Moc<<" "<<*day_chuky<<" "<<*week_day<<" "<<ThuTrongTuan_Am(week_day)<<endl;



        }else
        {
            cout<<"Chương Trình Bị Lỗi"<<endl;
        };

                
    };




    
    };
    
    ffull.close();

    return 0;
}