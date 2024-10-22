#include<stdio.h>
#include<conio.h>
#include<string.h>
 
 int main(int argc, char **argv)
 {
    char a[64] = {0};
    printf("\nNhap a: ");
    //fgets(a, 50, stdin);
    gets(a);
    printf("\nChuoi: %s", a);
    getch();
    return 1;
 }