// Hoang Gia Kiet
// CNTT - K62
// 6251071049

#include <bits/stdc++.h>
using namespace std;

const float LUONGCB = 650000;

struct NgaySinh
{
    int ngay, thang, nam;
};

struct NhanVien
{
    string hoTen;
    bool gioiTinh;
    NgaySinh ngaySinh;
    int thamNien;
};

void nhap(NhanVien &nv)
{
    cout << "Nhap ho ten: ";
    fflush(stdin);
    getline(cin, nv.hoTen);
    do
    {
        cout << "Nhap gioi tinh (0 - nu, 1 - nam): ";
        cin >> nv.gioiTinh;
        if (nv.gioiTinh < 0 || nv.gioiTinh > 1)
            cout << "\tNhap lai gioi tinh\n";
    } while (nv.gioiTinh < 0 || nv.gioiTinh > 1);
    cout << "Nhap ngay sinh (ngay/thang/nam): ";
    cin >> nv.ngaySinh.ngay >> nv.ngaySinh.thang >> nv.ngaySinh.nam;
    do
    {
        cout << "Nhap tham nien (>= 0): ";
        cin >> nv.thamNien;
        if (nv.thamNien < 0)
            cout << "\nNhap lai tham nien\n";
    } while (nv.thamNien < 0);
}

void xuat(const NhanVien &nv)
{
    cout << "\nHo ten: " << nv.hoTen;
    cout << "\nGioi tinh: " << ((nv.gioiTinh == 1) ? "Nam" : "Nu");
    cout << "\nNgay sinh: " << nv.ngaySinh.ngay << "/" << nv.ngaySinh.thang << "/" << nv.ngaySinh.nam;
    cout << "\nTham nien: " << nv.thamNien;
}

float luong(const int &tn)
{
    if (tn < 12)
        return 1.92 * LUONGCB;
    else if (tn >= 12 && tn < 36)
        return 2.34 * LUONGCB;
    else if (tn >= 36 && tn < 60)
        return 3 * LUONGCB;
    else if (tn >= 60)
        return 4.5 * LUONGCB;
    return 0;
}

int main()
{
    NhanVien *nv = new NhanVien();
    cout << "\n\t\tNHAP THONG TIN NHAN VIEN\n";
    nhap(*nv);
    cout << "\n\t\tTHONG TIN NHAN VIEN VUA NHAP\n";
    xuat(*nv);
    cout << "\n\t\tLUONG CUA NHAN VIEN\n";
    cout << "\n\nLuong : " << size_t(luong(nv->thamNien)) << " d";
    delete nv;
    return 0;
}