#include<iostream>
#include<conio.h>
#include<iomanip>

 struct Sinhvien
 {
   std::string TenSv;
   int Ngay, Thang, Nam;
   float GPA;
 };

  void nhapMang(Sinhvien a[], int &n)
   {
      while(n <= 0)
      {
         std::cout << "Nhap vao so Sinh vien : " ;
         std::cin >> n;
         if(n <= 0)
          std::cout << "Nhap so lg sv lon hon !!" << std::endl;
      }
      for(int i = 0; i < n; i++)
      {
         rewind(stdin);
        std::cout << "\n" <<"---------------------------------" << std::endl;
        std::cout << "Nhap vao sv thu " << i + 1 << std::endl;
        std::cout << "Ten : ";
        std::getline(std::cin, a[i].TenSv);
        rewind(stdin);
        std::cout << "Ngay Thang Nam sinh : ";
        std::cin >> a[i].Ngay;
        std::cin >> a[i].Thang;
        std::cin >> a[i].Nam;
        rewind(stdin);
        std::cout << "Diem GPA : ";
        std::cin >> a[i].GPA;
      }
   }
  
  void XuatdsSv(Sinhvien a[], int n)
  {
   std::cout << setfill('-');
   std::cout << std::setw(60) << "-" << std::endl;
   std::cout << setw(5) << std:: left <<"STT";
   std::cout << setw(30) << std::left <<"Ten";
   std::cout << setw(20) << std::left <<"Ngay Sinh";
   std::cout << setw(5) << std::right <<"GPA";
   for(int i = 0; i < n; i++)
   {
      
   }
  }

 int main()
 {
    int n = 0;
    Sinhvien a[10];
    nhapMang(a, n);
    XuatdsSv(a, n);
    getch();
    return 0;
 }