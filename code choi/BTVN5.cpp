#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

 void MENU();
 void Option(char *&a);
 void NhapChuoi(char *&a);
 void XuatChuoi(char *a);
 int DemKhoangTrang(char *a);
 void XoaKiTu(char *&a, int k);
 void XoaKhoangTrangThua(char *&a);
 void DoiKyTuHoaDau(char *&a);
 int TimKiemTen(char *a);
 int DemKhoangTrang(char *a);
 void CatChuoiHoTen(char *a);

 int main()
 {
    char *a;
    MENU();
    Option(a);
    getch();
    return 1;
 }

 void NhapChuoi(char *&a)
 {
    a = (char *)malloc(MAX_SIZE * sizeof(char));
    rewind(stdin);
    printf("\nNhap vao chuoi: ");
    fgets(a, MAX_SIZE, stdin);
 }

 void XuatChuoi(char *a)
 {
    printf("\nChuoi la: %s", a);
 }
 
 int DemKhoangTrang(char *a)
 {
    int tong = 0;
    for(int i = 0; i < strlen(a); i++)
    {
        if(*(a + i) == ' ')
        {
            tong++;
        }
    }
    return tong;
 }
 
 void XoaKiTu(char *&a, int k)
 {
    for(int i = k; i < strlen(a) - 1; i++)
    {
        a[i] = a[i + 1];
    }
 }
 
 void XoaKhoangTrangThua(char *&a)
 {
    for(int i = 0; i < strlen(a) - 1; i++)
    {
       if(a[i] == ' ' && a[i + 1] == ' ')
       {
         XoaKiTu(a, i);
         if(a[i] == ' ')
         {
            XoaKiTu(a, i);
         }
       }
    }
 }
 
 void DoiKyTuHoaDau(char *&a)
 {
    if(a[0] >= 97 && a[0] <= 122)
    {
        a[0] = a[0] - 32;
    }

    for(int i = 1; i < strlen(a); i++)
    {
        if(a[i - 1] == ' ' && a[i] >= 97 && a[i] <= 122)
        {
            a[i] = a[i] - 32;
        }

        if(a[i - 1] != ' ' && a[i] >= 65 && a[i] <= 90)
        {
            a[i] = a[i] + 32;
        }
    }
 }

 int TimKiemTen(char *a)
 {
    char ten[MAX_SIZE];
    rewind(stdin);
    printf("\nNhap vao ten can tim kiem: ");
    fgets(ten, MAX_SIZE, stdin);
    int nho[MAX_SIZE], n = 0;
    for(int i = 0; i < strlen(a); i++)
    {
        if(a[i] == ten[0])
        {
            int u = 1;
            int e = i + 1;
            while(a[e] != ' ')
            {
                if(a[e] != ten[u])
                {
                    break;
                }
                e++;
                u++;
                if(a[e] == ' ' && ten[u] == '\n')
                {
                    return 1;
                }
            }
            
        }
    }
    return 0;
 }

 void CatChuoiHoTen(char *a)
 {
    char HoLot[MAX_SIZE], Ten[MAX_SIZE];
    int khoantrang = DemKhoangTrang(a);
    int i = 0, j = 0;
    while(khoantrang != 0)
    {
        HoLot[i] = a[i];
        if(a[i] == ' ')
        {
          khoantrang--;   
        }
        i++;
    }
    
    while(a[i] != '\n')
    {
        Ten[j] = a[i];
        j++;
        i++;
    }
    printf("\nHo lot: %s", HoLot);
    printf("\nTen: %s", Ten);
 }
 
 void MENU()
 {
    printf("\n---------------MENU-----------------");
    printf("\n1) Nhap/Xuat chuoi");
    printf("\n2) Dem co bao nhieu khoang trang");
    printf("\n3) Xoa khoang trang thua");
    printf("\n4) Doi ki tu dau thanh in hoa va cac chu khac thuong");
    printf("\n5) Tim kiem ten trong chuoi ho va ten");
    printf("\n6) Cat chuoi ho lot va ten");
    printf("\n0) Thoat chuong trinh");
 }

 void Option(char *&a)
 {
    int chon;
    do
    {
        printf("\n\nNhap vao lua chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1: 
            {
                NhapChuoi(a);
                XuatChuoi(a);
            }
            break;

            case 2: 
            {
                printf("\nCo %d khoang trang trong chuoi", DemKhoangTrang(a));
            }
            break;

            case 3: 
            {
                XoaKhoangTrangThua(a);
                XuatChuoi(a);
            }
            break;

            case 4: 
            {
                DoiKyTuHoaDau(a);
                XuatChuoi(a);
            }
            break;

            case 5: 
            {
                if(TimKiemTen(a) == 1)
                {
                    printf("\nTim thay ten");
                }
                else
                {
                    printf("\nDa nhap sai !!!");
                }
            }
            break;

            case 6: 
            {
                CatChuoiHoTen(a);
            }
            break;

            case 0: 
            {
                printf("\nTHOAT CHUONG TRINH !!!");
            }
            break;

            default:
            {
                printf("\nKiem tra lua chon !!!");
            }
            break;
        }
    } while (chon != 0);
    
 }
