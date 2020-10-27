#include<iostream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    //Bat dau chuong trinh
    string s1,s2; // Khai bao chuoi S1 va S2
    cout<<"Nhap Chuoi so 1: "<<endl;
    cin >>s1;//Nhap Chuoi S1
    cout<<"Nhap Chuoi so 2: "<<endl;
    cin>>s2;//Nhap Chuoi S2

    //Tinh do dai 2 chuoi
    int d1=s1.size();
    int d2=s2.size();
    int delta=d1-d2;

    //Bien dem so lan chuoi trung nhau
    int phantu=0;
    int solantrung=0;

    //Bat dau so sanh
    if (delta ==0)
    {
        //Delta = 0 se thuc hien nhung cau lenh sau
        if (s1==s2)
        {
            cout<<"Hai Chuoi giong nhau"<<endl;
        }else
        {
            cout<<"Hai Chuoi cung do dai nhung noi dung khac nhau"<<endl;
        }
                
    }else
    {
        //Delta khac khong se thuc hien cau lenh o day
        if (delta>0)
        {
            //delta > 0  tuc la s1 nhieu ky tu hon s2
            for (size_t i = 0; i < delta; i++)
            {
                for (size_t x = 0; x < d2; x++)
                {
                    if (s1[i+x]==s2[x])
                    {
                        phantu++;
                        if (phantu==d2)
                        {
                            cout<<"S1 chua S2 tu phan tu thu: "<<i+1<<endl;
                            solantrung++;
                        }   
                    }                   
                    
                }
                
                
            }
            
        }else
        {
           //delta < 0  tuc la s2 nhieu ky tu hon s1
            for (size_t i = 0; i < -delta; i++)
            {
                for (size_t x = 0; x < d1; x++)
                {
                    if (s2[i+x]==s1[x])
                    {
                        phantu++;
                        if (phantu==d1)
                        {
                            cout<<"S2 chua S1 tu phan tu thu: "<<i+1<<endl;
                            solantrung++;
                        }
                    }                    
                }
            }
            
        }
        
        
    }
    
    
    if (solantrung!=0)
    {
        if (delta>0)
        {
            cout<<"Chuoi s2 trung "<<solantrung<<" lan trong chuoi S1"<<endl;
        }else
        {
            cout<<"Chuoi s1 trung "<<solantrung<<" lan trong chuoi S2"<<endl;
        }
        
        
    }else
    {
        cout<<"2 chuoi ko co doan trung nhau"<<endl;
    }
    
    cout<<endl<<endl<<endl;
    
    return 0;
}
