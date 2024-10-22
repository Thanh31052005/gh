#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct Fraction // Phân số
{
   int numerator;   // Tử số
   int denominator; // Mẫu số
};

void MENU();
void Option(int *a, int n);
void InputArray(int *&a, int &n);             // Nhập mảng
void OutputArray(int *a, int n);              // Xuất mảng
void InputFraction(Fraction &a);              // Nhập phân số
void OutputFraction(Fraction a);              // Xuất phân số
void CheckDenominator(Fraction a);            // Kiểm tra mẫu khác 0
void FractionCalculation(Fraction a, Fraction b); // Tính toán phân số
void SimplifyFraction(Fraction &a);           // Rút gọn phân số
void PrintOdd(int *a, int n);                 // Xuất các số từng chữ số là lẻ
int CountPrimeNum(int *a, int n);             // Đếm số ngtố
int MaxPosition(int *a, int n);               // Vị trí số lón nhất ở cuối (nếu có hai số giống nhau trở lên như excersise 1 đã nói)
int CheckEvenArray(int *a, int n);            // Kiểm tra mảng có toàn chẵn không
int CheckEven_Odd(int *a, int n);             // Kiểm tra mảng có chẵn lẻ xen kẽ không
int CheckPrimeNum(int x);                     // Kiểm tra số nguyên tố
int CheckPrimeArray(int *a, int n);           // Kiểm tra mảng toàn số nguyên tố không
int SymmetricalArray(int *a, int n);          // Kiểm tra mảng có đối xứng không
int CheckArray_INC(int *a, int n);            // Kiểm tra mảng có tăng dần không
int CheckArray_DEC(int *a, int n);            // Kiểm tra mảng có giảm dần không
int CheckOdd(int x);                          // Kiểm tra từng số là lẻ
void Swap(int &a, int &b);                    // Đổi chỗ
void _INC_Int_Selection_Sort(int *&a, int n); // Sắp xếp tăng dần
void _DEC_Int_Selection_Sort(int *&a, int n); // Sắp xếp giảm dần
void _INC_Int_Quick_Sort(int *&a, int l, int r);
void _DEC_Int_Quick_Sort(int *&a, int l, int r);

int main()
{
   int *a, n;
   Option(a, n);
   getch();
   return 1;
}

void MENU()
{
   printf("\n---------------------MENU--------------------");
   printf("\n1) Nhap/Xuat mang");
   printf("\n2) Dem so nguyen to");
   printf("\n3) Vi tri max o cuoi trong mang");
   printf("\n4) Kiem tra mang co phai toan chan");
   printf("\n5) Kiem tra mang co phai day so chan xen ke le ko");
   printf("\n6) Kiem tra xem mang co chua toan so ngto ko");
   printf("\n7) Kiem tra mang co doi xung hay khong");
   printf("\n8) Kiem tra mang co tang dan hay giam dan ko hay ko tang ko giam");
   printf("\n9) Xuat phan tu ma tung so la so le");
   printf("\n10) Lam viec voi phan so");
   printf("\n11) Sap xep tang dan kieu selection sort");
   printf("\n12) Sap xep giam dan kieu selection sort");
   printf("\n13) Sap xep tang dan kieu quick sort");
   printf("\n14) Sap xep giam dan kieu quick sort");
   printf("\n0) THOAT CHUONG TRINH");
}

void Option(int *a, int n)
{
   MENU();
   int nho = 1, chon;
   Fraction p;
   while (nho)
   {
      printf("\n*************************************");
      printf("\nNhap vao lua chon: ");
      scanf("%d", &chon);
      switch (chon)
      {

      case 1:
      {
         InputArray(a, n);
         OutputArray(a, n);
      }
      break;

      case 2:
      {
         printf("\nCo %d so nguyen to", CountPrimeNum(a, n));
      }
      break;

      case 3:
      {
         printf("\nNam o vi tri: a[%d] trong mang", MaxPosition(a, n));
      }
      break;

      case 4:
      {
         if (CheckEvenArray(a, n) == 1)
         {
            printf("\nMang toan chan");
         }

         else
         {
            printf("\nKhong phai la mang toan chan !!!");
         }
      }
      break;

      case 5:
      {
         OutputArray(a, n);
         if (CheckEven_Odd(a, n) == 1)
         {
            printf("\nMang chan le xen ke");
         }
         else
         {
            printf("\nMang khong chan le xen ke !!");
         }
      }
      break;

      case 6:
      {
         if (CheckPrimeArray(a, n) == 1)
         {
            printf("\nMang toan so nguyen to");
         }

         else
         {
            printf("\nMang ko phai toan so ngto !!");
         }
      }
      break;

      case 7:
      {
         if (SymmetricalArray(a, n) == 1)
         {
            printf("\nMang doi xung");
         }

         else
         {
            printf("\nMang khong doi xung !!!");
         }
      }
      break;

      case 8:
      {
         if(CheckArray_INC(a, n) == 1)
         {
            printf("\nMang tang dan");
         }

         else if(CheckArray_DEC(a, n) == 1)
         {
            printf("\nMang giam dan");
         }

         else
         {
            printf("\nMang ko tang cung ko giam");
         }
      }
      break;

      case 9: 
      {
         PrintOdd(a, n);
      }
      break;

      case 10:
      {
         printf("\nPhan so");
         int chon1, nho1 = 1;
         printf("\n-----------------MENU------------------");
         printf("\n1) Nhap/Xuat vao phan so");
         printf("\n2) Rut gon phan so");
         printf("\n3) Kiem tra mau khac 0");
         printf("\n4) Cac phep tinh voi phan so");
         printf("\n0) Thoat");
         while(nho1)
         {
            printf("\nNhap vao lua chon phan so: ");
            scanf("%d", &chon1);
            switch(chon1)
            {
               case 1: 
               {
                  InputFraction(p);
                  OutputFraction(p);
               }
               break;

               case 2: 
               {
                  SimplifyFraction(p);
               }
               break;

               case 3: 
               {
                  CheckDenominator(p);
               }
               break;

               case 4: 
               {
                  Fraction x, y;
                  printf("\nPhan so 1");
                  InputFraction(x);
                  printf("\nPhan so 2");
                  InputFraction(y);
                  FractionCalculation(x, y);
               }
               break;

               case 0: 
               {
                  printf("\nEsc");
                  nho1 = 0;
               }
            }
         }
      }

      break;

      case 11:
      {
         _INC_Int_Selection_Sort(a, n);
         printf("\nMang da duoc sap xep tang dan xong !!");
         OutputArray(a, n);
      }
      break;

      case 12:
      {
         _DEC_Int_Selection_Sort(a, n);
         printf("\nMang da duoc sap xep xong !!");
         OutputArray(a, n);
      }
      break;

      case 13:
      {
         _INC_Int_Quick_Sort(a, 0, n - 1);
         OutputArray(a, n);
      }
      break;

      case 14:
      {
         _DEC_Int_Quick_Sort(a, 0, n - 1);
         OutputArray(a, n);
      }
      break;

      case 0:
      {
         printf("\nTHOAT CHUONG TRINH !!!");
         nho = 0;
      }
      break;

      default:
         printf("\nVui long nhap dung lua chon");
         break;
      }
   }
}

void InputArray(int *&a, int &n)
{
   printf("\nNhap vao so luong phan tu : ");
   scanf("%d", &n);
   a = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++)
   {
      printf("\nNhap vao a[%d]: ", i);
      scanf("%d", (a + i));
   }
   printf("\nDa xong");
}

void OutputArray(int *a, int n)
{
   printf("\n-----------------------------------------");
   for (int i = 0; i < n; i++)
   {
      printf("\nGia tri a[%d] la: %d", i, *(a + i));
   }
}

int CheckPrimeNum(int x)
{
   if (x <= 1)
   {
      return 0;
   }

   for (int i = 2; i <= sqrt(x); i++)
   {
      if (x % i == 0)
      {
         return 0;
      }
   }
   return 1;
}

int CountPrimeNum(int *a, int n)
{
   int dem = 0;
   for (int i = 0; i < n; i++)
   {
      if (CheckPrimeNum(a[i]) == 1)
      {
         dem++;
      }
   }
   return dem;
}

int MaxPosition(int *a, int n)
{
   int max = *(a + (n - 1)); // Chạy cuối mảng lên (cre Phát Trần)
   int vtrMax = n - 1;
   for (int i = n - 2; i >= 0; i--)
   {
      if (max < *(a + i))
      {
         max = *(a + i);
         vtrMax = i;
      }
   }
   printf("\nGia tri lon nhat: %d", max);
   return vtrMax;
}

int CheckEvenArray(int *a, int n)
{
   for (int i = 0; i < n; i++)
   {
      if (*(a + i) % 2 != 0)
      {
         return 0;
      }
   }
   return 1;
}

int CheckEven_Odd(int *a, int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      if (a[i] % 2 == 0 && a[i + 1] % 2 == 0 || a[i] % 2 != 0 && a[i + 1] % 2 != 0)
      {
         return 0; // Ktra 2 ptu liền kề có chẵn lẻ xen kẽ không
      }
   }
   return 1;
}

int CheckPrimeArray(int *a, int n)
{
   for (int i = 0; i < n; i++)
   {
      if (CheckPrimeNum(*(a + i)) == 0)
      {
         return 0;
      }
   }
   return 1;
}

int SymmetricalArray(int *a, int n)
{
   int j = n - 1;
   for (int i = 0; i < (n / 2); i++)
   {
      if (*(a + i) != *(a + j)) // Tìm ptu ko đối xứng
      {
         return 0;
      }
      j--;
   }
   return 1;
}

int CheckOdd(int x)
{
   while (x)
   {
      int dv = x % 10;
      if (dv % 2 == 0) // Nếu chia hết 2 là chẵn
      {
         return 0;
      }
      x = x / 10;
   }
   return 1;
}

int CheckArray_INC(int *a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
				return 0;
		}
	}
	return 1;
}

int CheckArray_DEC(int *a, int n)
{
   for (int i = 0;i < n - 1;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			if (a[i] < a[j])
				return 0;
		}
	}
	return 1;
}

void PrintOdd(int *a, int n)
{
   printf("\nCac so toan chu so le: ");
   for (int i = 0; i < n; i++)
   {
      if (CheckOdd(*(a + i)) == 1)
      {
         printf("%d ", *(a + i));
      }
   }
}

void InputFraction(Fraction &a)
{
   printf("\nNhap vao tu so: ");
   scanf("%d", &a.numerator);
   printf("\nNhap vao mau so: ");
   scanf("%d", &a.denominator);
}

void OutputFraction(Fraction a)
{
   printf("\nPhan so la: %d/%d", a.numerator, a.denominator);
}

void CheckDenominator(Fraction a)
{
   try
   {
      if (a.denominator == 0)
      {
         throw "Mau bang 0 !!!";
      }

      else printf("\nMau khac 0");
   }
   catch (const char *str)
   {
      printf("\nLoi: %s", str);
   }
}

void SimplifyFraction(Fraction &a)
{ 
   if(a.denominator == 0)
   {
      printf("\nLoi: Mau bang 0 !!!");
      return;
   }

   if (a.numerator % a.denominator == 0) // Nếu tử lớn hơn mẫu và chia hết mẫu
   {
      printf("\nPhan so rut gon la: %d", a.numerator / a.denominator);
   }

   else if (a.denominator % a.numerator == 0) // Mẫu có thể chia hết tử rút gọn tử là 1
   {
      printf("\nPhan so rut gon: 1/%d", a.denominator / a.numerator);
   }

   else // Tìm thừa số chung lớn nhất nếu ko trong 2 trường hợp trên
   {
      int max = 1;
      for (int i = 2; i <= a.numerator / 2; i++)
      {
         if (a.denominator % i == 0 && a.numerator % i == 0)
         {
            max = i;
         }
      }
      if(max == 1)
      {
         printf("\nPhan so khong the rut gon them: %d/%d", a.numerator, a.denominator);
      }

      else printf("\nPhan so rut gon la: %d/%d", a.numerator/max, a.denominator/max);
   }
}

void FractionCalculation(Fraction a, Fraction b)
{
 Fraction tong, hieu, tich, thuong;

 tong.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
 tong.denominator = a.denominator * b.denominator;
 printf("\n\nTong 2 phan so la: %d/%d", tong.numerator, tong.denominator);
 SimplifyFraction(tong);

 hieu.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
 hieu.denominator = a.denominator * b.denominator;
 printf("\n\nHieu 2 phan so la: %d/%d", hieu.numerator, hieu.denominator);
 SimplifyFraction(hieu);

 tich.numerator = a.numerator * b.numerator;
 tich.denominator = a.denominator * b.denominator;
 printf("\n\nTich 2 phan so la: %d/%d", tich.numerator, tich.denominator);
 SimplifyFraction(tich);

 thuong.numerator = a.numerator * b.denominator;
 thuong.denominator = a.denominator * b.numerator;
 printf("\n\nThuong 2 phan so la: %d/%d", thuong.numerator, thuong.denominator);
 SimplifyFraction(thuong);
}

void Swap(int &a, int &b)
{
   int nho = a;
   a = b;
   b = nho;
}

void _INC_Int_Selection_Sort(int *&a, int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < n; j++)
      {
         if(*(a + j) < *(a + min))
         {
            min = j;
         }
      }
      if(min != i)
      {
         Swap(*(a + i),*(a + min));
      }
   }
}

void _DEC_Int_Selection_Sort(int *&a, int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int max = i;
      for(int j = i + 1; j < n; j++)
      {
         if(*(a + j) > *(a + max))
         {
            max = j;
         }
      }
      if(max != i)
      {
         Swap(*(a + i),*(a + max));
      } 
   }
}

void _INC_Int_Quick_Sort(int *&a, int l, int r)
{
   int i = l - 1 , j = l; 
   int p = r;

   if(l >= r)
   {
      return;
   }

   while(j < r)
   {
      if (a[j] <= a[p])
      {
        ++i; 
        Swap(a[j], a[i]);
      }
    j++;
   }
   Swap(a[i + 1], a[r]);
   p = i + 1;
   _INC_Int_Quick_Sort(a, l, p - 1);
   _INC_Int_Quick_Sort(a, p + 1, r);
}

void _DEC_Int_Quick_Sort(int *&a, int l, int r)
{
   int i = l - 1 , j = l; 
   int p = r;

   if(l >= r)
   {
      return;
   }

   while(j < r)
   {
      if (a[j] >= a[p])
      {
        ++i; 
        Swap(a[j], a[i]);
      }
    j++;
   }
   Swap(a[i + 1], a[r]);
   p = i + 1;
   _DEC_Int_Quick_Sort(a, l, p - 1);
   _DEC_Int_Quick_Sort(a, p + 1, r);
}