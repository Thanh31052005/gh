#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien 
{
    int maSoSinhVien;
    string ten;
    string email;
};

struct NhiemVu 
{
    string moTa;
    time_t hanChot;
};

struct MonHoc 
{
    string tenMonHoc;
    string phongHoc;
    time_t thoiGianBatDau;
    time_t thoiGianKetThuc;
};

SinhVien sinhVien;
vector<NhiemVu> danhSachNhiemVu;
vector<MonHoc> thoiKhoaBieu;
time_t ngayDanhGiaCuoi = 0;
time_t ngayNhacNhoCuoi = 0;

void luuDuLieu() 
{
    ofstream outFile("Sinhvien.txt");
    outFile << sinhVien.maSoSinhVien << "\n";
    outFile << sinhVien.ten << "\n";
    outFile << sinhVien.email << "\n";

    outFile << danhSachNhiemVu.size() << "\n";
    for (const auto& nv : danhSachNhiemVu) {
        outFile << nv.moTa << "\n";
        outFile << nv.hanChot << "\n";
    }

    outFile << thoiKhoaBieu.size() << "\n";
    for (const auto& mh : thoiKhoaBieu) {
        outFile << mh.tenMonHoc << "\n";
        outFile << mh.phongHoc << "\n";
        outFile << mh.thoiGianBatDau << "\n";
        outFile << mh.thoiGianKetThuc << "\n";
    }

    outFile << ngayDanhGiaCuoi << "\n";
    outFile << ngayNhacNhoCuoi << "\n";
    outFile.close();
}

void taiDuLieu() 
{
    ifstream inFile("Sinhvien.txt");
    if (!inFile) {
        cout << "Khong tim thay du lieu. Vui long nhap thong tin sinh vien.\n";
        return;
    }

    string line;
    getline(inFile, line);
    sinhVien.maSoSinhVien = stoi(line);
    getline(inFile, sinhVien.ten);
    getline(inFile, sinhVien.email);

    size_t nhiemVuSize;
    inFile >> nhiemVuSize;
    inFile.ignore();

    danhSachNhiemVu.clear();
    for (size_t i = 0; i < nhiemVuSize; ++i) {
        NhiemVu nv;
        getline(inFile, nv.moTa);
        inFile >> nv.hanChot;
        inFile.ignore();
        danhSachNhiemVu.push_back(nv);
    }

    size_t thoiKhoaBieuSize;
    inFile >> thoiKhoaBieuSize;
    inFile.ignore();

    thoiKhoaBieu.clear();
    for (size_t i = 0; i < thoiKhoaBieuSize; ++i) {
        MonHoc mh;
        getline(inFile, mh.tenMonHoc);
        getline(inFile, mh.phongHoc);
        inFile >> mh.thoiGianBatDau;
        inFile >> mh.thoiGianKetThuc;
        inFile.ignore();
        thoiKhoaBieu.push_back(mh);
    }

    inFile >> ngayDanhGiaCuoi;
    inFile >> ngayNhacNhoCuoi;
    inFile.close();
}

void nhapThongTinSinhVien() 
{
    cout << "Nhap mssv: ";
    cin >> sinhVien.maSoSinhVien;
    cin.ignore();
    cout << "Nhap ten sinh vien : ";
    getline(cin, sinhVien.ten);
    cout << "Nhap email sinh vien ";
    getline(cin, sinhVien.email);
    cout << "Da nhap thong tin thanh cong\n";
    luuDuLieu();
}

void themNhiemVu() 
{
    NhiemVu nv;
    cout << "Nhap vao nhiem vu: ";
    cin.ignore();
    getline(cin, nv.moTa);

    tm thoiGianHanChot = {};
    cout << "Nhap vao han hoan thanh (YYYY MM DD HH MM): ";
    cin >> thoiGianHanChot.tm_year >> thoiGianHanChot.tm_mon >> thoiGianHanChot.tm_mday >> thoiGianHanChot.tm_hour >> thoiGianHanChot.tm_min;
    thoiGianHanChot.tm_year -= 1900;
    thoiGianHanChot.tm_mon -= 1;
    nv.hanChot = mktime(&thoiGianHanChot);

    danhSachNhiemVu.push_back(nv);
    cout << "Da them thanh cong!\n";
    luuDuLieu();
}

void suaNhiemVu() 
{
    int index;
    cout << "Nhap vao chi so can sua (0 - " << danhSachNhiemVu.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= danhSachNhiemVu.size()) {
        cout << "Chi so sai !!!\n";
        return;
    }

    NhiemVu& nv = danhSachNhiemVu[index];
    cout << "Nhap vao nhiem vu moi: ";
    cin.ignore();
    getline(cin, nv.moTa);

    tm thoiGianHanChot = {};
    cout << "Nhap vao han chot moi (YYYY MM DD HH MM): ";
    cin >> thoiGianHanChot.tm_year >> thoiGianHanChot.tm_mon >> thoiGianHanChot.tm_mday >> thoiGianHanChot.tm_hour >> thoiGianHanChot.tm_min;
    thoiGianHanChot.tm_year -= 1900;
    thoiGianHanChot.tm_mon -= 1;
    nv.hanChot = mktime(&thoiGianHanChot);

    cout << "Da sua thanh cong!\n";
    luuDuLieu();
}

void xoaNhiemVu() 
{
    int index;
    cout << "Nhap vao chi so can xoa (0 - " << danhSachNhiemVu.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= danhSachNhiemVu.size()) {
        cout << "Chi so sai !!!\n";
        return;
    }

    danhSachNhiemVu.erase(danhSachNhiemVu.begin() + index);
    cout << "Da xoa thanh cong!\n";
    luuDuLieu();
}

void hienThiNhiemVu() 
{
    cout << "Danh sach nhiem vu : " << sinhVien.maSoSinhVien << "--" << sinhVien.ten << "--" << sinhVien.email << ":\n";
    for (size_t i = 0; i < danhSachNhiemVu.size(); ++i) {
        char buffer[80];
        strftime(buffer, 80, "%Y-%m-%d %H:%M", localtime(&danhSachNhiemVu[i].hanChot));
        cout << "Nhiem vu " << i << ": " << danhSachNhiemVu[i].moTa << ", Han chot: " << buffer << "\n";
    }
}

void timKiemNhiemVu() 
{
    string tuKhoa;
    cout << "Nhap vao tu khoa nhiem vu: ";
    cin.ignore();
    getline(cin, tuKhoa);

    cout << "Ket qua tim kiem \"" << tuKhoa << "\":\n";
    bool timThay = false;
    for (size_t i = 0; i < danhSachNhiemVu.size(); ++i) {
        if (danhSachNhiemVu[i].moTa.find(tuKhoa) != string::npos) {
            char buffer[80];
            strftime(buffer, 80, "%Y-%m-%d %H:%M", localtime(&danhSachNhiemVu[i].hanChot));
            cout << "Nhiem vu " << i << ": " << danhSachNhiemVu[i].moTa << ", Han chot : " << buffer << "\n";
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay nhiem vu\n";
    }
}

void nhacNhoNhiemVu() 
{
    time_t hienTai = time(0);
    cout << "Nhac nho hoc tap sinh vien " << sinhVien.ten << ":\n";
    for (const auto& nv : danhSachNhiemVu) {
        double giayConLai = difftime(nv.hanChot, hienTai);
        if (giayConLai < 0) {
            cout << "Nhiem vu \"" << nv.moTa << "\" da qua han!\n";
        } else {
            int ngay = giayConLai / 86400;
            int gio = ((int)giayConLai % 86400) / 3600;
            int phut = ((int)giayConLai % 3600) / 60;
            cout << "Nhiem vu \"" << nv.moTa << "\" con " << ngay << " ngay, " << gio << " gio, " << phut << " phut.\n";
        }
    }
}

void danhGiaHangThang() 
{
    time_t hienTai = time(0);
    tm* now = localtime(&hienTai);
    tm* cuoi = localtime(&ngayDanhGiaCuoi);

    if (now->tm_mon != cuoi->tm_mon || now->tm_year != cuoi->tm_year) {
        cout << "Thuc hien danh gia hang thang!\n";
        // Thực hiện đánh giá...
        ngayDanhGiaCuoi = hienTai;
        luuDuLieu();
    }
}

void nhacNhoHangNgay() 
{
    time_t hienTai = time(0);
    cout << "Nhac nho hang ngay cho sinh vien " << sinhVien.ten << ":\n";
    for (auto it = danhSachNhiemVu.begin(); it != danhSachNhiemVu.end(); ) {
        double giayConLai = difftime(it->hanChot, hienTai);
        if (giayConLai < 0) {
            cout << "Nhiem vu \"" << it->moTa << "\" da qua han. Khong dat !!!\n";
            it = danhSachNhiemVu.erase(it); // Xóa nhiệm vụ quá hạn
        } else if (giayConLai <= 86400) {
            cout << "Nhiem vu \"" << it->moTa << "\" se het han trong 24h\n";
            ++it;
        } else {
            ++it;
        }
    }
    luuDuLieu();
}

void themMonHoc() 
{
    MonHoc mh;
    cout << "Nhap ten mon hoc: ";
    cin.ignore();
    getline(cin, mh.tenMonHoc);
    cout << "Nhap phong hoc: ";
    getline(cin, mh.phongHoc);

    tm thoiGianBatDau = {};
    cout << "Nhap thoi gian hoc (YYYY MM DD HH MM): ";
    cin >> thoiGianBatDau.tm_year >> thoiGianBatDau.tm_mon >> thoiGianBatDau.tm_mday >> thoiGianBatDau.tm_hour >> thoiGianBatDau.tm_min;
    thoiGianBatDau.tm_year -= 1900;
    thoiGianBatDau.tm_mon -= 1;
    mh.thoiGianBatDau = mktime(&thoiGianBatDau);

    tm thoiGianKetThuc = {};
    cout << "Nhap thoi gian nghi (YYYY MM DD HH MM): ";
    cin >> thoiGianKetThuc.tm_year >> thoiGianKetThuc.tm_mon >> thoiGianKetThuc.tm_mday >> thoiGianKetThuc.tm_hour >> thoiGianKetThuc.tm_min;
    thoiGianKetThuc.tm_year -= 1900;
    thoiGianKetThuc.tm_mon -= 1;
    mh.thoiGianKetThuc = mktime(&thoiGianKetThuc);

    thoiKhoaBieu.push_back(mh);
    cout << "Da them mon hoc xong !\n";
    luuDuLieu();
}

void xacNhanHoanThanhNhiemVu() 
{
    int index;
    cout << "Nhap chi so nhiem vu can xac nhan hoan thanh (0 - " << danhSachNhiemVu.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= danhSachNhiemVu.size()) {
        cout << "Chi so nhiem vu khong hop le!\n";
        return;
    }

    danhSachNhiemVu.erase(danhSachNhiemVu.begin() + index);
    cout << "Da xac nhan hoan thanh nhiem vu!\n";
    luuDuLieu();
}

void suaMonHoc() 
{
    int index;
    cout << "Nhap vao chi so can chinh sua (0 - " << thoiKhoaBieu.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= thoiKhoaBieu.size()) {
        cout << "Chi so khong hop le !\n";
        return; 
    }

    MonHoc& mh = thoiKhoaBieu[index];
    cout << "Nhap ten mon hoc moi: ";
    cin.ignore();
    getline(cin, mh.tenMonHoc);
    cout << "Nhap phong hoc moi: ";
    getline(cin, mh.phongHoc);

    tm thoiGianBatDau = {};
    cout << "Nhap thoi gian bat dau hoc moi: (YYYY MM DD HH MM): ";
    cin >> thoiGianBatDau.tm_year >> thoiGianBatDau.tm_mon >> thoiGianBatDau.tm_mday >> thoiGianBatDau.tm_hour >> thoiGianBatDau.tm_min;
    thoiGianBatDau.tm_year -= 1900;
    thoiGianBatDau.tm_mon -= 1;
    mh.thoiGianBatDau = mktime(&thoiGianBatDau);

    tm thoiGianKetThuc = {};
    cout << "Nhap thoi ket thuc moi: (YYYY MM DD HH MM): ";
    cin >> thoiGianKetThuc.tm_year >> thoiGianKetThuc.tm_mon >> thoiGianKetThuc.tm_mday >> thoiGianKetThuc.tm_hour >> thoiGianKetThuc.tm_min;
    thoiGianKetThuc.tm_year -= 1900;
    thoiGianKetThuc.tm_mon -= 1;
    mh.thoiGianKetThuc = mktime(&thoiGianKetThuc);
    cout << "Da sua mon hoc thanh cong!\n";
    luuDuLieu();
}

void xoaMonHoc() 
{
    int index;
    cout << "Nhap vao chi so can xoa :(0 - " << thoiKhoaBieu.size() - 1 << "): ";
    cin >> index;
    if (index < 0 || index >= thoiKhoaBieu.size()) {
        cout << "Chi so khong hop le \n";
        return;
    }
    thoiKhoaBieu.erase(thoiKhoaBieu.begin() + index);
    cout << "Da xoa mon hoc thanh cong\n";
    luuDuLieu();
}

void hienThiThoiKhoaBieu() 
{
    cout << "TKB SINH VIEN " << sinhVien.ten << ":\n";
    for (size_t i = 0; i < thoiKhoaBieu.size(); ++i) {
        char bufferBatDau[80];
        char bufferKetThuc[80];
        strftime(bufferBatDau, 80, "%Y-%m-%d %H:%M", localtime(&thoiKhoaBieu[i].thoiGianBatDau));
        strftime(bufferKetThuc, 80, "%Y-%m-%d %H:%M", localtime(&thoiKhoaBieu[i].thoiGianKetThuc));
        cout << "Mon hoc " << i << ": " << thoiKhoaBieu[i].tenMonHoc << ", Phong: " << thoiKhoaBieu[i].phongHoc << ", Bat dau: " << bufferBatDau << ", Ket thuc: " << bufferKetThuc << "\n";
    }
}

void MenuThaoTacNv()
{
    cout << "\n--- MENU ---\n";
    cout << "1. Them nhiem vu\n";
    cout << "2. Sua nhiem vu\n";
    cout << "3. Xoa nhiem vu\n";
    cout << "0. Thoat\n";
    cout << "-----------------\n";
}

void MenuThaoTacTKB()
{
    cout << "\n--- MENU ---\n";
    cout << "1. Them mon hoc vao tkb\n";
    cout << "2. Sua mon hoc tkb\n";
    cout << "3. Xoa mon hoc tkb\n";
    cout << "0. Thoat\n";
    cout << "-----------------\n";
}

void LuachonNhiemVu()
{
    int luaChon;
    do
    {
     MenuThaoTacNv();
     cout << "Nhap vao lua chon : ";
     cin >> luaChon;
     switch (luaChon)
     {
     case 1 : 
        themNhiemVu();
        break;
     case 2 :
        suaNhiemVu();
        break;
     case 3 :
        xoaNhiemVu();
        break;
     case 0: 
      cout << "Thoat lua chon !";
      break;   
     default: 
      cout << "Vui long nhap lai !!!";
      break;
     }
    } while(luaChon != 0);
}

void LuachonTKB()
{
    int luaChon;
    do
    {
     MenuThaoTacTKB();
     cout << "Nhap vao lua chon : ";
     cin >> luaChon;
     switch (luaChon)
     {
     case 1 : 
        themMonHoc();
        break;
     case 2 :
        suaMonHoc();
        break;
     case 3 :
        xoaMonHoc();
        break;
     case 0: 
      cout << "Thoat lua chon !";
      break;   
     default: 
      cout << "Vui long nhap lai !!!";
      break;
     }
    } while(luaChon != 0);
}

void hienThiMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Nhap thong tin sinh vien\n";
    cout << "2. Cac thao tac voi nhiem vu\n";
    cout << "3. Hien thi danh sach nhiem vu cua sinh vien\n";
    cout << "4. Tim kiem nhiem vu\n";
    cout << "5. Nhac nho hang ngay\n";
    cout << "6. Xac nhan hoan thanh nhiem vu\n";
    cout << "7. Cac thao tac TKB\n";
    cout << "8. Hien thi TKB\n";
    cout << "0. Thoat chuon trinh\n";
}

int main() 
{
    taiDuLieu();
    nhacNhoHangNgay(); // Kiểm tra và nhắc nhở hàng ngày khi khởi động ctr
    danhGiaHangThang();
    int luaChon;
    do {
        hienThiMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nhapThongTinSinhVien();
                break;
            case 2:
                LuachonNhiemVu();
                break;
            case 3:
                hienThiNhiemVu();
                break;
            case 4:
                timKiemNhiemVu();
                break;
            case 5:
                nhacNhoHangNgay();
                break;
            case 6:
                xacNhanHoanThanhNhiemVu();
                break;
            case 7:
                LuachonTKB();
                break;
            case 8:
                hienThiThoiKhoaBieu();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}