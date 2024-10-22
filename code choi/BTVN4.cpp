#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE_COL 20
#define MAX_SIZE_ROW 20

void MENU();
void Option(int a[][MAX_SIZE_COL], int dong, int cot);
void DocFileTxt(int a[][MAX_SIZE_COL], int &dong, int &cot, char tenfile[40]);
void XuatMaTran(int a[][MAX_SIZE_COL], int dong, int cot);
void Swap(int &a, int &b);
int SapXepTangDong(int a[][MAX_SIZE_COL], int dong, int cot);
int SapXepGiamDong(int a[][MAX_SIZE_COL], int dong, int cot);
void SapxepDongChanTangLeGiam(int a[][MAX_SIZE_COL], int dong, int cot);
int SapXepTangCot(int a[][MAX_SIZE_COL], int dong, int cot);
int SapXepGiamCot(int a[][MAX_SIZE_COL], int dong, int cot);
void SapxepCotChanTangLeGiam(int a[][MAX_SIZE_COL], int dong, int cot);
void SelectionSort_INC(int a[], int n);
void SelectionSort_DEC(int a[], int n);
void SapXepMatranTang(int a[][MAX_SIZE_COL], int dong, int cot);
void SapXepMatranGiam(int a[][MAX_SIZE_COL], int dong, int cot);
void SapxepTangZicZac(int a[][MAX_SIZE_COL], int dong, int cot);
void SapxepGiamZicZac(int a[][MAX_SIZE_COL], int dong, int cot);
void MenuMaTranVuong();
int TongPhanTuCheoChinh(int a[][MAX_SIZE_COL], int dong, int cot);
int TongPhanTuCheoPhu(int a[][MAX_SIZE_COL], int dong, int cot);
int TongPhanTuPhiaTrenCheoChinh(int a[][MAX_SIZE_COL], int dong, int cot); // chua xong
int TongPhanTuPhiaTrenCheoPhu(int a[][MAX_SIZE_COL], int dong, int cot); // chua xong
int KiemTraCotLe(int a[][MAX_SIZE_COL], int dong, int cot);
void XuatCot(int a[][MAX_SIZE_COL], int dong, int cot);
void XuatCacCotLe(int a[][MAX_SIZE_COL], int dong, int cot);
int TimMaxBien(int a[][MAX_SIZE_COL], int dong, int cot);
int KtraSo2(int x);
int DemPtuCoChuSo2(int a[][MAX_SIZE_COL], int dong, int cot);
int KtraCucTieu(int a[][MAX_SIZE_COL], int dong, int cot, int i, int j);
void XuatCacCucTieu(int a[][MAX_SIZE_COL], int dong, int cot);
void SapxepDongChanGiamLeTang(int a[][MAX_SIZE_COL], int dong, int cot);
int KiemTraDongChan(int a[][MAX_SIZE_COL], int dong, int cot);
void XuatDong(int a[][MAX_SIZE_COL], int dong, int cot);
void XuatCacDongChan(int a[][MAX_SIZE_COL], int dong, int cot);
int KiemTraDongGiamDan(int a[][MAX_SIZE_COL], int dong, int cot);
void XuatCacDongGiamDan(int a[][MAX_SIZE_COL], int dong, int cot);
int DemPtuMatran(int a[][MAX_SIZE_COL], int dong, int cot, int x);
int GiaTriXuatHienNhieuNhat(int a[][MAX_SIZE_COL], int dong, int cot);
int TimSoXuatHienNhieuNhat(int a[][MAX_SIZE_COL], int dong, int cot);
int TinhTongCotDau(int a[][MAX_SIZE_COL], int dong);
void LietKeCotTongNho(int a[][MAX_SIZE_COL], int dong, int cot);
void HoanViCoti_j(int a[][MAX_SIZE_COL], int dong, int cot);
void HoanViDongk_l(int a[][MAX_SIZE_COL], int dong, int cot);


int main()
{
   int a[MAX_SIZE_ROW][MAX_SIZE_COL];
   int dong = 0, cot = 0;
   MENU();
   Option(a, dong, cot);
   getch();
   return 1;
}

void MenuMaTranVuong()
{
   printf("\n1) Doc ma tran vuong tu file/Xuat ma tran");
   printf("\n2) Tinh tong tren duong cheo chinh");
   printf("\n3) Tinh tong tren duong cheo phu");
   printf("\n4) Tinh tong phia tren duong cheo chinh");
   printf("\n5) Tinh tong phia tren duong cheo phu");
   printf("\n0) Thoat chuong trinh ma tran vuong");
}

void DocFileTxt(int a[][MAX_SIZE_COL], int &dong, int &cot, char tenfile[40])
{
   FILE *f = fopen(tenfile, "r");
   if (f == NULL)
   {
      printf("\nKhong the mo file");
      return;
   }
   fscanf(f, "%d\n", &dong);
   fscanf(f, "%d\n\n", &cot);
   for (int i = 0; i < dong; i++)
   {
      for (int j = 0; j < cot; j++)
      {
         fscanf(f, "%d\n", &a[i][j]);
      }
   }
   fclose(f);
   printf("\nDa doc xong !!!");
}

void XuatMaTran(int a[][MAX_SIZE_COL], int dong, int cot)
{
   printf("\n--Ma Tran--");
   printf("\n");
   for (int i = 0; i < dong; i++)
   {
      for (int j = 0; j < cot; j++)
      {
         printf("[%d] ", a[i][j]);
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

void SapxepDongChanTangLeGiam(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < dong; i++)
   {
      if(i % 2 == 0)
      {
         SapXepTangDong(a, i, cot);
      }

      else
      {
         SapXepGiamDong(a, i, cot);
      }
   }
}

int SapXepTangCot(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < dong - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < dong; j++)
      {
         if(a[min][cot] > a[j][cot])
         {
            min = j;
         }
      }
      Swap(a[min][cot], a[i][cot]);
   }
   return 1;
}

int SapXepGiamCot(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < dong - 1; i++)
   {
      int max = i;
      for(int j = i + 1; j < dong; j++)
      {
         if(a[max][cot] < a[j][cot])
         {
            max = j;
         }
      }
      Swap(a[max][cot], a[i][cot]);
   }
   return 1;
}

void SapxepCotChanTangLeGiam(int a[][MAX_SIZE_COL], int dong, int cot)
{
   for(int i = 0; i < cot; i++)
   {
      if(i % 2 == 0)
      {
         SapXepTangCot(a, dong, i);
      }

      else 
      {
         SapXepGiamCot(a, dong , i);
      }
   }
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

void SapXepMatranTang(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int b[MAX_SIZE_ROW];
   int e = 0;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         b[e] = a[i][j];
         e++;
      }
   }
   SelectionSort_INC(b, e);
   
   e = 0;
   for(int n = 0; n < dong; n++)
   {
      for(int m = 0; m < cot; m++)
      {
         a[n][m] = b[e];
         e++;
      }
   }
}

void SapxepTangZicZac(int a[][MAX_SIZE_COL], int dong, int cot)
{
   SapXepMatranTang(a, dong, cot);
   for(int i = 0; i < dong; i++)
   {
      if(i % 2 != 0)
      {
         SapXepGiamDong(a, i, cot);
      }
   }
}

void SelectionSort_DEC(int a[], int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int max = i;
      for(int j = i + 1; j < n; j++)
      {
         if(a[max] < a[j])
         {
            max = j;
         }
      }
      Swap(a[max], a[i]);
   }
}

void SapXepMatranGiam(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int b[MAX_SIZE_ROW];
   int e = 0;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         b[e] = a[i][j];
         e++;
      }
   }
   SelectionSort_DEC(b, e);
   
   e = 0;
   for(int n = 0; n < dong; n++)
   {
      for(int m = 0; m < cot; m++)
      {
         a[n][m] = b[e];
         e++;
      }
   }
}

void SapxepGiamZicZac(int a[][MAX_SIZE_COL], int dong, int cot)
{
   SapXepMatranGiam(a, dong, cot);
   for(int i = 0; i < dong; i++)
   {
      if(i % 2 != 0)
      {
         SapXepTangDong(a, i, cot);
      }
   }
}

int TongPhanTuCheoChinh(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int tong = a[0][0];
   int i = 1, j = 1;
    while(i < dong && j < cot)
    {
      tong += a[i][j];
      i++;
      j++;
    }
   return tong;
}

int TongPhanTuCheoPhu(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int tong = a[0][cot - 1];
   int i = dong - 2, j = cot - 2;
    while(i < dong && j >= 0)
    {
      tong += a[i][j];
      i++;
      j--;
    }
   return tong;
}

int TongPhanTuPhiaTrenCheoChinh(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int tong = 0;
   int e = 0;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(j > e)
         {
            tong += a[i][j];
         }
      }
      e++;
   }
   return tong;
}

int TongPhanTuPhiaTrenCheoPhu(int a[][MAX_SIZE_COL], int dong, int cot)
{
   int tong = 0;
   int e = cot - 1;
   for(int i = 0; i < dong; i++)
   {
      for(int j = 0; j < cot; j++)
      {
         if(j < e)
         {
            tong += a[i][j];
         }
      }
      e--;
   }
   return tong;
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
   printf("\n1) Doc file Text/Xuat ma tran");
   printf("\n2) Sap xep ma tran dong chan tang, le giam");
   printf("\n3) Sap xep ma tran cot chan tang, le giam");
   printf("\n4) Sap xep ma tran tang/giam theo ziczac");
   printf("\n5) Lam viec voi ma tran vuong");
   
   printf("\n6) Xuat cac cot le");
   printf("\n7) Tim phan tu max tren bien");
   printf("\n8) Dem phan tu co chu so 2 xuat hien trong ptu");
   printf("\n9) Xuat cac cuc tieu ma tran");
   printf("\n10) Sap xep ma tran dong chan giam, le tang");
   printf("\n11) Kiem tra trong ma tran giam dong/cot (ziczac)");
   printf("\n12) Liet Ke dong chua toan chan");
   printf("\n13) Liet ke dong giam dan");
   printf("\n14) Tim gia tri xuat hien nhieu nhat");
   printf("\n15) Tim so xuat hien nhieu nhat");
   printf("\n16) Liet ke cot tong nho nhat");
   printf("\n17) Hoan vi cot i va j");
   printf("\n18) Hoan vi dong k va l");
   printf("\n0) Thoat chuong trinh !!!");
}

void Option(int a[][MAX_SIZE_COL], int dong, int cot)
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
            char tenfile[40] = "../Data/Matran.txt";
            DocFileTxt(a, dong, cot, tenfile);
            XuatMaTran(a, dong, cot);
         }
         break;
   
         case 2:
         {
            SapxepDongChanTangLeGiam(a, dong, cot);
            XuatMaTran(a, dong, cot);
         }
         break;
   
         case 3:
         {
            SapxepCotChanTangLeGiam(a, dong, cot);
            XuatMaTran(a, dong, cot);
         }
         break;
   
         case 4:
         {
            printf("\nZICZAC TANG");
            SapxepTangZicZac(a, dong, cot);
            XuatMaTran(a, dong, cot);
            printf("\nZICZAC GIAM");
            SapxepGiamZicZac(a, dong, cot);
            XuatMaTran(a, dong, cot);
         }
         break;
   
         case 5:
         {
            printf("\n---------------------------------------");
            MenuMaTranVuong();
            int MTV[MAX_SIZE_ROW][MAX_SIZE_COL];
            int chon1;
            do
            {
              printf("\n\nNhap vao lua chon ma tran vuong: ");
              scanf("%d", &chon1);
              switch(chon1)
              {
               case 1:
               {
                  char tenFileVuong[30] = "../Data/MatranVuong.txt";
                  DocFileTxt(MTV, dong, cot, tenFileVuong);
                  XuatMaTran(MTV, dong, cot);
               }
               break;

               case 2:
               {
                  printf("\nTong duong cheo chinh: %d", TongPhanTuCheoChinh(MTV, dong, cot));
               }
               break;

               case 3:
               {
                  printf("\nTong duong cheo phu: %d", TongPhanTuCheoPhu(MTV, dong, cot));
               }
               break;

               case 4:
               {
                  printf("\nTong phan tu tren duong cheo chinh: %d", TongPhanTuPhiaTrenCheoChinh(MTV, dong, cot));
               }
               break;

               case 5:
               {
                  printf("\nTong phan tu tren duong cheo phu: %d", TongPhanTuPhiaTrenCheoPhu(MTV , dong, cot));
               }
               break;

               case 0:
               {
                  printf("\nThoat ma tran vuong !!!");
               }
               break;

               default : printf("\nKiem tra lai lua chon !!!");
               break;
              }
            } while (chon1 != 0);   
            printf("\n---------------------------------------");     
         }
         break;

         case 6:
         {
            printf("\nCac cot le la\n");
            XuatCacCotLe(a, dong, cot);
         }
         break;

         case 7:
         {
            printf("\nPhan tu lon nhat tren bien ma tran la: %d", TimMaxBien(a, dong, cot));
         }
         break;

         case 8:
         {
            printf("\nCo %d phan tu co chu so 2", DemPtuCoChuSo2(a, dong, cot));
         }
         break;

         case 9:
         {
            XuatCacCucTieu(a, dong, cot);
         }
         break;

         case 10:
         {
            SapxepDongChanGiamLeTang(a, dong, cot);
            XuatMaTran(a, dong ,cot);
         }
         break;

         case 11:
         {
            
         }
         break;

         case 12:
         {
            XuatCacDongChan(a, dong, cot);
         }
         break;

         case 13:
         {
           XuatCacDongGiamDan(a, dong, cot); 
         }
         break;

         case 14:
         {
            printf("\nGia tri xuat hien nhieu nhat: %d", GiaTriXuatHienNhieuNhat(a, dong, cot));
         }
         break;

         case 15:
         {
            printf("\nSo xuat hien nhieu nhat la: %d", TimSoXuatHienNhieuNhat(a, dong, cot));
         }
         break;

         case 16:
         {
            LietKeCotTongNho(a, dong, cot);
         }
         break;

         case 17:
         {
            HoanViCoti_j(a, dong, cot);
            XuatMaTran(a, dong, cot);
         }
         break;

         case 18:
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