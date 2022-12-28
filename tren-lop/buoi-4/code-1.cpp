/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

private:
    int UCLN(PhanSo ps);

public:
    PhanSo();
    PhanSo(const int &_tu, const int &_mau);
    // hàm khởi tạo không đầy đủ tham số;
    PhanSo(const int &_tu);
    // Copy constructor
    PhanSo(const PhanSo &ps);
    ~PhanSo();
    void nhap();
    void xuat();
    PhanSo rutGon(const PhanSo &ps);
    PhanSo tong(const PhanSo &ps);
    PhanSo thuong(const PhanSo &ps);
};

int main()
{
    PhanSo ps(2, 3);
    PhanSo ps2(2, 3);
    PhanSo ps3 = ps.thuong(ps2);
    ps3.rutGon(ps3);
    ps3.xuat();
    return 0;
}

PhanSo::PhanSo()
{
    tu = mau = 1;
}

PhanSo::PhanSo(const int &_tu, const int &_mau)
{
    tu = _tu;
    mau = _mau;
}

PhanSo::PhanSo(const int &_tu)
{
    tu = _tu;
    mau = 1;
}

PhanSo::PhanSo(const PhanSo &ps)
{
    tu = ps.tu;
    mau = ps.mau;
}

PhanSo::~PhanSo()
{
    tu = mau = 0;
}

void PhanSo::nhap()
{
    cout << "\nNhap tu so: ";
    cin >> tu;
    do
    {
        cout << "\nNhap mau so: ";
        cin >> mau;
        if (mau <= 0)
            cout << "\nMau so khong hop le !" << endl;
    } while (mau <= 0);
}

void PhanSo::xuat()
{
    if (mau != 1)
        cout << tu << "/" << mau << endl;
    else
        cout << tu << endl;
}

PhanSo PhanSo::tong(const PhanSo &ps)
{
    PhanSo t;
    t.tu = tu * ps.mau + ps.tu * mau;
    t.mau = mau * ps.mau;
    return t;
}

PhanSo PhanSo::thuong(const PhanSo &ps)
{
    PhanSo t;
    t.tu = tu * ps.mau;
    t.mau = mau * ps.tu;
    return t;
}

// private
int PhanSo::UCLN(PhanSo ps)
{
    int temp;
    PhanSo t;
    t.tu = abs(t.tu);
    t.mau = abs(t.mau);
    (t.tu > t.mau) ? (t.tu = ps.tu, t.mau = ps.mau) : (t.tu = ps.mau, t.mau = ps.tu);
    while (t.mau != 0)
    {
        temp = t.tu % t.mau;
        t.tu = t.mau;
        t.mau = temp;
    }
    return t.tu;
}

PhanSo PhanSo::rutGon(const PhanSo &ps)
{
    PhanSo t = ps;
    if (t.tu == 0)
        t.mau = 0;
    else if (t.tu == t.mau)
    {
        t.tu = 1;
        t.mau = 1;
    }
    else
    {
        int ucln = UCLN(t);
        t.tu /= ucln;
        t.mau /= ucln;
    }
    return t;
}
