#include<stdio.h>
#include<conio.h>

 int main()
 {
    float a, b;
    float tong, hieu, tich, thuong;
    float *pa = &a; 
    float *pb = &b;
    printf("\nNhap vao so a: ");
    scanf("%f", pa);
    printf("\nNhap vao so b: ");
    scanf("%f", pb);
    tong = *pa + *pb;
    hieu = *pa - *pb;
    tich = *pa * *pb;
    thuong = *pa / *pb;
    printf("\nTong la: %.2f, dia chi: %x", tong, &tong);
    printf("\nHieu la: %.2f, dia chi: %x", hieu, &hieu);
    printf("\nTich la: %.2f, dia chi: %x", tich, &tich);
    printf("\nThuong la: %.2f, dia chi: %x", thuong, &thuong);
    getch();
    return 0;
 }