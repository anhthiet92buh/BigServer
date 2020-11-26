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

// namespace nguoi Viet Nam
namespace vn{
    double deltaX = 0.000001;   //Sai so tieu chuan
    // Kieu cau truc Time cua nguoi Viet Nam
    struct vntime
    {
        int sec_vn;     // So giay trong 1 phut tu 0 den 60, mac dinh la 0
        int min_vn;     // So phut trong 1 gio tu 0 den 60, mac dinh la 0
        int hour_vn;    // So gio trong 1 ngay tu 0 den 24, mac dinh la 0
        int mday_vn;    // So ngay trong thang tu 1 den 31, mac dinh la 0
        int mon_vn;     // Thang trong nam tu 1 den 12, mac dinh la 0
        int year_vn;    // Nam, Nam bat dau 2000, mac dinh la 2000
        int wday_vn;    // Ngay trong tuan, bat dau tu thu 2 den cn tuong ung tu 0 den 8, mac dinh la 0
        int yday_vn;    // Ngay trong nam tu 0 den 366, mac dinh la 0
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
};
// In Ngay thang nam Gio phut Giay
void InTime(vn::vntime *pt){

    std::cout<<"Ngay "<<pt->mday_vn<<" Thang "<<pt->mon_vn<<" Nam "<<pt->year_vn<<": "<<pt->hour_vn<<": "<<pt->min_vn<<"'"<<": "<<pt->sec_vn<<"''"<<std::endl;
};

using namespace std;
using namespace vn;

int main(int argc, char const *argv[])
{
    vntime *pt, t;
    pt = &t;
    //--------------------------------
    int a,b=2000;  
    cin >> a;   // Nhap vao so ngay
    //cin >> b;   // Nhap vào năm gốc


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
        




        if (a>0)
        {
            /* Truong hop a>0 */
            ngayMoc = int(*slck4n*1461);
            cout<<"Ngay Moc: "<<*day_Moc<<endl;

            if (a<=1461)
            {
                namMoc = b;
            }else
            {
                namMoc = int(b+*slck4n*4);
            }
            
            
            cout<<"Nam Moc: "<<*year_Moc<<endl;

            ngaytrongchuky = int(a-*day_Moc);
            cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;










        }else if (a<0)
        {
            /* Truong hop a<0 */
            ngayMoc = int(*slck4n*1461-1461);
            cout<<"Ngay Moc: "<<*day_Moc<<endl;

            namMoc = int(b+*slck4n*4-4);
            cout<<"Nam Moc: "<<*year_Moc<<endl;

            ngaytrongchuky = int(a-*day_Moc);
            cout<<"So ngay trong chu ky: "<<*day_chuky<<endl;
        }else
        {
            cout<<"Chương Trình Bị Lỗi"<<endl;
        };

                
    };
    
    
    










    return 0;
}
