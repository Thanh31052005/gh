#include <stdio.h>
#include <conio.h>
#include <math.h>

void NhapN(int &n);
void MENU();
void Option(int &n);
int TongCau1DeQuy(int n);
int TongCau1KhuDeQuy(int n);
float TongCau2DeQuy(int n);
float TongCau2KhuDeQuy(int n);
float TongCau3DeQuy(int n);
float TongCau3KhuDeQuy(int n);
float TongCau4DeQuy(int n);
float TongCau4KhuDeQuy(int n);
int TongCau5DeQuy(int n);
int TongCau5KhuDeQuy(int n);
float TongCau6DeQuy(int n);
float TongCau6KhuDeQuy(int n);
int TongCau7DeQuy(int n);
int TongCau7KhuDeQuy(int n);
int Tong1DenN(int x);
int TongCau8DeQuy(int n);
int TongCau8KhuDeQuy(int n);
int GiaiThua(int x);
float TongCau9DeQuy(int n);
float TongCau9KhuDeQuy(int n);
float TongCau10DeQuy(int n);
float TongCau10KhuDeQuy(int n);
float TongCau11DeQuy(int n);
float TongCau11KhuDeQuy(int n);
int TongCau12DeQuy(int m, int n);
int TongCau12KhuDeQuy(int m, int n);
int UCLNDeQuy(int a, int b);
int UCLNKhuDeQuy(int a, int b);
int CapSoCong(int a, int d, int n);
int CapSoNhan(int a, int q, int n);
int TinhUnLonHon6(int n);


void NhapN(int &n)
{
  do
  {
    printf("\nNhap vao n: ");
    scanf("%d", &n);
    try
    {
      if (n <= 0)
      {
        throw "N <= 0 Khong hop le !!!";
      }
    }
    catch (const char *str)
    {
      printf("\nLoi: %s", str);
    }
  } while (n <= 0);
}

int TongCau1DeQuy(int n)
{
  if (n == 1)
    return 1;
  else
    return n + TongCau1DeQuy(n - 1);
}

int TongCau1KhuDeQuy(int n)
{
  int tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += i;
  }
  return tong;
}

float TongCau2DeQuy(int n)
{
  if (n == 1)
    return sqrt(2);
  else
    return sqrt(2 + TongCau2DeQuy(n - 1));
}

float TongCau2KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong = sqrt(2 + tong);
  }
  return tong;
}

float TongCau3DeQuy(int n)
{
  if (n == 1)
    return 0.5;
  else
    return (float)n / (n + 1) + TongCau3DeQuy(n - 1);
}

float TongCau3KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += (1.0 * i / (i + 1));
  }
  return tong;
}

float TongCau4DeQuy(int n)
{
  if (n == 0)
    return 1;
  else
    return 1.0 / (2 * n + 1) + TongCau4DeQuy(n - 1);
}

float TongCau4KhuDeQuy(int n)
{
  float tong = 1;
  for (int i = 1; i <= n; i++)
  {
    tong += 1.0 / (2 * i + 1);
  }
  return tong;
}

int TongCau5DeQuy(int n)
{
  if (n == 1)
    return 2;
  else
    return (n * (n + 1)) + TongCau5DeQuy(n - 1);
}

int TongCau5KhuDeQuy(int n)
{
  int tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += i * (i + 1);
  }
  return tong;
}

float TongCau6DeQuy(int n)
{
  if (n == 1)
    return 1.0 / (1 * 2 * 3);
  else
    return 1.0 / (n * (n + 1) * (n + 2)) + TongCau6DeQuy(n - 1);
}

float TongCau6KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += 1.0 / (i * (i + 1) * (i + 2));
  }
  return tong;
}

int TongCau7DeQuy(int n)
{
  if (n == 1)
    return 1;
  else
    return pow(n, 2) + TongCau7DeQuy(n - 1);
}

int TongCau7KhuDeQuy(int n)
{
  int tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += pow(i, 2);
  }
  return tong;
}

int Tong1DenN(int x)
{
  int tong = 1;
  for (int i = 2; i <= x; i++)
  {
    tong += i;
  }
  return tong;
}

int TongCau8DeQuy(int n)
{
  if (n == 1)
    return 1;
  else
    return Tong1DenN(n) + TongCau8DeQuy(n - 1);
}

int TongCau8KhuDeQuy(int n)
{
  int tong = 1;
  for (int i = 2; i <= n; i++)
  {
    tong += Tong1DenN(i);
  }
  return tong;
}

int GiaiThua(int x)
{
  int tich = 1;
  for (int i = 2; i <= x; i++)
  {
    tich *= i;
  }
  return tich;
}

float TongCau9DeQuy(int n)
{
  if (n == 1)
    return -1.0 * ((1.0 + 2) / GiaiThua(2));
  else
    return ((pow(-1.0, n) * (((2 * n - 1) + 2 * n))) / (GiaiThua(2 * n))) + TongCau9DeQuy(n - 1);
}

float TongCau9KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += ((pow(-1.0, i) * (((2 * i - 1) + (2 * i)))) / (GiaiThua(2 * i)));
  }
  return tong;
}

float TongCau10DeQuy(int n)
{
  if (n == 1)
    return (1.0 * GiaiThua(2)) / (2 + sqrt(3));
  else
    return ((n * GiaiThua(n + 1.0)) / ((n + 1) + sqrt(n + 2))) + TongCau10DeQuy(n - 1);
}

float TongCau10KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 1; i <= n; i++)
  {
    tong += ((i * GiaiThua(i + 1.0)) / ((i + 1) + sqrt(i + 2)));
  }
  return tong;
}

float TongCau11DeQuy(int n)
{
  if (n == 0)
    return 1.0 / (1 + sqrt(GiaiThua(2)));
  else
    return (n + sqrt(n + n + 1)) / ((n + 1) + sqrt(GiaiThua(n + 2))) + TongCau11DeQuy(n - 1);
}

float TongCau11KhuDeQuy(int n)
{
  float tong = 0;
  for (int i = 0; i <= n; i++)
  {
    tong += (i + sqrt(i + i + 1)) / ((i + 1) + sqrt(GiaiThua(i + 2)));
  }
  return tong;
}

int TongCau12DeQuy(int m, int n)
{
  if (n == 0)
    return 1;
  else
    return m * TongCau12DeQuy(m, n - 1);
}

int TongCau12KhuDeQuy(int m, int n)
{
  int tich = 1;
  for (int i = 1; i <= n; i++)
  {
    tich *= m;
  }
  return tich;
}

int UCLNDeQuy(int a, int b)
{
  if(a == b)
   return a;
  else
  {
    if(a > b)
    {
      return UCLNDeQuy(a - b, b);
    }

    else
    {
      return UCLNDeQuy(a, b - a);
    }
  } 
}

int UCLNKhuDeQuy(int a, int b)
{
  while(a != b)
  {
    if(a > b)
    {
      a = a - b;
    }

    else
    {
      b = b - a;
    }
  }
  return a;
}

int CapSoCong(int a, int d, int n)
{
  if(n == 1)
   return a;
  else 
   return d + CapSoCong(a, d, n - 1); 
}

int CapSoNhan(int a, int q, int n)
{
  if(n == 1)
   return a;
  else
   return q * CapSoNhan(a, q, n - 1);
}

int TinhUnLonHon6(int n)
{
  if(n < 6)
   return n;
  else
  {
   return TinhUnLonHon6(n - 5) + TinhUnLonHon6(n - 4) + TinhUnLonHon6(n - 3) + TinhUnLonHon6(n - 2) + TinhUnLonHon6(n - 1);
  } 
}

void MENU()
{
  printf("\n---------------------------MENU------------------------");
  printf("\n1) Tinh S(n) = 1 + 2 + 3 + .... + n");
  printf("\n2) Tinh sqrt(2+ sprt(2 + sqrt(n)))");
  printf("\n3) Tinh 1/2 + 2/3 +..+ n/n+1");
  printf("\n4) 1 + 1/3 + 1/5... + 1 / 2n + 1");
  printf("\n5) 1.2 + 2.3 + ... + n(n+1)");
  printf("\n6) 1/1.2.3 + ... + 1/n.(n+1).(n+2)");
  printf("\n7) 1^2 + 2^2 + ..+ n^2");
  printf("\n8) 1 + (1+2) + .. + (1 + 2 +...+ n)");
  printf("\n9) - 1+2 / 2! + .. + (-1)^n (2n - 1) + 2n / (2n!)");
  printf("\n10) n.(n + 1)! / (n + 1) + sqrt(n+2)");
  printf("\n11) n + sqrt(n + n + 1) / (n  + 1) + sqrt((n + 2)!)");
  printf("\n12) Tinh m^n");
  printf("\n13) Tinh UCLN cu a va b");
  printf("\n14) Cap so Cong");
  printf("\n15) Cap so Nhan");
  printf("\n16) U(n) = Un-5 + Un-4 + Un-3 + Un-2 + Un-1 (n >= 6)");
  printf("\n17) ");
  printf("\n18) ");
  printf("\n19) ");
  printf("\n0) Thoat chuong trinh !!!");
}

void Option(int &n)
{
  int chon = 0;
  do
  {
    printf("\n\nNhap vao lua chon: ");
    scanf("%d", &chon);
    switch (chon)
    {

    case 1:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %d", TongCau1DeQuy(n));
      printf("\nTong cau khu de quy: %d", TongCau1KhuDeQuy(n));
    }
    break;

    case 2:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau2DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau2KhuDeQuy(n));
    }
    break;

    case 3:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau3DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau3KhuDeQuy(n));
    }
    break;

    case 4:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau4DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau4KhuDeQuy(n));
    }
    break;

    case 5:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %d", TongCau5DeQuy(n));
      printf("\nTong cau khu de quy: %d", TongCau5KhuDeQuy(n));
    }
    break;

    case 6:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau6DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau6KhuDeQuy(n));
    }
    break;

    case 7:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %d", TongCau7DeQuy(n));
      printf("\nTong cau khu de quy: %d", TongCau7KhuDeQuy(n));
    }
    break;

    case 8:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %d", TongCau8DeQuy(n));
      printf("\nTong cau khu de quy: %d", TongCau8KhuDeQuy(n));
    }
    break;

    case 9:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau9DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau9KhuDeQuy(n));
    }
    break;

    case 10:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau10DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau10KhuDeQuy(n));
    }
    break;

    case 11:
    {
      NhapN(n);
      printf("\nTong theo de quy la: %.3f", TongCau11DeQuy(n));
      printf("\nTong cau khu de quy: %.3f", TongCau11KhuDeQuy(n));
    }
    break;

    case 12:
    {
      int m = 0;
      printf("\nNhap vao so nguyen m: ");
      scanf("%d", &m);
      NhapN(n);
      printf("\nTong theo de quy la: %d", TongCau12DeQuy(m, n));
      printf("\nTong cau khu de quy: %d", TongCau12KhuDeQuy(m, n));
    }
    break;

    case 13:
    {
      int a = 0, b = 0;
      printf("\nNhap vao so nguyen a: ");
      scanf("%d", &a);
      printf("\nNhap vao so nguyen b: ");
      scanf("%d", &b);
      printf("\nUCLN de quy la: %d", UCLNDeQuy(a, b));
      printf("\nUCLN cau khu de quy: %d", UCLNKhuDeQuy(a, b));
    }
    break;
    
    case 14:
    {
      int a = 0, d = 0;
      printf("\nNhap vao so dau: ");
      scanf("%d", &a);
      printf("\nNhap vao cong sai: ");
      scanf("%d", &d);
      NhapN(n);
      printf("\nSo hang thu %d la: %d", n, CapSoCong(a, d, n));
    }
    break;

    case 15:
    {
      int a = 0, q = 0;
      printf("\nNhap vao so dau: ");
      scanf("%d", &a);
      printf("\nNhap vao cong boi: ");
      scanf("%d", &q);
      NhapN(n);
      printf("\nSo hang thu %d la: %d", n, CapSoNhan(a, q, n));
    }
    break;

    case 16:
    {
      NhapN(n);
      printf("\nTong U(n): %d", TinhUnLonHon6(n));
    }
    break;

    case 17:
    {
      
    }
    break;

    case 18:
    {
      
    }
    break;

    case 0:
    {
      printf("\nThoat chuong trinh !!!");
    }
    break;

    default:
      printf("\nKiem tra lai lua chon !");
      break;
    }
  } while (chon != 0);
}

int main()
{
  int n = 0;
  MENU();
  Option(n);
  getch();
  return 1;
}