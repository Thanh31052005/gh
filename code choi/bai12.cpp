#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Fraction // Phân số
{
    int numerator;   // Tử số
    int denominator; // Mẫu số
};

int CheckDenominator(int Mau)
{
    if (Mau == 0)
    {
        printf("\nLoi: Mau bang 0!!!");
        return 0;
    }
    return 1;
}

void NhapMangPS(Fraction **a, int *n)
{
    printf("\nNhap vao so luong phan tu: ");
    scanf("%d", n);
    *a = (Fraction *)malloc((*n) * sizeof(Fraction));
    for (int i = 0; i < *n; i++)
    {
        printf("\n---------------------------------");
        printf("\nNhap vao phan so a[%d]", i);
        printf("\nNhap vao tu: ");
        scanf("%d", &((*a + i)->numerator));
        printf("\nNhap vao mau: ");
        scanf("%d", &((*a + i)->denominator));
    }
    printf("\nDa xong");
}

void XuatMangPS(Fraction *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (CheckDenominator((a + i)->denominator) == 1)
        {
            printf("\nPhan so a[%d]: %d/%d", i, (a + i)->numerator, (a + i)->denominator);
        }
        else
        {
            printf("\nPhan so a[%d] co mau bang 0", i);
        }
    }
}

int SoSanh(Fraction a, Fraction b)
{
    int left = a.numerator * b.denominator;
    int right = b.numerator * a.denominator;
    
    if (left > right)
        return 1;
    else
        return 0;
}

void Max(Fraction *a, int n)
{
    Fraction max = *(a + 0);
    for (int i = 1; i < n; i++)
    {
        if (SoSanh(*(a + i), max) == 1) 
        {
            max = *(a + i);
        }
    }
    printf("\nPhan so lon nhat la: %d/%d", max.numerator, max.denominator);
}

void Min(Fraction *a, int n)
{
    Fraction min = *(a + 0);
    for (int i = 1; i < n; i++)
    {
        if (SoSanh(*(a + i), min) == 0) // Nếu a[i] nhỏ hơn min
        {
            min = *(a + i);
        }
    }
    printf("\nPhan so nho nhat la: %d/%d", min.numerator, min.denominator);
}

int XuLyNgoaiLe(int n, int k)
{
    if (k < 0)
    {
        printf("\nVi tri k be hon mang!!!");
        return 0;
    }
    if (k >= n)
    {
        printf("\nLoi: Khong ton tai vi tri k nay");
        return 0;
    }
    return 1;
}

int XoaTaiK(int *n, Fraction *a)
{
    int k;
    printf("\nNhap vao vtri can xoa: ");
    scanf("%d", &k);
    if (XuLyNgoaiLe(*n, k) == 0)
    {
        return 0;
    }

    for (int i = k; i < *n - 1; i++)
    {
        *(a + i) = *(a + (i + 1));
    }
    (*n)--;
    return 1;
}

int ThemTaiK(int *n, Fraction *a)
{
    int k;
    Fraction nho;
    printf("\nNhap vtri can them: ");
    scanf("%d", &k);
    if (XuLyNgoaiLe(*n, k) == 0)
    {
        return 0;
    }
    printf("\nNhap vao phan so can them");
    printf("\nNhap vao tu: ");
    scanf("%d", &nho.numerator);
    printf("\nNhap vao mau: ");
    scanf("%d", &nho.denominator);
    for (int i = *n; i > k; i--)
    {
        *(a + i) = *(a + (i - 1));
    }
    *(a + k) = nho;
    (*n)++;
    return 1;
}

int main()
{
    Fraction *a;
    int n;
    NhapMangPS(&a, &n);
    XuatMangPS(a, n);
    XoaTaiK(&n, a);
    XuatMangPS(a, n);
    ThemTaiK(&n, a);
    XuatMangPS(a, n);
    Max(a, n);
    Min(a, n);
    free(a);
    getch();
    return 0;
}
