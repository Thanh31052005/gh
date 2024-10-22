#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 50

struct PhanSo
{
    int tu;
    int mau;
};

struct HonSo
{
    int nguyen;
    PhanSo pso;
};

void MENU()
{
    printf("\n1) Tao mang hon so ngau nhien");
    printf("\n2) Xuat Mang");
    printf("\n3) Tim hon so x trong mang theo linear search");
    printf("\n4) Sap xep nguyen chan len dau, nguyen le xuong duoi");
    printf("\n5) Tim hon so x trong mang theo binary search");
    printf("\n6) Chia 2 mang s1 chua nguyen, s2 chua pso");
    printf("\n7) Xoa phan tu thu k");
    printf("\n8) Them hon so vao vtri k");
    printf("\n9) Tao mang c chua phan so doi tu hso mang b");
    printf("\n10) Tinh tong phan tu");
    printf("\n11) Tim phan tu lon/nho nhat");
    printf("\n0) Thoat chuong trinh !!");
}

void TaoMang(HonSo a[], int &n)
{
    printf("\nNhap vao so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i].nguyen = rand() % 20 + 2;
        a[i].pso.tu = rand() % 20;
        a[i].pso.mau = (rand() % 20) + 1;
    }
}

void XuatMang(HonSo a[], int n)
{
    printf("\nPhan tu mang a: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d/%d  ", a[i].nguyen, a[i].pso.tu, a[i].pso.mau);
    }
}

PhanSo ChuyenThanhPS(HonSo a)
{
    PhanSo p;
    p.tu = (a.nguyen * a.pso.mau) + a.pso.tu;
    p.mau = a.pso.mau;
    return p;
}

int SoSanhHonSo(HonSo a, HonSo b)
{
    PhanSo na, nb;
    na = ChuyenThanhPS(a);
    nb = ChuyenThanhPS(b);
    na.tu = na.tu * nb.mau;
    nb.tu = nb.tu * na.mau;
    if (na.tu < nb.tu) // a < b
        return 1;
    else if (na.tu == nb.tu) // a = b
        return 0;
    else
        return -1;
}

void XuatMangHS_PS(HonSo a[], int n)
{
    printf("\nDanh sach phan so: ");
    for (int i = 0; i < n; i++)
    {
        PhanSo t = ChuyenThanhPS(a[i]);
        printf("%d/%d ", t.tu, t.mau);
    }
}

HonSo ChuyenThanhHS(PhanSo ps)
{
    HonSo hs;
    hs.nguyen = ps.tu / ps.mau;
    ps.tu = ps.tu % ps.mau;
    hs.pso = ps;
    return hs;
}

int TimKiemLinear(HonSo a[], int n , HonSo x)
{
    for(int i = 0; i < n ; i++)
    {
        if(a[i].nguyen == x.nguyen && a[i].pso.tu == x.pso.tu && a[i].pso.mau == x.pso.mau)
        {
            return i;
        }
    }
    return -1;
}

void EvenOdd(HonSo a[], int n)
{
   HonSo tam[n + 1]; 
   int i = 0;
   int e = 0, j = 0;
   while(i < n)
   {
    if(a[i].nguyen % 2 == 0)
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

void Swap(HonSo &a, HonSo &b)
{
   HonSo nho = a;
   a = b;
   b = nho;
}

void SapXepMangTang(HonSo a[], int n)
{
   for(int i = 0; i < n - 1; i++)
   {
      int min = i;
      for(int j = i + 1; j < n; j++)
      {
         if(SoSanhHonSo(a[j], a[min]) == 1)
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

int TimKiemBinary(HonSo a[], int n, HonSo x) 
{
   int L = 0, R = n - 1;
   while (L <= R)
   {
      int M = (L + R) / 2;
      if (SoSanhHonSo(a[M], x) == 0)
      {
        return M;
      }

      else if (SoSanhHonSo(x, a[M]) == 1)
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

void ChiaMangS1S2(HonSo a[], int n)
{
    int S1[MAX_SIZE];
    PhanSo S2[MAX_SIZE];
    for(int i = 0; i < n; i++)
    {
        S1[i] = a[i].nguyen;
        S2[i] = a[i].pso;
    }

    printf("\nPhan Nguyen: ");
    for(int j = 0; j < n; j++)
    {
        printf("%d ", S1[j]);
    }

    printf("\nPhan Phan So: ");
    for(int e = 0; e < n; e++)
    {
        printf("%d/%d ", S2[e].tu, S2[e].mau);
    }
}

int XoaTaiK(HonSo a[], int &n)
{
    int k;
    printf("\nNhap vao vtri can xoa : ");
    scanf("%d", &k);
    for (int i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}

int ThemTaiK(HonSo a[], int &n, HonSo x)
{
    int k;
    int nho;
    printf("\nNhap vtri can them : ");
    scanf("%d", &k);
    if(n == 0)
    {
        a[0] = x;
        n++;
        return 1;
    }

    for (int i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
    return 1;
}

void TaoMangChuaPS(HonSo a[], int n, PhanSo c[])
{
    for(int i = 0; i < n; i++)
    {
        c[i] = ChuyenThanhPS(a[i]);
    }
    
    printf("\nPhan So Mang C: ");
    for(int j = 0; j < n; j++)
    {
        printf("%d/%d ", c[j].tu, c[j].mau);
    }
}

PhanSo TinhTong(PhanSo a, PhanSo b)
{
 PhanSo tong;
 tong.tu = (a.tu * b.mau) + (b.tu * a.mau);
 tong.mau = a.mau * b.mau;
 return tong;
}

PhanSo TongMang(HonSo a[], int n)
{
    PhanSo tong = ChuyenThanhPS(a[0]);
    for(int i = 1; i < n; i++)
    {
        tong = TinhTong(tong, ChuyenThanhPS(a[i]));
    }
    return tong;
}

void MaxMin(HonSo a[], int n)
{
    HonSo max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(SoSanhHonSo(max, a[i]) == 1)
        {
            max = a[i];
        }
    }
    printf("\nSo lon nhat la: %d %d/%d", max.nguyen, max.pso.tu, max.pso.mau);

    HonSo min = a[0];
    for(int j = 1; j < n; j++)
    {
        if(SoSanhHonSo(min, a[j]) == -1)
        {
            min = a[j];
        }
    }
    printf("\nSo nho nhat la %d %d/%d", min.nguyen, min.pso.tu, min.pso.mau);
}


void Option(HonSo a[], int n)
{
    int nho = 1, chon;
    while (nho)
    {
        printf("\nNhap vao lua chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
        {
            TaoMang(a, n);
        }
        break;

        case 2:
        {
            XuatMang(a, n);
        }
        break;

        case 3:
        {
            HonSo x;
            printf("\nTIM KIEM LINEAR");
            printf("\nNhap vao phan nguyen: ");
            scanf("%d", &x.nguyen);
            printf("\nNhap vao tu: ");
            scanf("%d", &x.pso.tu);
            printf("\nNhap vao phan mau: ");
            scanf("%d", &x.pso.mau);
            if(TimKiemLinear(a, n, x) != -1)
            {
                printf("\nHon so %d %d/%d tim thay vi tri %d", x.nguyen, x.pso.tu, x.pso.mau, TimKiemLinear(a, n, x));
            }
            
            else printf("\nKhong tim thay hon so !!!");
        }
        break;

        case 4:
        {
            EvenOdd(a, n);
            XuatMang(a, n);
        }
        break;

        case 5:
        {
            printf("\nTIM KIEM BINARY");
            SapXepMangTang(a, n);
            printf("\n\n Mang da duoc sap xep tang !!");
            HonSo x;
            printf("\nNhap vao phan nguyen: ");
            scanf("%d", &x.nguyen);
            printf("\nNhap vao tu: ");
            scanf("%d", &x.pso.tu);
            printf("\nNhap vao phan mau: ");
            scanf("%d", &x.pso.mau);
            if(TimKiemBinary(a, n, x) != -1)
            {
                printf("\nHon so %d %d/%d tim thay vi tri %d", x.nguyen, x.pso.tu, x.pso.mau, TimKiemBinary(a, n, x));
            }
            
            else printf("\nKhong tim thay hon so !!!");

        }
        break;

        case 6:
        {
            ChiaMangS1S2(a, n);
        }
        break;

        case 7:
        {
            XoaTaiK(a, n);
            XuatMang(a, n);
        }
        break;

        case 8:
        {
            HonSo x;
            printf("\nNhap vao gia tri X");
            printf("\nNhap vao phan nguyen: ");
            scanf("%d", &x.nguyen);
            printf("\nNhap vao tu: ");
            scanf("%d", &x.pso.tu);
            printf("\nNhap vao phan mau: ");
            scanf("%d", &x.pso.mau);
            ThemTaiK(a, n, x);
            XuatMang(a, n);
        }
        break;

        case 9:
        {
            PhanSo c[MAX_SIZE];
            TaoMangChuaPS(a, n, c);
        }
        break;

        case 10:
        {
            PhanSo tong = TongMang(a, n);
            printf("\nTong mang la: %d/%d", tong.tu, tong.mau);
        }
        break;

        case 11:
        {
            MaxMin(a, n);
        }
        break;

        default:
        {
            printf("\nThoat chuong trinh !!!");
            nho = 0;
        }
        break;
        }
    }
}

int main()
{
    int n = 0;
    HonSo a[MAX_SIZE];
    MENU();
    Option(a, n);
    getch();
    return 0;
}