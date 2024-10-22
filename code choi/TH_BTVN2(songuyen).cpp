#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 50

 void NhapMang(int a[], int &n)
  {
    printf("\nNhap vao so luong phan tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      a[i] = rand()% n + 15;
    }
  }

 void XuatMang(int a[], int n)
 {
  printf("\nMang a: ");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
 }

 int CheckPrimeNum(int x)
{
   if(x <= 1)
   {
      return 0;
   }

   for(int i = 2; i <= x / 2; i++)
   {
      if(x % i == 0)
      {
         return 0;
      }
   }
   return 1;
}

 void LietKeSoNguyenBeN(int a[])
 {
  int n;
  printf("\nNhap vao n: ");
  scanf("%d", &n);
  printf("\n");
  int dem = 0;
  for(int i = 0; i < n; i++)
  {
    if(CheckPrimeNum(a[i]) == 1 && a[i] < n)
    {
      printf("%d ", a[i]);
      dem++;
    }
  }
  if(dem == 0)
  {
    printf("\nKo co so ngto nao be hon n");
  }
 }

 int LayChuDau(int x)
{
   int dv;
   while (x)
   {
      dv = x % 10;
      x = x / 10;
   }
   return dv;
}

 int TongDauLe(int a[], int n)
{
  int tong = 0;
  for(int i = 0; i < n; i++)
  {
    if(LayChuDau(a[i]) % 2 != 0)
    {
      tong += a[i];
    }
  }
  return tong;
}
 
 int LietKeSoLanXH(int a[], int n)
 {
  int x, dem = 0;
  printf("\nNhap vao so can dem so lan xh: ");
   scanf("%d", &x);
  for(int i = 0; i < n; i++)
  {
    if(a[i] == x)
    {
      dem++;
    }
  }
  return dem;
 }

  void Swap(int &a, int &b)
  {
   int nho = a;
   a = b;
   b = nho;
  }
 
 void SapxepChanTangLeGiam(int a[], int n)
 {
  for(int i = 0; i < n; i++)
  {
    if(a[i] % 2 == 0)
    {
      for(int j = i + i; j < n; j++)
      {
        if(a[j] % 2 == 0 && a[j] < a[i])
        {
          Swap(a[i], a[j]);
        }
      }
    }

    else
    {
      for(int e = i + 1; e < n; e++)
      {
        if(a[e] % 2 != 0 && a[e] > a[i])
        {
          Swap(a[e], a[i]);
        }
      }
    }
  }
 }
 
 int KiemTraChuaX(int x, int dv1, int chuc1)
 {
  int demdv = 0, demchuc = 0;
  while(x)
  {
    int dv = x % 10;
    if(dv == dv1)
    {
      demdv++;
    }

    if(dv == chuc1)
    {
      demchuc++;
    }
    x = x / 10;
  }
  if(demdv != 0 && demchuc != 0)
  {
    return 1;
  }
  
  else return 0;
 }

 void KiemTraMangTrungHaiSo(int a[], int n)
 {
  int x;
  printf("\nNhap vao so nguyen 2 chu so: ");
  scanf("%d", &x);
  printf("\nCac so trung voi %d la: ", x);
  int dv, chuc;
  dv = x % 10;
  x = x /10;
  chuc = x % 100;
  for(int i = 0; i < n; i++)
  {
    if(KiemTraChuaX(a[i], dv, chuc) == 1)
    {
      printf("%d ", a[i]);
    }
  }
 }

 void SapXepChanTang(int a[], int n)
 {
  for(int i = 0; i < n; i++)
  {
    if(a[i] % 2 == 0)
    {
      for(int j = i + i; j < n; j++)
      {
        if(a[j] % 2 == 0 && a[j] < a[i])
        {
          Swap(a[i], a[j]);
        }
      }
    }
 }
 }
 
 void OddEven(int a[], int n)
 {
   int tam[n + 1]; 
   int i = 0;
   int e = 0, j = 0;
   while(i < n)
   {
    if(a[i] % 2 != 0)
    {
      tam[e] = a[i];
      e++;
    }

    else
    {
      tam[n-j-1] = a[i];
      j++;
    }
    i++;
   }
   for(int t = 0; t < n; t++)
   {
    a[t] = tam[t];
   }
 }

 void _INC_Int_Selection_Sort(int a[], int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < n; j++)
      {
         if(a[j] < a[min])
         {
            min = j;
         }
      }
      if(min != i)
      {
         Swap(a[i], a[min]);
      }
   }
}

 int SoNhoThu2(int a[], int n)
 {
  int tam[MAX_SIZE];
  for(int i = 0; i < n; i++)
  {
    tam[i] = a[i];
  }
  _INC_Int_Selection_Sort(tam, n);
  int min2 = tam[0];
  for(int j = 1; j < n; j++)
  {
    if(tam[j] < tam[j+1])
    {
      min2 = tam[j+1];
      break;
    }
  }
  return min2;
 }
 
 int Tapcondainhat(int a[], int n) {
    int dp[MAX_SIZE];  
    for (int i = 0; i < n; i++) {
        dp[i] = 1; 
    }

    int maxLen = 1;  
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) 
        {
            if (a[i] < a[j] && dp[i] < dp[j] + 1) 
            {
                dp[i] = dp[j] + 1;  
            }
        }
        if (dp[i] > maxLen) 
        {
            maxLen = dp[i];  
        }
    }

    return maxLen;  
}

 int main()
 {
    int a[MAX_SIZE], n = 0;
    NhapMang(a, n);
    XuatMang(a, n);
    LietKeSoNguyenBeN(a);
    printf("\nTong chu so dau le: %d", TongDauLe(a, n));
    printf("\nSo lan xuat hien: %d", LietKeSoLanXH(a, n));
    SapxepChanTangLeGiam(a, n);
    SapXepChanTang(a, n);
    printf("\nTap con dai nhat: %d", Tapcondainhat(a, n));
    OddEven(a, n);
    XuatMang(a, n);
    KiemTraMangTrungHaiSo(a, n);
    printf("\nSo nho thu 2 la: %d", SoNhoThu2(a, n));
    getch();
    return 1;
 }