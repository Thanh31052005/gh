#include<stdio.h>
#include<conio.h>
#include<string.h>

 void NhapChuoi(char *ptr)
 {
    printf("\nNhap vao chuoi: ");
    fgets(ptr, 50, stdin);
    ptr[strlen(ptr) - 1] = '\0';
    rewind(stdin);
 }

 void XuatKiTu(char *ptr)
 {
    printf("\nCac ki tu: ");
    for(int i = 0; i < strlen(ptr); i++)
    {
        printf("\n%c", *(ptr + i));
    }
 }

 void ChuyenChuHoa(char *ptr)
 {
    printf("\nChu Hoa: ");
    for(int i = 0; i < strlen(ptr); i++)
    {
        if(*(ptr + i) >= 65 && *(ptr + i) <= 90)
        {
            printf("%c", *(ptr + i));
        }

        else if(*(ptr + i) >= 97 && *(ptr + i) <= 122)
        {
            printf("%c", *(ptr + i) - 32);
        }
        
        else printf(" ");    // Thay kí tự đặt biệt bằng khoảng trắng
    }
 }

 void InHoaChuDau(char *ptr)
 {
    printf("\nIn hoa chu cai dau: ");

    if(*(ptr + 0) >= 65 && *(ptr + 0) <= 90)
    {
        printf("%c", *(ptr + 0));
    }

    else printf("%c", *(ptr + 0) - 32);
    
    for(int i = 1; i < strlen(ptr); i++)
    {
        if(*(ptr + i) >= 65 && *(ptr + i) <= 90)
        {
            printf("%c", *(ptr + i));
        }

        else if(*(ptr + (i - 1)) == ' ' && *(ptr + i) >= 97 && *(ptr + i) <= 122)
        {
            printf("%c", *(ptr + i) - 32);
        }

        else if(*(ptr + i) >= 97 && *(ptr + i) <= 122)
        {
            printf("%c", *(ptr + i));
        }
        
        else printf(" ");    
    }
 }

 int main()
 {
    char chuoi[50];
    char *ptr = chuoi;
    NhapChuoi(ptr);
    XuatKiTu(ptr);
    ChuyenChuHoa(ptr);
    InHoaChuDau(ptr);
    getch();
    return 0;
 }