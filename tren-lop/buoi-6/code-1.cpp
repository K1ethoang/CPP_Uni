/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

// virtual

#include <iostream>
#include <string>
using namespace std;

// Nhan vien
class NhanVien
{
private:
    string hoTen;
    string gioiTinh;
    string ma;

public:
    NhanVien();
    NhanVien(string hoTen, string gioiTinh, string ma);
    ~NhanVien();
    virtual float tinhLuong() = 0;
};

// Thu viec
class ThuViec : public NhanVien
{
private:
    int thang;

public:
    ThuViec();
    ThuViec(string hoTen, string gioiTinh, string ma, int thang);
    ~ThuViec();
    void setThang(int thang);
    float tinhLuong();
};

// Chinh thuc
class ChinhThuc : public NhanVien
{
private:
    float hsl;
    float phuCap;

public:
    ChinhThuc();
    ChinhThuc(string hoTen, string gioiTinh, string ma, float hsl, float phuCap);
    ~ChinhThuc();

    float tinhLuong();
};

int main()
{
    NhanVien *tv = new ThuViec("Kiet", "Nam", "ABC", 12);
    NhanVien *ct = new ChinhThuc("Hieu", "Nam", "123", 2, 4);
    cout << "\nLuong thu viec: " << tv->tinhLuong();
    cout << "\nLuong chinh thuc: " << ct->tinhLuong();
    return 0;
}

NhanVien::NhanVien()
{
    hoTen = "";
    gioiTinh = "";
    ma = "";
}

NhanVien::NhanVien(string hoTen, string gioiTinh, string ma)
    : hoTen(hoTen), gioiTinh(gioiTinh), ma(ma) {}

NhanVien::~NhanVien()
{
}

// Thu viec
ThuViec::ThuViec()
{
    thang = 0;
}

ThuViec::ThuViec(string hoTen, string gioiTinh, string ma, int thang)
    : NhanVien(hoTen, gioiTinh, ma), thang(thang) {}

ThuViec::~ThuViec()
{
}

void ThuViec::setThang(int thang)
{
    this->thang = thang;
}

float ThuViec::tinhLuong()
{
    return 2 * thang;
}

// Chinh thuc
ChinhThuc::ChinhThuc()
{
    hsl = 0;
    phuCap = 0;
}

ChinhThuc::~ChinhThuc() {}

ChinhThuc::ChinhThuc(string hoTen, string gioiTinh, string ma, float hsl, float phuCap)
    : NhanVien(hoTen, gioiTinh, ma), hsl(hsl), phuCap(phuCap) {}

float ChinhThuc::tinhLuong()
{
    return hsl * 1699 + phuCap;
}
