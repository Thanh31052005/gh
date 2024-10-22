#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float ChiaPhanTu(int a, int b)
{
    try
    {
        if (b == 0)
        {
            throw "Loi: Mau bang 0";
        }
        return (float)a / b;
    }
    catch (const char* err)
    {
        printf("\n%s", err);
        return 0;  
    }
}

void NhapMang(int *&a, int &n)
 {
   printf("\nNhap vao so luong phan tu : ");
   scanf("%d", &n);
   a = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++)
   {
      printf("\nNhap vao [%d]: ", i);
      scanf("%d", (a + i));
   }
   printf("\nDa xong");
 }

void XuatMang(int *a, int n)
 {
   for (int i = 0; i < n; i++)
   {
     printf("\nGia tri [%d] la: %d", i, *(a + i));
   }
 }

void ChiaMang(int *a, int *b, int na, int nb)
{
    try
    {
        if (na != nb)
        {
            throw "Loi: Hai mang khong cung do dai";
        }
        printf("\nKet qua chia phan tu mang a cho mang b:\n");

        for (int i = 0; i < na; i++)
        {
            float ketqua = ChiaPhanTu(*(a + i), *(b + i));
            printf(" a[%d] / b[%d] = %.3f\n", i, i, ketqua);
        }
    }
    catch (const char* e)
    {
        printf("\n%s", e);
    }
}

int main()
{
    int na, nb;
    int *a, *b;
    printf("\nMang A");
    NhapMang(a, na);
    printf("\nMang B");
    NhapMang(b, nb);

    printf("\nMang a: ");
    XuatMang(a, na);
    printf("\n------------------------------------");
    printf("\nMang b: ");
    XuatMang(b, nb);

    ChiaMang(a, b, na, nb);
    free(a);
    free(b);
    getch();
    return 0;
}
