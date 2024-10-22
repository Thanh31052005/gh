#include <stdio.h>
#include <conio.h>
#include <time.h>

// int n = sizeof(arr) / sizeof(arr[0]); 
// Cho biết số lượng ptu của mảng khi ta ko cho trước số lượng ptu cố định (n).
// Chỉ dùng cho mảng đã có trước phần tử nhưng chưa có n

int FindxBinary(int a[])
{
   int x = 168;
   int L, R;
   L = 0, R = 24;
   while (L <= R)
   {
      int M = (R + L) / 2;
      if (a[M] == x)
      {
         printf("\nTim thay x");
         return 1;
      }
      if (a[M] < x) // Nếu x lớn hơn mid
         L = M + 1;
      if (a[M] > x) // nếu x nhỏ mid
         R = M - 1;
   }
   return 0;
}

int FindxLinear(int a[])
{
 int x = 68;
 for(int i = 0; i < 25; i++)
 {
   if(a[i] == x)
   {
      printf("\nTim thay x");
      return 1;
   }
 }
 return 0;
}

void RUNTIME(int a[])
{
   clock_t start, end;
   double cpu_time_used;

   // Lấy thời gian bắt đầu
   start = clock();

   // Gọi hàm sắp xếp
   FindxBinary(a);

   // Lấy thời gian kết thúc
   end = clock();

   // Tính toán thời gian đã sử dụng
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

   // Xuất ra màn hình thời gian chạy
   printf("\nThoi gian chay cua thuat toan tim kiem tuyen tinh: %f giay\n", cpu_time_used);
}

int main()
{
   int a[150] = {1, 4, 7, 9, 19, 26, 29, 30, 56, 65, 68, 86, 98, 100, 101, 195, 205, 206, 211
   , 275, 278, 321, 789, 1000, 10001};
   RUNTIME(a);
   getch();
   return 0;
}