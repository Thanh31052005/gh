#include<stdio.h>
#include<conio.h>
#include<string.h> 
#define MAX_SIZE 50

 void ReadFromFile(int &n, int a[]);
 void WriteToFile(int n, int a[]);
 void NhapMang(int &n, int a[]);
 void XuatMang(int n, int a[]);

 int main()
 {
    int n;
    int a[MAX_SIZE];
    //NhapMang(n, a);
    ReadFromFile(n, a);
    // WriteToFile(n, a);
    getch();
    return 1;
 }
 
 void NhapMang(int &n, int a[])
 {
   printf("\nNhap vao so ptu mang : ");
    scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
      printf("\nNhap vao a[%d] : ", i);
       scanf("%d", &a[i]);
   }
 }

 void XuatMang(int n, int a[])
 {
   printf("\n-------------------------------");
   for(int i = 0; i < n; i++)
   {
     printf("\nPtu a[%d] la : %d ", i, a[i]);
   }
 }

 void ReadFromFile(int &n, int a[])
 {
    FILE *f = fopen("Songuyen.txt", "r");
    if(f == NULL)
    {
      printf("\nFile khong ton tai !");
      return;
    }
    fscanf(f, "%d\n\n", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(f, "%d\n", &a[i]);
        printf("\nGia tri a[%d] : %d", i, a[i]);
    }
    fclose(f);
    printf("\nDa xong !!!!"); 
    }

 void WriteToFile(int n, int a[])
 {
    char chuoi[20];
    rewind(stdin);
    printf("\nNhap vao ten file can ghi vao : ");
     fgets(chuoi, 20, stdin);
     chuoi[strlen(chuoi) - 1] = '\0';
    FILE *f = fopen(chuoi, "w");
    fprintf(f, "%d\n\n", n);
    for(int i = 0; i < n; i++)
    {
      fprintf(f, "%d\n", a[i]);
    }
    fclose(f);
    printf("\nDa ghi vao file !!");
 }
