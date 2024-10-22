#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE_COL 20
#define MAX_SIZE_ROW 20

void MENU()
{
   printf("\n---------------MENU-----------------");
   printf("\n1) Tao/Xuat ma tran ngau nhien n >= 5");
   printf("\n2) Xuat cac phan tu tren duong cheo trinh");
   printf("\n3) Xuat cac phan tu thuoc duong cheo song song voi cheo chinh");
   printf("\n4) Tim max thuoc tam giac tren duong cheo chinh");
   printf("\n5) Sap xep ma tran tang dan kieu ziczac");
   printf("\n6) Sap xep tang dan duong cheo chinh");
   printf("\n0)Thoat chuong trinh !!!");
}

void NhapMaTran(int a[][MAX_SIZE_COL], int &n)
{
   do
   {
      printf("\nNhap vao n: ");
      scanf("%d", &n);
      if (n < 5)
      {
         printf("\nNhap vao so n >= 5 !!!");
      }
   } while (n < 5);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         a[i][j] = rand() % 30;
      }
   }
}

void XuatMaTran(int a[][MAX_SIZE_COL], int n)
{
   printf("\n  --Ma Tran--");
   printf("\n");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         printf("%4d", a[i][j]);
      }
      printf("\n");
   }
}

void XuatPtuCheoChinh(int a[][MAX_SIZE_COL], int n)
{
   printf("\nCac phan tu tren duong cheo chinh la: ");
   for (int e = 0; e < n; e++)
   {
      printf("%d ", a[e][e]);
   }
}

void XuatPtuCheoTrenSSChinh(int a[][MAX_SIZE_COL], int n)
{
   for (int k = 1; k < n; k++)
   {
      for (int i = 0; i < n - k; i++)
      {
         printf("%d ", a[i][i + k]);
      }
      printf("\n");
   }
}

void XuatPtuCheoDuoiSSChinh(int a[][MAX_SIZE_COL], int n)
{
   for (int k = 1; k < n; k++)
   {
      for (int i = 0; i < n - k; i++)
      {
         printf("%d ", a[i + k][i]);
      }
      printf("\n");
   }
}


int MaxTamGiacTren(int a[][MAX_SIZE_COL], int n)
{
    int max = a[0][0]; 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) 
        { 
            if (a[i][j] > max) 
            {
               max = a[i][j];
            }
        }
    }
    return max;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int SapXepGiamDong(int a[][MAX_SIZE_COL], int dong, int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int max = i;
      for(int j = i + 1; j < n; j++)
      {
         if(a[dong][max] < a[dong][j])
         {
            max = j;
         }
      }
      Swap(a[dong][max], a[dong][i]);
   }
   return 1;
}

void SelectionSort_INC(int a[], int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < n; j++)
      {
         if(a[min] > a[j])
         {
            min = j;
         }
      }
      Swap(a[min], a[i]);
   }
}

void SapXepMatranTang(int a[][MAX_SIZE_COL], int n)
{
   int b[MAX_SIZE_ROW];
   int e = 0;
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
      {
         b[e] = a[i][j];
         e++;
      }
   }
   SelectionSort_INC(b, e);
   
   e = 0;
   for(int u = 0; u < n; u++)
   {
      for(int m = 0; m < n; m++)
      {
         a[u][m] = b[e];
         e++;
      }
   }
}

void SapxepTangZicZac(int a[][MAX_SIZE_COL], int n)
{
   SapXepMatranTang(a, n);
   for(int i = 0; i < n; i++)
   {
      if(i % 2 != 0)
      {
         SapXepGiamDong(a, i, n);
      }
   }
}

void SapXepDuongCheoChinhTangDan(int a[][MAX_SIZE_COL], int n)
{
    int duongCheo[MAX_SIZE_ROW];

    for (int i = 0; i < n; i++) {
        duongCheo[i] = a[i][i];
    }

    SelectionSort_INC(duongCheo, n);

    for (int i = 0; i < n; i++) {
        a[i][i] = duongCheo[i];
    }
}

void Option(int a[][MAX_SIZE_COL], int n)
{
   int chon;
   do
   {
      printf("\n\nNhap vao lua chon: ");
      scanf("%d", &chon);
      switch (chon)
      {
      case 1:
      {
         NhapMaTran(a, n);
         XuatMaTran(a, n);
      }
      break;

      case 2:
      {
         XuatPtuCheoChinh(a, n);
      }
      break;

      case 3:
      {
         printf("Cac phan tu tren dg cheo song song voi cheo chinh\n");
         XuatPtuCheoTrenSSChinh(a, n);
         printf("\n");
         XuatPtuCheoDuoiSSChinh(a, n);
      }
      break;

      case 4:
      {
         printf("\nPhan tu max thuoc tam gia tren la: %d", MaxTamGiacTren(a, n));
      }
      break;

      case 5:
      {
         SapxepTangZicZac(a, n);
         XuatMaTran(a, n);
      }
      break;

      case 6:
      {
         SapXepDuongCheoChinhTangDan(a, n);
         XuatMaTran(a, n);
      }
      break;

      case 0:
      {
         printf("\nThoat chuong trinh !!!");
      }
      break;

      default:
         printf("\nKiem tra lai lua chon !!!");
         break;
      }
   } while (chon != 0);
}

int main()
{
   int n = 0;
   int a[MAX_SIZE_ROW][MAX_SIZE_COL];
   MENU();
   Option(a, n);
   getch();
   return 1;
}
