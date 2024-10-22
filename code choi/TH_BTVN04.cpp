#include <stdio.h>
#include <conio.h>
#include <math.h>

int Bai12_y(int n);
int Bai12_x(int n);

void Nhapn(int &n)
{
    printf("\nNhap vao n: ");
    scanf("%d", &n);
}

float Bai9a(int n)
{
    if (n == 1)
    {
        return (float)1 / (1 * (1 + 1) * (1 + 2));
    }
    return (float)1 / (n * (n + 1) * (n + 2)) + Bai9a(n - 1);
}

int Bai9b(int n)
{
    if (n == 1)
        return 1;
    return pow(n, 2) + Bai9b(n - 1);
}

int TongTu1DenN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += i;
    }
    return tong;
}

int Bai9c(int n)
{
    if (n == 1)
        return 1;
    return TongTu1DenN(n) + Bai9c(n - 1);
}

int GiaiThua(int x)
{
    if (x == 0)
    {
        return 0;
    }
    int tong = 1;
    for (int i = 2; i <= x; i++)
    {
        tong *= i;
    }
    return tong;
}

float Bai9d(int n)
{
    if (n == 1)
        return pow(-1, 1) * ((2 * 1 - 1) + (2 * 1)) / GiaiThua(2 * 1);
    return (pow(-1, n) * ((2 * n - 1) + (2 * n)) / GiaiThua(2 * n)) + Bai9d(n - 1);
}

// khoảng [m, n]
int fibonacci(int k)
{
    if (k <= 2) return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
}

void Bai10(int m, int n)
{
    int fib = 1, i = 1;
    printf("\nCac so Fibonacci trong khoang [%d, %d]: ", m, n);
    while (fib <= n)
    {
        fib = fibonacci(i++);
        if (fib >= m && fib <= n)
            printf("%d ", fib);
    }
}

int Bai11DeQuy(int n)
{
    if (n <= 2)
        return 1;
    int a = 1, b = 1, fib;
    while (true)
    {
        fib = a + b;
        if (fib >= n)
            return b;
        a = b;
        b = fib;
    }
}

int Bai11KhongDeQuy(int n)
{
    if (n <= 2)
        return 1;
    int a = 1, b = 1, fib;
    while (true)
    {
        fib = a + b;
        if (fib >= n)
            return b;
        a = b;
        b = fib;
    }
}

int Bai12_x(int n)
{
    if (n == 0)
        return 1;
    return Bai12_x(n - 1) + Bai12_y(n - 1);
}

int Bai12_y(int n)
{
    if (n == 0)
        return 0;
    return 3 * Bai12_x(n - 1) + 2 * Bai12_y(n - 1);
}

int Bai13(int a, int q, int n)
{
    if (n == 1)
        return a;
    return q * Bai13(a, q, n - 1);
}


int Bai14(int n)
{
    if (n < 6)
        return n;
    return Bai14(n - 5) + Bai14(n - 4) + Bai14(n - 3) + Bai14(n - 2) + Bai14(n - 1);
}

int Bai15(int n)
{
    if (n == 1)
        return 1;
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += Bai15(i);
    return n * sum;
}

int Bai16(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 3;
    return Bai16(n - 1) + 2 * Bai16(n - 2) + 3 * Bai16(n - 3);
}

int Bai17(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Bai17(n - 1) + (n - 1) * Bai17(n - 2);
}

int Bai18(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += Bai18(i);
    return sum;
}

int Bai19(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return n / 2 + Bai19(n / 2) + 2;
    else
        return pow((n / 2), 2) + Bai19(n / 2) * Bai19(n / 2 + 1) + 1;
}

void MENU()
{
    printf("\n------------------MENU-----------------");
    printf("\n1) 1 / ( n * (n + 1) * (n + 2))");
    printf("\n2) 1^2 + 2^2 + n^2");
    printf("\n3) 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 +...+ n)");
    printf("\n4) (-1)^n * ((2n - 1) + 2n) / (2n)!");
    printf("\n5) Fibonacci trong doan [m, n]");
    printf("\n6) Fibonacci lon nhat < n (de quy)");
    printf("\n7) Fibonacci lon nhat < n (khong de quy)");
    printf("\n8) Tinh so hang thu n cua day xn va yn");
    printf("\n9) Tinh so hang thu n cua cap so nhan");
    printf("\n10) Tinh U(n) cho n >= 6");
    printf("\n11) Tinh An de quy");
    printf("\n12) Tinh Yn de quy");
    printf("\n13) Tinh cap so nhan");
    printf("\n14) Tinh so nguyen duong nhap tu ban phim");
    printf("\n15) Tinh An bai 19");
}

void Option(int n)
{
    int chon, m;
    do
    {
        printf("\n\nNhap vao lua chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            Nhapn(n);
            printf("\nTong la: %.3f", Bai9a(n));
            break;
        case 2:
            Nhapn(n);
            printf("\nTong la: %d", Bai9b(n));
            break;
        case 3:
            Nhapn(n);
            printf("\nTong la: %d", Bai9c(n));
            break;
        case 4:
            Nhapn(n);
            printf("\nTong la: %.3f", Bai9d(n));
            break;
        case 5:
            printf("\nNhap vao m va n: ");
            scanf("%d%d", &m, &n);
            Bai10(m, n);
            break;
        case 6:
            Nhapn(n);
            printf("\nFibonacci lon nhat nho hon %d la: %d", n, Bai11DeQuy(n));
            break;
        case 7:
            Nhapn(n);
            printf("\nFibonacci lon nhat nho hon %d la: %d", n, Bai11KhongDeQuy(n));
            break;
        case 8:
            Nhapn(n);
            printf("\nxn = %d, yn = %d", Bai12_x(n), Bai12_y(n));
            break;
        case 9:
            int a, q;
            printf("\nNhap a va q: ");
            scanf("%d%d", &a, &q);
            Nhapn(n);
            printf("\nSo hang thu %d la: %d", n, Bai13(a, q, n));
            break;
        case 10:
            Nhapn(n);
            printf("\nGia tri U(%d) la: %d", n, Bai14(n));
            break;
        case 11:
            Nhapn(n);
            printf("\nGia tri A(%d) la: %d", n, Bai15(n));
            break;
        case 12:
            Nhapn(n);
            printf("\nGia tri Y(%d) la: %d", n, Bai16(n));
            break;
        case 13:
            Nhapn(n);
            printf("\nGia tri X(%d) la: %d", n, Bai17(n));
            break;
        case 14:
            Nhapn(n);
            printf("\nGia tri x(%d) la: %d", n, Bai18(n));
            break;
        case 15:
            Nhapn(n);
            printf("\nGia tri A(%d) theo bai 19 la: %d", n, Bai19(n));
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
    MENU();
    Option(n);
    getch();
    return 1;
}
