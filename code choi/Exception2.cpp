#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 50

void MENU();                            // Hàm menu
void ChonSo(int n, int k, int a[]);     // Hàm chọn
void NhapMang(int &n, int &k, int a[]); // Hàm nhập số cho btoan
void XuatMang(int n, int a[]);          // Hàm xuất mảng
int XoaTaiK(int &n, int k, int a[]);    // Hàm xóa ptu tại vtri k
int ThemTaiK(int &n, int k, int a[]);   // Hàm thêm ptu tại vtri k

void MENU()
{
    printf("\n||*************MENU*************||");
    printf("\n||    1) Them ptu tai vi tri k  ||");
    printf("\n||    2) Xoa ptu tai vi tri k   ||");
    printf("\n||    0) Thoat chuong trinh     ||");
    printf("\n||******************************||");
}

void NhapMang(int &n, int &k, int a[])
{
    printf("\nNhap vao so ptu array : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap vao ptu a[%d] : ", i + 1);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nPtu a[%d] : %d", i + 1, a[i]);
    }
}

int ThemTaiK(int &n, int k, int a[])
{
    int nho;
    printf("\nNhap vtri can them : ");
    scanf("%d", &k);
    printf("\nNhap vao ptu : ");
    scanf("%d", &nho);
    k--;                        // Vì chương trình đc bắt đầu bằng số 1 khác với mảng là 0.
    for (int i = n; i > k; i--) // Xử lí các ptu trc K nhưng chưa thay đổi gtri K.
    {
        a[i] = a[i - 1];
    }
    a[k] = nho;
    n++;
    return 1;
}

int XoaTaiK(int &n, int k, int a[])
{
    printf("\nNhap vao vtri can xoa : ");
    scanf("%d", &k);
    k--;
    for (int i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}

void ChonSo(int n, int k, int a[])
{
    int chon;
    int nho = 1;
    while (nho)
    {
        printf("\nNhap vao lua chon : ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            printf("\nThoat chuong trinh");
            nho = 0;
            break;

        case 1:
            ThemTaiK(n, k, a);
            XuatMang(n, a);
            break;

        case 2:
            XoaTaiK(n, k, a);
            XuatMang(n, a);
            break;

        default:
            printf("\nHay kiem tra lai !!");
        }
    }
}

int main()
{
    int n, k;
    int a[MAX_SIZE];
    NhapMang(n, k, a);
    XuatMang(n, a);
    ChonSo(n, k, a);
    getch();
    return 1;
}