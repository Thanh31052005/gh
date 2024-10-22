#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 void InputArray(int *&a, int &n)
 {
   printf("\nNhap vao so luong phan tu : ");
   scanf("%d", &n);
   a = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++)
   {
      printf("\nNhap vao a[%d]: ", i);
      scanf("%d", (a + i));
   }
   printf("\nDa xong");
 }

 void OutputArray(int *a, int n)
 {
   printf("\n-----------------------------------------");
   for (int i = 0; i < n; i++)
   {
     printf("\nGia tri a[%d] la: %d", i, *(a + i));
   }
 }

 void XuatCucTieu(int *a, int n)
 {
    printf("\n\nCac cuc tieu la: ");

    if(*(a + 0) < *(a + 1))
    {
        printf("%d ", *(a + 0));
    }

    for(int i = 1; i < n - 1; i++)
    {
        if(*(a + (i - 1)) > *(a + i) && *(a + (i + 1)) > *(a + i))
        {
          printf("%d ", *(a + i));  
        }
    }

    if(*(a + (n - 1)) < *(a + (n - 2)))
    {
        printf("%d", *(a + (n - 1)));
    }
 }

 int XuLyNgoaiLe(int n, int k)
 {
    try 
    {
        if (k < 0)
        {
            throw 101;
        }

        else if (k > n)
        {
            throw "Khong ton tai vi tri k nay";
        }
        else return 1;
    }
    catch (int k)
    {
        if(k == 101)
        {
          printf("\nVi tri k be hon mang !!!");
        }
    }

    catch (const char *Loi)
    {
        printf("\nLoi: %s", Loi);
    }
    return 0;
 }

 int ThemTaiK(int &n, int *a)
 {
    int k;
    int nho;
    printf("\nNhap vtri can them: ");
    scanf("%d", &k);
    if (XuLyNgoaiLe(n, k) == 0)
    {
      return 0;
    }
    printf("\nNhap vao ptu : ");
    scanf("%d", &nho);
    for (int i = n; i > k; i--) 
    {
        *(a + i) = *(a + (i - 1));
    }
    *(a + k) = nho;
    n++;
    return 1;
 }

 int XoaTaiK(int &n, int *a)
 {
    int k;
    printf("\nNhap vao vtri can xoa: ");
    scanf("%d", &k);
    if (XuLyNgoaiLe(n, k) == 0)
    {
      return 0;
    }
    
    for (int i = k; i < n - 1; i++)
    {
      *(a + i) = *(a + (i + 1));
    }
    n--;
    return 1;
 }
 
 int KiemTraXenKe(int *a, int n)
 {
   for (int i = 0; i < n - 1; i++)
   {
      if (a[i] % 2 == 0 && a[i + 1] % 2 == 0 || a[i] % 2 != 0 && a[i + 1] % 2 != 0)
      {
        return 0;
      }
   }
   return 1;
 }

 void EvenOdd(int *a, int n)
 {
   int tam[n + 1]; // Mảng tạm lưu dữ liệu của mảng a
   int i = 0;
   int e = 0, j = 0;
   while(i < n)
   {
    if(*(a + i) % 2 == 0)
    {
      *(tam + e) = *(a + i);
      e++;
    }

    else
    {
      *(tam + ((n - j) - 1)) = *(a + i);
      j++;
    }
    i++;
   }
   for(int t = 0; t < n; t++)
   {
    *(a + t) = *(tam + t);
   }
 }
 
 int main()
 {
  int *a, n;
  InputArray(a, n);
  OutputArray(a, n);
  XuatCucTieu(a, n);
  printf("\n------------------------");
  XoaTaiK(n, a);
  OutputArray(a, n);
  printf("\n------------------------");
  ThemTaiK(n, a);
  OutputArray(a, n);
  printf("\n------------------------");
  if(KiemTraXenKe(a, n) == 1)
  {
    printf("\nMang chan le xen ke");
  }
  else printf("\nMang ko xen ke");
  printf("\n------------------------");
  printf("\nChan len dau, Le cuoi");
  EvenOdd(a, n);
  OutputArray(a, n);
  getch();
  return 0;
 }