#include <ctime>
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


}