#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 50

struct SinhVien
{
  char MSSV[15];
  char Ten[30];
  float DTB;
};

void XuatMang(int n, SinhVien a[]);
void NhapMang(int &n, SinhVien a[]);
void ReadFromFile(int &n, SinhVien a[]);
void WriteToFile(int n, SinhVien a[]);

int main()
{
  SinhVien a[MAX_SIZE];
  int n;
  //NhapMang(n, a);
  ReadFromFile(n, a);
  XuatMang(n, a);
  //WriteToFile(n, a);
  getch();
  return 0;
}

void NhapMang(int &n, SinhVien a[])
{
  printf("\nNhap vao so luong sinh vien : ");
  scanf("%d", &n);
  printf("\n-----------------------------------");
  for (int i = 0; i < n; i++)
  {
    rewind(stdin);
    printf("\nNhap vao sinh vien thu %d", i + 1);
    printf("\nNhap vao mssv : ");
    fgets(a[i].MSSV, 15, stdin);
    a[i].MSSV[strlen(a[i].MSSV) - 1] = '\0';
    rewind(stdin);
    printf("\nNhap vao ten sinh vien : ");
    fgets(a[i].Ten, 30, stdin);
    a[i].Ten[strlen(a[i].Ten) - 1] = '\0';
    printf("\nNhap diem trung binh : ");
    scanf("%f", &a[i].DTB);
    printf("\n-----------------------");
  }
  rewind(stdin);
}

void XuatMang(int n, SinhVien a[])
{
  printf("\n\nDANH SACH SINH VIEN");
  for (int i = 0; i < n; i++)
  {
    printf("\nSinh vien thu %d", i + 1);
    printf("\n%s %s %.2f", a[i].MSSV, a[i].Ten, a[i].DTB);
    printf("\n-----------------------------");
  }
}

void WriteToFile(int n, SinhVien a[])
{
  char chuoi[20];
  printf("\nNhap vao ten file binary : ");
  fgets(chuoi, 20, stdin);
  chuoi[strlen(chuoi) - 1] = '\0';
  FILE *f = fopen(chuoi, "wb");
  for(int i = 0; i < n; i++)
  {
    fwrite(&a[i], sizeof(SinhVien), 1, f);
  }
  fclose(f);
  printf("\nDa xong !!!");
}

void ReadFromFile(int &n, SinhVien a[])
{
  char chuoi1[20];
  printf("\nNhap vao ten file binary can lay du lieu ra mang: ");
  fgets(chuoi1, 20, stdin);
  chuoi1[strlen(chuoi1) - 1] = '\0';
  FILE *fo = fopen(chuoi1, "rb");
  if (fo == NULL)
  {
    printf("\nFile khong ton tai !");
    return;
  }
  fseek(fo, 0, SEEK_END);
  n = ftell(fo) / sizeof(SinhVien);
  rewind(fo);
  if (n > MAX_SIZE)
  {
    printf("\nKich thuoc mang khong du !");
    fclose(fo);
    return;
  }
  fread(a, sizeof(SinhVien), n, fo);

  fclose(fo);
}