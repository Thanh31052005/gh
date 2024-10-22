#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX_SIZE 100

void MENU();                                     // Menu chọn
void Option(int a[], int n);                     // Lựa chọn
void InputArray(int a[], int &n);                // Nhập mảng
void OutputArray(int a[], int n);                // Xuất Mảng
void OutputPrimeNum(int a[], int n);             // Xuất số nguyên tố
void OutputPerfectNum(int a[], int n);           // Xuất số hoàn hảo
void OutputEvenPosition(int a[], int n);         // Xuất số vị trí chẵn
void OutputOddPosition(int a[], int n);          // Xuất số vị trí lẻ
void OutputMaxPosition(int a[], int n);          // Xuất số kèm vị trí max
void OutputMinPosition(int a[], int n);          // Xuất số kèm vị trí min
void MergeArray(int b[], int c[], int x, int y); // Gộp mảng
void BubbleSort(int a[], int n);                 // Sắp xếp nổi bọt
void Swap(int &a, int &b);                       // Đổi vị trí
int FindMax(int a[], int n);                     // Tìm max
int FindMin(int a[], int n);                     // Tìm min
int CountEven(int a[], int n);                   // Đếm chẵn
int CountOdd(int a[], int n);                    // Đếm lẻ
int FindBinary(int a[], int n, int x);           // Tìm kiếm x kiểu nhị phân
int FindLinear(int a[], int n, int x);           // Tìm kiếm x kiểu tuyến tính
int CountX(int a[], int n);                      // Đếm x
int CountGreaterThanX(int a[], int n);           // Đếm số lớn hơn x
int SumArray(int a[], int n);                    // Tổng mảng
int CheckPrimeNum(int x);                        // Kiểm tra số ngto
int CheckPerfectNum(int x);                      // Kiểm tra số hoàn hảo

int main()
{
   int a[MAX_SIZE], n;
   Option(a, n);
   getch();
   return 1;
}

void MENU()
{
   printf("\n------------MENU------------");
   printf("\n1) Nhap/xuat mang mot chieu");
   printf("\n2) Tim max/min cua mang");
   printf("\n3) Dem so ptu chan/le mang");
   printf("\n4) Tim kiem x theo nhi phan/tuyen tinh"); // Note: Trường hợp x nhiều nơi trên 1 mảng
   printf("\n5) Dem so phan tu x");
   printf("\n6) Dem so phan tu lon hon x");
   printf("\n7) Tinh tong mang");
   printf("\n8) Xuat so nguyen to trong mang");
   printf("\n9) Xuat so hoan thien");
   printf("\n10) Xuat phan tu vi tri chan/le");
   printf("\n11) Xuat max/min kem theo vi tri");
   printf("\n12) Ghep mang va sap xep");
   printf("\n0) Thoat chuong trinh !!!");
}

void Option(int a[], int n)
{
   int chon, nho = 1;
   MENU();
   while (nho)
   {
      printf("\n\n--------------------------------------------------------------");
      printf("\n\nNhap vao lua chon : ");
      scanf("%d", &chon);
      switch (chon)
      {
      case 0:
      {
         printf("\nThoat chuong trinh !!!");
         nho = 0;
      }
      break;

      case 1:
      {
         InputArray(a, n);
         OutputArray(a, n);
      }
      break;

      case 2:
      {
         printf("\nGia tri lon nhat trong mang : %d", FindMax(a, n));
         printf("\nGia tri nho nhat trong mang : %d", FindMin(a, n));
      }
      break;

      case 3:
      {
         printf("\nSo ptu chan la : %d", CountEven(a, n));
         printf("\nSo ptu le la : %d", CountOdd(a, n));
      }
      break;

      case 4:
      {
         // có thể có các phần tử giống nhau !
         int x, chon1;
         printf("\nNhap vao x: ");
         scanf("%d", &x);
         printf("\n1) Tim kiem tuyen tinh");
         printf("\n2) Tim kiem nhi phan");
         printf("\n\nNhap vao lua chon tim kiem: ");
         scanf("%d", &chon1);
         switch (chon1)
         {
         case 1:
         {
            if (FindLinear(a, n, x) >= 0)
            {
               printf("\nDa tim %d tai a[%d]", x, FindLinear(a, n, x));
            }
            else
            {
               printf("\nKhong tim thay %d", x);
            }
         }

         break;
         case 2:
         {
            if (FindBinary(a, n, x) >= 0)
            {
               printf("\nDa tim %d tai a[%d]", x, FindBinary(a, n, x));
            }
            else
            {
               printf("\nKhong tim thay %d", x);
            }
         }
         break;
         default:
            printf("\nKiem tra lai lua chon");
            break;
         }
      }
      break;

      case 5:
      {
         printf("\nCo %d ptu x trong mang", CountX(a, n));
      }
      break;

      case 6:
      {
         printf("\nCo %d ptu lon hon x trong mang", CountGreaterThanX(a, n));
      }
      break;

      case 7:
      {
         printf("\nTong cua mang la: %d", SumArray(a, n));
      }
      break;

      case 8:
      {
         OutputPrimeNum(a, n);
      }
      break;

      case 9:
      {
         OutputPerfectNum(a, n);
      }
      break;

      case 10:
      {
         OutputEvenPosition(a, n);
         OutputOddPosition(a, n);
      }
      break;

      case 11:
      {
         OutputMinPosition(a, n);
         printf("\n-------------------");
         OutputMaxPosition(a, n);
      }
      break;

      case 12:
      {
         int b[MAX_SIZE], c[MAX_SIZE], x, y;
         printf("\nMANG THU NHAT");
         InputArray(b, x);
         OutputArray(b, x);
         printf("\n--------------------------");
         printf("\nMANG THU HAI");
         InputArray(c, y);
         OutputArray(c, y);
         MergeArray(b, c, x, y);
      }
      break;

      default:
      {
         printf("\nKiem tra lai lua chon !");
      }
      break;
      }
   }
}

void InputArray(int a[], int &n)
{
   while (1)
   {
      printf("\nNhap vao so luong ptu trong mang (0 < n < 100): ");
      scanf("%d", &n);
      if (n <= 0 || n >= 100)
      {
         printf("\nCheck input !!!");
      }
      else
      {
         printf("\nNhap mang");
         break;
      }
   }
   for (int i = 0; i < n; i++)
   {
      printf("\nNhap vao a[%d]: ", i);
      scanf("%d", &a[i]);
   }
   printf("\nDa xong !!!");
}

void OutputArray(int a[], int n)
{
   printf("\nMang chua %d phan tu", n);
   for (int i = 0; i < n; i++)
   {
      printf("\nPhan tu a[%d]: %d", i, a[i]);
   }
}

int FindMax(int a[], int n)
{
   int max = a[0];
   for (int i = 1; i < n; i++)
   {
      if (max < a[i])
      {
         max = a[i];
      }
   }
   return max;
}

int FindMin(int a[], int n)
{
   int min = a[0];
   for (int i = 1; i < n; i++)
   {
      if (min > a[i])
      {
         min = a[i];
      }
   }
   return min;
}

int CountEven(int a[], int n)
{
   int chan = 0;
   for (int i = 0; i < n; i++)
   {
      if (a[i] % 2 == 0)
      {
         chan++;
      }
   }
   return chan;
}

int CountOdd(int a[], int n)
{
   int le = 0;
   for (int i = 0; i < n; i++)
   {
      if (a[i] % 2 != 0)
      {
         le++;
      }
   }
   return le;
}

void Swap(int &a, int &b)
{
   int c = a;
   a = b;
   b = c;
}

void BubbleSort(int a[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = 0; j < n - i - 1; j++)
      {
         if (a[j] > a[j + 1])
         {
            Swap(a[j], a[j + 1]);
         }
      }
   }
   printf("\nDa sap xep xong !");
}

int FindBinary(int a[], int n, int x) 
{
   int L = 0, R = n - 1;
   BubbleSort(a, n);
   printf("\n\n Mang da duoc sap xep !!");
   OutputArray(a, n);
   while (L <= R)
   {
      int M = (L + R) / 2;
      if (a[M] == x)
      {
         return M;
      }

      else if (x < a[M])
      {
         R = M - 1;
      }
      else
      {
         L = M + 1;
      }
   }
   return -1;
}

int FindLinear(int a[], int n, int x)
{
   for (int i = 0; i < n; i++)
   {
      if (a[i] == x)
      {
         return i;
      }
   }
   return -1;
}

int CountX(int a[], int n)
{
   int dem = 0, x;
   printf("\nNhap vao gia tri x :");
   scanf("%d", &x);
   for (int i = 0; i < n; i++)
   {
      if (a[i] == x)
      {
         dem++;
      }
   }
   return dem;
}

int CountGreaterThanX(int a[], int n)
{
   int dem1 = 0, x1;
   printf("\nNhap vao so x: ");
   scanf("%d", &x1);
   for (int i = 0; i < n; i++)
   {
      if (a[i] > x1)
      {
         dem1++;
      }
   }
   return dem1;
}

int SumArray(int a[], int n)
{
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += a[i];
   }
   return sum;
}

int CheckPrimeNum(int x)
{
   if(x <= 1)
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

void OutputPrimeNum(int a[], int n)
{
   printf("\nSo nguyen to trong mang :");
   for (int i = 0; i < n; i++)
   {
      if (CheckPrimeNum(a[i]) == 1)
      {
         printf("%d ", a[i]);
      }
   }
}

int CheckPerfectNum(int x)
{
   int tong = 1; // bắt đầu bằng 1 vì mọi số đều chia hết cho 1
   if(x <= 1)
   {
      return 0;
   }
   for (int i = 2; i <= x / 2; i++)
   {
      if (x % i == 0)
      {
         tong += i;
      }
   }
   if (tong == x)
   {
      return 1;
   }
   else
      return 0;
}

void OutputPerfectNum(int a[], int n)
{
   printf("\nSo hoan hao trong mang: ");
   for (int i = 0; i < n; i++)
   {
      if (CheckPerfectNum(a[i]) == 1)
      {
         printf("%d ", a[i]);
      }
   }
}

void OutputEvenPosition(int a[], int n)
{
   printf("\nPhan tu vi tri chan: ");
   for (int i = 0; i < n; i+=2)
   {
      printf("%d ", a[i]);
   }
}

void OutputOddPosition(int a[], int n)
{
   printf("\nPhan tu vi tri le: ");
   for (int i = 1; i < n; i+=2)
   {
      printf("%d ", a[i]);
   }
}

void OutputMaxPosition(int a[], int n)
{
   printf("\nPhan tu lon nhat: %d", FindMax(a, n));
   printf("\nO vi tri a[%d]", FindLinear(a, n, FindMax(a, n)));
}

void OutputMinPosition(int a[], int n)
{
   printf("\nPhan tu nho nhat: %d", FindMin(a, n));
   printf("\nO vi tri a[%d]", FindLinear(a, n, FindMin(a, n)));
}

void MergeArray(int b[], int c[], int x, int y)
{
   int a[MAX_SIZE], n = x;
   for (int i = 0; i < x; i++)
   {
      a[i] = b[i];
   }

   for (int j = 0; j < y; j++)
   {
      a[n] = c[j];
      n++;
   }
   printf("\n\nGhep mang hoan thanh !!!");
   BubbleSort(a, n);
   OutputArray(a, n);
}

// Good !