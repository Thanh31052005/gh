#include <stdio.h>
#include <conio.h>
#include <string.h>

 struct NguoiLaoDong{
    char hoTen[50];
    int ngay, thang, nam;
    char gioiTinh[10];
};

int tinhTuoiNghiHuu(int namSinh, char gioiTinh[]) {
    int tuoiNghiHuu = 0;
    int namBatDauTangTuoiNghiHuu = 2021;

    if (strcmp(gioiTinh, "Nam") == 0 || strcmp(gioiTinh, "nam") == 0) {
        tuoiNghiHuu = 60;
        tuoiNghiHuu += (2024 - namBatDauTangTuoiNghiHuu) * 3 / 12;
    } else if (strcmp(gioiTinh, "Nu") == 0 || strcmp(gioiTinh, "nu") == 0) {
        tuoiNghiHuu = 55; 
        tuoiNghiHuu += (2024 - namBatDauTangTuoiNghiHuu) * 4 / 12;
    }

    return tuoiNghiHuu;
}

int kiemTraGioiTinh(char gioiTinh[]) {
     if(strcmp(gioiTinh, "Nam") == 0 || strcmp(gioiTinh, "nam") == 0 || strcmp(gioiTinh, "Nu") == 0 || strcmp(gioiTinh, "nu") == 0)
     {
        return 1;
     }
     else return 0;
}

int main() {
    NguoiLaoDong nld;
    printf("Nhap ho ten: ");
    fgets(nld.hoTen, sizeof(nld.hoTen), stdin);
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &nld.ngay, &nld.thang, &nld.nam);

    do {
        printf("Nhap gioi tinh (Nam/Nu): ");
        scanf("%s", nld.gioiTinh);
        if (kiemTraGioiTinh(nld.gioiTinh) == 0) {
            printf("Gioi tinh khong hop le. Vui long nhap lai.\n");
        }
    } while (!kiemTraGioiTinh(nld.gioiTinh));

    int tuoiNghiHuu = tinhTuoiNghiHuu(nld.nam, nld.gioiTinh);
    int namNghiHuu = nld.nam + tuoiNghiHuu;

    printf(" Nguoi lao dong %s sinh ngay %02d/%02d/%d\n", nld.hoTen, nld.ngay, nld.thang, nld.nam);
    printf(" Gioi tinh: %s\n", nld.gioiTinh);
    printf(" Tuoi nghi huu du kien: %d\n", tuoiNghiHuu);
    printf(" Nam nghi huu du kien: %d\n", namNghiHuu);
    getch();
    return 0;
}
