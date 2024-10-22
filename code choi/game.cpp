#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

 struct Data
 {
    char Username[20];
    char Passwords[15];
    float Money;
 };
  
 void CreateAccount(Data &a) // Tao tai khoan 
 {
  char check[15];
  char nho[25];
   while (1)
   {
     rewind(stdin);
     printf("\nTen dang nhap : ");
      fgets(a.Username, 20, stdin);
     a.Username[strlen(a.Username) - 1] = '\0'; 
     rewind(stdin);
     printf("\nMat khau : ");
      fgets(a.Passwords, 15, stdin);
     rewind(stdin);
     printf("\nNhap lai mat khau : ");
      fgets(check, 15, stdin);
     if((strcmp(a.Passwords, check)) != 0)
      {
        printf("\nMat khau nhap lai khong dung !!!");
        printf("\n**************************************");
      }
     else
      { 
       a.Money += 5.0;
       break;
      }
    }
     // Tao file text
     strcpy(nho, a.Username);
     strcat(nho, ".txt");
     //---------------------
     FILE *f = fopen(nho, "w");
      fprintf(f, "%s%.2f", a.Passwords, a.Money);
     fclose(f);
      printf("\nDa tao tai khoan thanh cong =))");
 }

  int CheckAccount(Data a) // Kiem tra xem co tai khoan chua ?
  {
    char nho[25];
     strcpy(nho, a.Username);
     strcat(nho, ".txt");
   FILE *f = fopen(nho, "r");

    if(f == NULL)
    {
      printf("\nTen dang nhap hoac mat khau khong dung !");
      return 0;
    }
    
    else
    {
     printf("\n\nDANG NHAP THANH CONG");
     printf("\nXin Chao : %s  || So du : %.2f", a.Username, a.Money);
     return 1;
    }
  }

  int RandomNumber(int &TongXucXac) // Tao so ngau nhien trong game
  {
   int N = 6; // so cham cua xuc xac
   int L = 3; // so lan gieo xuc xac
   printf("\nSo diem xuc sac lan luot la : ||");
   srand(time(NULL));
    for(int i = 1; i <= L; i++)
    {
      int nho = rand() % N + 1;
      printf(" %d ||", nho);
      TongXucXac += nho;
    }
    return TongXucXac;
  }
  
  

  int main()
  {
    Data a;
    int TongXucXac = 0;
    RandomNumber(TongXucXac);
    printf("\nTong so xuc xac : %d", TongXucXac);
    getch();
    return 1;
  }