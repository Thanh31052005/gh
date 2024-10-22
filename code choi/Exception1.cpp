#include <stdio.h>
#include <conio.h>

void NhapSo(int &a, int &b, int &c);   //  hàm nhập số
void XuLyNgoaiLe(int a, int b, int c); // hàm xử lý exception
float TinhToan(int a, int b, int c);   // hàm tính

void NhapSo(int &a, int &b, int &c)
{
  printf("\nNhap vao so a : ");
  scanf("%d", &a);
  printf("\nNhap vao so b: ");
  scanf("%d", &b);
  printf("\nNhap vao so c: ");
  scanf("%d", &c);
}

float TinhToan(int a, int b, int c)
{
  float d = 1.0 * c / (a - b);
  return d;
}

void XuLyNgoaiLe(int a, int b, int c)
{
  int d = a - b;

  try
  {
    if (d == 0)
    {
      throw d;
    }
    printf("\nKet qua : %.2f", TinhToan(a, b, c));
  }

  catch (int d)
  {
    printf("\nNgoai le xay ra !!!");
  }
}

int main()
{
  int a, b, c;
  NhapSo(a, b, c);
  XuLyNgoaiLe(a, b, c);
  getch();
  return 0;
}