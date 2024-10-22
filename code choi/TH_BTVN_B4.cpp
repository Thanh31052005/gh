#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void NhapMaTran(int a[][MAX_SIZE], int *n) {
    do {
        printf("\nNhap vao kich thuoc ma tran vuong n (n >= 5): ");
        scanf("%d", n);
        if (*n < 5) 
        {
            printf("\nNhap lai kich thuoc n >= 5!");
        }
    } while (*n < 5);

    printf("\nNhap vao cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) 
        {
            a[i][j] = rand() % 30;
        }
    }
}

void XuatMaTran(int a[][MAX_SIZE], int n) {
    printf("\nMa tran vuong %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SapXepDuongCheoPhuTangDan(int a[][MAX_SIZE], int n) {
    int k = 0;
    int duongCheoPhu[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        duongCheoPhu[k++] = a[i][n - i - 1];
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (duongCheoPhu[i] > duongCheoPhu[j]) {
                Swap(&duongCheoPhu[i], &duongCheoPhu[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][n - i - 1] = duongCheoPhu[i];
    }
}

void SapXepMaTranTheoDong(int a[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) || (i % 2 == 1 && a[i][j] < a[i][k])) {
                    Swap(&a[i][j], &a[i][k]);
                }
            }
        }
    }
}

void SapXepMaTranTheoCot(int a[][MAX_SIZE], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 == 1 && a[i][j] < a[k][j])) {
                    Swap(&a[i][j], &a[k][j]);
                }
            }
        }
    }
}

void SapXepMangTrenDuongCheoChinh(int a[][MAX_SIZE], int n) {
    int k = 0;
    int mang[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        mang[k++] = a[i][i];
        if (i + 1 < n) {
            mang[k++] = a[i][i + 1];
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (mang[i] > mang[j]) {
                Swap(&mang[i], &mang[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = mang[i];
        if (i + 1 < n) {
            a[i][i + 1] = mang[n + i];
        }
    }
}

void ChiaChanLe(int a[][MAX_SIZE], int n) {
    int temp[MAX_SIZE * MAX_SIZE], idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                temp[idx++] = a[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 1) {
                temp[idx++] = a[i][j];
            }
        }
    }

    idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[idx++];
        }
    }
}

int KiemTraDoiXung(int a[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    int a[MAX_SIZE][MAX_SIZE];
    int chon;

    do {
        printf("\n---------------MENU-----------------");
        printf("\n1) Nhap/Xuat ma tran vuong");
        printf("\n2) Sap xep duong cheo phu tang dan");
        printf("\n3) Sap xep ma tran theo dong");
        printf("\n4) Sap xep ma tran theo cot");
        printf("\n5) Sap xep cac phan tu tren duong cheo chinh va song song");
        printf("\n6) Di chuyen phan tu chan, le");
        printf("\n7) Kiem tra doi xung qua duong cheo chinh");
        printf("\n0) Thoat");
        printf("\nNhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                NhapMaTran(a, &n);
                XuatMaTran(a, n);
                break;
            case 2:
                SapXepDuongCheoPhuTangDan(a, n);
                XuatMaTran(a, n);
                break;
            case 3:
                SapXepMaTranTheoDong(a, n);
                XuatMaTran(a, n);
                break;
            case 4:
                SapXepMaTranTheoCot(a, n);
                XuatMaTran(a, n);
                break;
            case 5:
                SapXepMangTrenDuongCheoChinh(a, n);
                XuatMaTran(a, n);
                break;
            case 6:
                ChiaChanLe(a, n);
                XuatMaTran(a, n);
                break;
            case 7:
                if (KiemTraDoiXung(a, n)) {
                    printf("Ma tran doi xung qua duong cheo chinh.\n");
                } else {
                    printf("Ma tran khong doi xung qua duong cheo chinh.\n");
                }
                break;
            case 0:
                printf("\nThoat chuong trinh !!!");
                break;
            default:
                printf("\nLua chon khong hop le!");
                break;
        }
    } while (chon != 0);
    getch();
    return 0;
}
