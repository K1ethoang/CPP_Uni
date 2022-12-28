/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    string ten;
    string GT;
    float OOP;
};

void nhap(SinhVien &s);
void xuat(const SinhVien &s);

int main()
{
    SinhVien *sv = new SinhVien();
    nhap(*sv);
    xuat(*sv);
    delete sv;
    return 0;
}

void nhap(SinhVien &s)
{
    cout << "\nten: ";
    fflush(stdin);
    getline(cin, s.ten);
    cout << "\nNhap gioi tinh: ";
    getline(cin, s.GT);
    cout << "\nNhap diem: ";
    cin >> s.OOP;
}
void xuat(const SinhVien &s)
{
    cout << "\nten: " << s.ten;
    cout << "\ngioi tinh: " << s.GT;
    cout << "\ndiem: " << s.OOP;
}
