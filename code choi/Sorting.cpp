#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 100

struct Data
{
    int songuyen;
    float sothuc;
    char kitu;
    char chuoi[MAX_SIZE];
};

void MENU();
void Option(Data a[], int n);
void Swap(Data &a, Data &b);

// Dữ liệu số nguyên
void InputArrayInt(Data a[], int &n);
void OutputArrayInt(Data a[], int n);

// Dữ liệu số thực
void InputArrayFloat(Data a[], int &n);
void OutputArrayFloat(Data a[], int n);

// Dữ liệu kí tự
void InputArrayChar(Data a[], int &n);
void OutputArrayChar(Data a[], int n);

// Dữ liệu chuỗi
void InputArrayString(Data a[], int &n);
void OutputArrayString(Data a[], int n);

// Hàm sắp xếp tăng
void _INC_Int_Interchange_Sort(Data a[], int n);    // Sắp xếp tăng kiểu số nguyên
void _INC_Float_Interchange_Sort(Data a[], int n);  // Sắp xếp tăng kiểu số thực
void _INC_Char_Interchange_Sort(Data a[], int n);   // Sắp xếp tăng kiểu kí tự
void _INC_String_Interchange_Sort(Data a[], int n); // Sắp xếp tăng kiểu chuỗi

// Hàm sắp xếp giảm
void _DEC_Int_Interchange_Sort(Data a[], int n);    // Sắp xếp giảm kiểu số nguyên
void _DEC_Float_Interchange_Sort(Data a[], int n);  // Sắp xếp giảm kiểu số thực
void _DEC_Char_Interchange_Sort(Data a[], int n);   // Sắp xếp giảm kiểu kí tự
void _DEC_String_Interchange_Sort(Data a[], int n); // Sắp xếp giảm kiểu chuỗi

int main()
{
    Data a[MAX_SIZE];
    int n;
    Option(a, n);
    getch();
    return 1;
}

void MENU()
{
    printf("\n----------------MENU-----------------");
    printf("\n1) Sap xep mang tang dan kieu so nguyen");
    printf("\n2) Sap xep mang tang dan kieu so thuc");
    printf("\n3) Sap xep mang tang dan kieu ki tu");
    printf("\n4) Sap xep mang tang dan kieu chuoi");

    printf("\n5) Sap xep mang giam dan kieu so nguyen");
    printf("\n6) Sap xep mang giam dan kieu so thuc");
    printf("\n7) Sap xep mang giam dan kieu ki tu");
    printf("\n8) Sap xep mang giam dan kieu chuoi");
    printf("\n0) Thoat chuong trinh");
}

void Swap(Data &a, Data &b)
{
    Data nho = a;
    a = b;
    b = nho;
}

void InputArrayInt(Data a[], int &n)
{
    while (1)
    {
        printf("\nNhap vao so luong ptu trong mang (0 < n < 100): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 100)
        {
            printf("\nCheck input !!!");
        }
        else
        {
            printf("\nNhap mang");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap vao a[%d]: ", i);
        scanf("%d", &a[i].songuyen);
    }
    printf("\nDa xong !!!");
}

void InputArrayFloat(Data a[], int &n)
{
    while (1)
    {
        printf("\nNhap vao so luong ptu trong mang (0 < n < 100): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 100)
        {
            printf("\nCheck input !!!");
        }
        else
        {
            printf("\nNhap mang");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap vao a[%d]: ", i);
        scanf("%f", &a[i].sothuc);
    }
    printf("\nDa xong !!!");
}

void InputArrayChar(Data a[], int &n)
{
    while (1)
    {
        printf("\nNhap vao so luong ptu trong mang (0 < n < 100): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 100)
        {
            printf("\nCheck input !!!");
        }
        else
        {
            printf("\nNhap mang");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        rewind(stdin);
        printf("\nNhap vao a[%d]: ", i);
        scanf("%c", &a[i].kitu);
    }
    printf("\nDa xong !!!");
}

void InputArrayString(Data a[], int &n)
{
    while (1)
    {
        printf("\nNhap vao so luong ptu trong mang (0 < n < 100): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 100)
        {
            printf("\nCheck input !!!");
        }
        else
        {
            printf("\nNhap mang");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        rewind(stdin);
        printf("\nNhap vao a[%d]: ", i);
        fgets(a[i].chuoi, MAX_SIZE, stdin);
        a[i].chuoi[strlen(a[i].chuoi) - 1] = '\0'; // Xóa kí tự xuống dòng
    }
    printf("\nDa xong !!!");
}

void OutputArrayInt(Data a[], int n)
{
    printf("\nMang chua %d phan tu", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu a[%d]: %d", i, a[i].songuyen);
    }
}

void OutputArrayFloat(Data a[], int n)
{
    printf("\nMang chua %d phan tu", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu a[%d]: %.2f", i, a[i].sothuc);
    }
}

void OutputArrayChar(Data a[], int n)
{
    printf("\nMang chua %d phan tu", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu a[%d]: %c", i, a[i].kitu);
    }
}

void OutputArrayString(Data a[], int n)
{
    printf("\nMang chua %d phan tu", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu a[%d]: %s", i, a[i].chuoi);
    }
}

void _INC_Int_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].songuyen > a[j].songuyen)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _INC_Float_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].sothuc > a[j].sothuc)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _INC_Char_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].kitu > a[j].kitu)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _INC_String_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].chuoi, a[j].chuoi) > 0)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _DEC_Int_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].songuyen < a[j].songuyen)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _DEC_Float_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].sothuc < a[j].sothuc)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _DEC_Char_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].kitu < a[j].kitu)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void _DEC_String_Interchange_Sort(Data a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].chuoi, a[j].chuoi) < 0)
            {
                Swap(a[i], a[j]);
            }
        }
    }
    printf("\nDa sap xep !!");
}

void Option(Data a[], int n)
{
    MENU();
    int chon, nho = 1;
    while (nho)
    {
        printf("\n----------------------------------------------------");
        printf("\nNhap vao lua chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
        {
            printf("\n\n __SO NGUYEN TANG__");
            InputArrayInt(a, n);
            OutputArrayInt(a, n);
            _INC_Int_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayInt(a, n);
        }
        break;

        case 2:
        {
            printf("\n\n __SO THUC TANG__");
            InputArrayFloat(a, n);
            OutputArrayFloat(a, n);
            _INC_Float_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayFloat(a, n);
        }
        break;

        case 3:
        {
            printf("\n\n __KI TU TANG__");
            InputArrayChar(a, n);
            OutputArrayChar(a, n);
            _INC_Char_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayChar(a, n);
        }
        break;

        case 4:
        {
            printf("\n\n __CHUOI KI TU TANG__");
            InputArrayString(a, n);
            OutputArrayString(a, n);
            _INC_String_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayString(a, n);
        }
        break;

        case 5:
        {
            printf("\n\n __SO NGUYEN GIAM__");
            InputArrayInt(a, n);
            OutputArrayInt(a, n);
            _DEC_Int_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayInt(a, n);
        }
        break;

        case 6:
        {
            printf("\n\n __SO THUC GIAM__");
            InputArrayFloat(a, n);
            OutputArrayFloat(a, n);
            _DEC_Float_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayFloat(a, n);
        }
        break;

        case 7:
        {
            printf("\n\n __KI TU GIAM__");
            InputArrayChar(a, n);
            OutputArrayChar(a, n);
            _DEC_Char_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayChar(a, n);
        }
        break;

        case 8:
        {
            printf("\n\n __CHUOI KI TU GIAM__");
            InputArrayString(a, n);
            OutputArrayString(a, n);
            _DEC_String_Interchange_Sort(a, n);
            printf("\n------------------------------------");
            OutputArrayString(a, n);
        }
        break;

        case 0:
        {
            printf("\nThoat chuong trinh !");
            nho = 0;
        }
        break;

        default:
            printf("\nKIEM TRA LUA CHON");
            break;
        }
    }
}
