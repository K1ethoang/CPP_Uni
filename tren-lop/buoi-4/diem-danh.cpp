/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class HocSinh
{
private:
    string hoTen;
    float van, toan;

public:
    HocSinh();
    HocSinh(const string &_hoTen, const float &_van, const float &_toan);
    HocSinh(const string &_hoTen);
    HocSinh(const HocSinh &hs);
    ~HocSinh();
    bool operator>(const HocSinh &hs);
    friend istream &operator>>(istream &is, HocSinh &hs);
    friend ostream &operator<<(ostream &os, HocSinh hs);
};

int main()
{
    HocSinh hs1, hs2;
    cout << "\n\tNhap HS1\n";
    cin >> hs1;
    cout << "\n\tXuat HS1\n";
    cout << hs1;
    cout << "\n\n\tNhap HS2\n";
    cin >> hs2;
    cout << "\n\tXuat HS2\n";
    cout << hs2;
    cout << "\n\n\tSo sanh\n";
    if (hs1 > hs2)
        cout << "Diem hs1 > hs2";
    else
        cout << "Diem hs1 < hs2";
    return 0;
}

HocSinh::HocSinh()
{
    hoTen = "";
    toan = van = 0;
}

HocSinh::HocSinh(const string &_hoTen, const float &_van, const float &_toan)
{
    hoTen = _hoTen;
    van = _van;
    toan = _toan;
}
HocSinh::HocSinh(const string &_hoTen)
{
    hoTen = _hoTen;
    van = toan = 0;
}
HocSinh::HocSinh(const HocSinh &hs)
{
    hoTen = hs.hoTen;
    van = hs.van;
    toan = hs.toan;
}

HocSinh::~HocSinh()
{
}

bool HocSinh::operator>(const HocSinh &hs)
{
    float dtb1 = (van + toan) / 2;
    float dtb2 = (hs.van + hs.toan) / 2;
    if (dtb1 > dtb2)
        return 1;
    else
        return 0;
}

istream &operator>>(istream &is, HocSinh &hs)
{
    cout << "\nNhap ho ten: ";
    fflush(stdin);
    getline(is, hs.hoTen);
    cout << "\nNhap diem van: ";
    is >> hs.van;
    cout << "\nNhap diem toan: ";
    is >> hs.toan;
    return is;
}
ostream &operator<<(ostream &os, HocSinh hs)
{
    os << "\nHo ten: " << hs.hoTen;
    os << "\nDiem van: " << hs.van;
    os << "\nDiem toan: " << hs.toan;
    return os;
}