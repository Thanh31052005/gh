#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAX_SIZE_COL 20
#define MAX_SIZE_ROW 20


void NhapMaTran(int a[][MAX_SIZE_COL], int &dong, int &cot)
{
 printf("\nNhap vao so dong: ");
 scanf("%d", &dong);
 printf("\nNhap vao so cot: ");
 scanf("%d", &cot);

   for (int i = 0; i < dong; i++)
   {
      for (int j = 0; j < cot; j++)
      {
         a[i][j] = rand() % 30;
      }
   }
}

void XuatMaTran(int a[][MAX_SIZE_COL], int dong, int cot)
{
   printf("\n  --Ma Tran--");
   printf("\n");
   for (int i = 0; i < dong; i++)
   {
      for (int j = 0; j < cot; j++)
      {
         printf("%4d", a[i][j]);
      }
      printf("\n");
   }
}
 
 void Swap(int &a, int &b)
{
   int nho = a;
   a = b;
   b = nho;
}

 int SapXepTangDong(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < cot; j++)
      {
         if(a[dong][min] > a[dong][j])
         {
            min = j;
         }
      }
      Swap(a[dong][min], a[dong][i]);
   }
   return 1;
}

int SapXepGiamDong(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot - 1; i++)
   {
      int max = i;
      for(int j = i + 1; j < cot; j++)
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


 int KiemTraCotLe(int a[][MAX_SIZE_COL], int dong, int cot)
 {
   for(int i = 0; i < dong; i++)
   {
      if(a[i][cot] % 2 == 0)
      {
         return 0;
      }
   }
   return 1;
 }

void XuatCot(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < dong; i++)
   {
      printf("\n[%d]", a[i][cot]);
   }
   printf("\n");
}

void XuatCacCotLe(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot; i++)
   {
      if(KiemTraCotLe(a, dong, i) == 1)
      {
         XuatCot(a, dong, i);
      }
   }
}

int TimMaxBien(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int max = a[0][0];
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(i == 0 || i == dong - 1 || j == 0 || j == cot - 1)
         {
            if(max < a[i][j])
            {
               max = a[i][j];
            }
         }
      }
   }
   return max;
}

int KtraSo2(int x)
{
   while (x)
   {
      int dv = x % 10;
      if(dv == 2)
      {
         return 1;
      }
      x = x / 10;
   }
   return 0;
}

int DemPtuCoChuSo2(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int dem = 0;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(KtraSo2(a[i][j]) == 1)
         {
            dem++;
         }
      }
   }
   return dem;
}

int KtraCucTieu(int a[][MAX_SIZE_COL], int dong, int cot, int i, int j)
{
   int ht = a[i][j];
   if(ht > a[i - 1][j] && i - 1 >= 0) return 0;
   if(ht > a[i + 1][j] && i + 1 < dong) return 0;
   if(ht > a[i][j + 1] && j + 1 < cot) return 0;
   if(ht > a[i][j - 1] && j - 1 >= 0) return 0;
   if(ht > a[i - 1][j - 1] && i - 1 >= 0 && j - 1 >= 0) return 0;
   if(ht > a[i + 1][j + 1] && i + 1 < dong && j + 1 < cot) return 0;
   if(ht > a[i - 1][j + 1] && i - 1 >= 0 && j + 1 < cot) return 0;
   if(ht > a[i + 1][j - 1] && i + 1 < dong && j - 1 >= 0) return 0;
   return 1;
}

void XuatCacCucTieu(int a[][MAX_SIZE_COL], int dong, int cot)
{
   printf("\nCuc tieu ma tran\n");
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(KtraCucTieu(a, dong, cot, i , j) == 1)
         {
            printf("[%d] ", a[i][j]);
         }
      }
   }
}

void SapxepDongChanGiamLeTang(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < dong; i++)
   {
      if(i % 2 != 0)
      {
         SapXepTangDong(a, i, cot);
      }

      else
      {
         SapXepGiamDong(a, i, cot);
      }
   }
}

int KiemTraDongChan(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot; i++)
   {
      if(a[dong][i] % 2 != 0)
      {
         return 0;
      }
   }
   return 1;
}

void XuatDong(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot; i++)
   {
      printf("[%d] ", a[dong][i]);
   }
   printf("\n");
}

void XuatCacDongChan(int a[][MAX_SIZE_COL], int dong, int cot)
{
   printf("\nDong toan chan: ");
   for(int i = 0; i < dong; i++)
   {
      if(KiemTraDongChan(a, i, cot) == 1)
      {
         XuatDong(a, i , cot);
      }
   }
}

int KiemTraDongGiamDan(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot - 1; i++)
   {
      if(a[dong][i] < a[dong][i + 1])
      {
         return 0;
      }
   }
   return 1;
}

void XuatCacDongGiamDan(int a[][MAX_SIZE_COL], int dong, int cot)
{
   printf("\nDong giam dan: ");
   for(int i = 0; i < dong; i++)
   {
      if(KiemTraDongGiamDan(a, i, cot) == 1)
      {
         XuatDong(a, i , cot);
      }
   }
}

int TinhTongCotDau(int a[][MAX_SIZE_COL], int dong)
{
   int tong = 0;
   for(int i = 0; i < dong; i++)
   {
      tong += a[i][0];
   }
   return tong;
}

void LietKeCotTongNho(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int min = 0;
   int tong1 = TinhTongCotDau(a, dong);
   int i = 1;
   for(i; i < cot; i++)
   {
      int tong2 = 0;
      for(int j = 0; j < dong; j++)
      {
         tong2 += a[j][i];
      }

      if(tong1 > tong2)
      {
         tong1 = tong2;
         min = i;
      }
   }

   for(int e = 0; e < dong; e++)
   {
      printf("[%d]\n", a[e][min]);
   }
}

int DemPtuMatran(int a[][MAX_SIZE_COL], int dong, int cot, int x)
{
   int dem = 0;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(a[i][j] == x)
         {
            dem++;
         }
      }
   }
   return dem;
}

int GiaTriXuatHienNhieuNhat(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int max1 = DemPtuMatran(a, dong, cot, a[0][0]);
   int maxptu = a[0][0];
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         int max2 = DemPtuMatran(a, dong, cot, a[i][j]);
         if(max1 < max2)
         {
            max1 = max2;
            maxptu = a[i][j];
         }
      }
   }
   return maxptu;
}

int TimSoXuatHienNhieuNhat(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int ktr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         int x = a[i][j];
         while(x)
         {
            int dv = x % 10;
            for(int e = 0; e < 10; e++)
            {
               if(e == dv)
               {
                  ktr[e]++;
                  break;
               }
            }
            x = x / 10;
         }
      }
   }
 int solon = ktr[0];
 int vtri = 0;
 for(int u = 1; u < 10; u++)
 {
   if(solon < ktr[u])
   {
      solon = ktr[u];
      vtri = u;
   }
 }
 return vtri;
}

void HoanViCoti_j(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int i, j;
   printf("Nhap vao cot i: ");
   scanf("%d", &i);
   printf("Nhap vao cot j: ");
   scanf("%d", &j);

   for(int e = 0; e < dong; e++)
   {
      Swap(a[e][i], a[e][j]);
   }
}

void HoanViDongk_l(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int k, l;
   printf("Nhap vao cot i: ");
   scanf("%d", &k);
   printf("Nhap vao cot j: ");
   scanf("%d", &l);

   for(int e = 0; e < cot; e++)
   {
      Swap(a[k][e], a[l][e]);
   }
}

void MENU()
{
   printf("\n--------------------MENU----------------------");   
   printf("\n1) Xuat cac cot le");
   printf("\n2) Tim phan tu max tren bien");
   printf("\n3) Dem phan tu co chu so 2 xuat hien trong ptu");
   printf("\n4) Xuat cac cuc tieu ma tran");
   printf("\n5) Sap xep ma tran dong chan giam, le tang");
   printf("\n6) Kiem tra trong ma tran giam dong/cot (ziczac)");
   printf("\n7) Liet Ke dong chua toan chan");
   printf("\n8) Liet ke dong giam dan");
   printf("\n9) Tim gia tri xuat hien nhieu nhat");
   printf("\n10) Tim so xuat hien nhieu nhat");
   printf("\n11) Liet ke cot tong nho nhat");
   printf("\n12) Hoan vi cot i va j");
   printf("\n13) Hoan vi dong k va l");
   printf("\n0) Thoat chuong trinh !!!");
}

void Option(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int chon;
      NhapMaTran(a, dong, cot);
      XuatMaTran(a, dong, cot);
   do
   {
      printf("\n\nNhap vao lua chon: ");
      scanf("%d", &chon);
      switch (chon)
      {
         case 1:
         {
            printf("\nCac cot le la\n");
            XuatCacCotLe(a, dong, cot);
         }
         break;

         case 2:
         {
            printf("\nPhan tu lon nhat tren bien ma tran la: %d", TimMaxBien(a, dong, cot));
         }
         break;

         case 3:
         {
            printf("\nCo %d phan tu co chu so 2", DemPtuCoChuSo2(a, dong, cot));
         }
         break;

         case 4:
         {
            XuatCacCucTieu(a, dong, cot);
         }
         break;

         case 5:
         {
            SapxepDongChanGiamLeTang(a, dong, cot);
            XuatMaTran(a, dong ,cot);
         }
         break;

         case 6:
         {
            
         }
         break;

         case 7:
         {
            XuatCacDongChan(a, dong, cot);
         }
         break;

         case 8:
         {
           XuatCacDongGiamDan(a, dong, cot); 
         }
         break;

         case 9:
         {
            printf("\nGia tri xuat hien nhieu nhat: %d", GiaTriXuatHienNhieuNhat(a, dong, cot));
         }
         break;

         case 10:
         {
            printf("\nSo xuat hien nhieu nhat la: %d", TimSoXuatHienNhieuNhat(a, dong, cot));
         }
         break;

         case 11:
         {
            LietKeCotTongNho(a, dong, cot);
         }
         break;

         case 12:
         {
            HoanViCoti_j(a, dong, cot);
            XuatMaTran(a, dong, cot);
         }
         break;

         case 13:
         {
            HoanViDongk_l(a, dong, cot);
            XuatMaTran(a, dong, cot);
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
   int a[MAX_SIZE_ROW][MAX_SIZE_COL];
   int dong = 0, cot = 0;
   MENU();
   Option(a, dong, cot);
   getch();
   return 1;
 }