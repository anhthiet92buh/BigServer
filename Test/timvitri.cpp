#include<iostream>
using namespace std;

int main()
{ 
    int x[10];
    int max, min, lonhonhai;


    //nhap gia tri mang 10 phan tu    
  //for (int i = 0; i < 10; i++){cin >> x[i];};
  for (size_t i = 0; i < 10; i++)
  {
        cin >> x[i];
  };
  


    //tinh max
   max = x[0];
   for ( int i = 0; i < 10; i++)
   {
     if ( x[i] > max) {max = x[i];}
     
    };
    
    
    //Tinh min
    min = x[0];
    for ( int i = 0; i < 10; i++)
    { 
      if ( x[i] < min){ min = x[i];};
    };


    //print max min
    
    cout<<max<<"&"<<min<<endl<<endl<<endl<<endl;
    
    
    //so sanh vs so 2
    
    
    for ( int i = 0; i<10; i++)
    {
      if ((x[i] > min) && (x[i] < max))
        {    
           //lonhonhai = x[0];
            
            if  (x[i] >2)
            {
                //print ra vi tri cua so 2
            cout <<" 2 dung truoc "<< x[i]<< " "<< endl;
            }
             
        }
    }
    system("pause");
    return 0;
}