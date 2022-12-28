/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
#include <iomanip>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

private:
    PhanSo rutGon(const PhanSo &fra);
    int UCLN(PhanSo fra);

public:
    PhanSo();
    PhanSo(const int &tu_, const int &mau_);
    void nhap();
    void xuat();
    void tong(const PhanSo &fra);
    float tru(const PhanSo &fra);
};

int main()
{

    PhanSo a, b;
    cout << "\n\tNhap phan so 1\n";
    a.nhap();
    cout << "\n\tPhan so 1\n";
    a.xuat();
    cout << "\n\tNhap phan so 2\n";
    b.nhap();
    cout << "\n\tPhan so 2\n";
    b.xuat();
    cout << "\n\tSau khi cong 2 phan so\n";
    a.tong(b);
    cout << "\n\tSau khi tru 2 phan so\n";
    cout << setprecision(2) << fixed << a.tru(b);
    return 0;
}

PhanSo::PhanSo()
{
    tu = 0;
    mau = 0;
}

PhanSo::PhanSo(const int &tu_, const int &mau_)
    : tu(tu_), mau(mau_) {}

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

void PhanSo::tong(const PhanSo &fra)
{
    PhanSo c;
    if (mau == fra.mau)
    {
        c.tu = tu + fra.tu;
        c.mau = mau;
    }
    else
    {
        c.tu = tu * fra.mau + fra.tu * mau;
        c.mau = mau * fra.mau;
    }
    c = rutGon(c);
    c.xuat();
}

float PhanSo::tru(const PhanSo &fra)
{
    PhanSo c;
    if (mau == fra.mau)
    {
        c.tu = tu - fra.tu;
        c.mau = mau;
    }
    else
    {
        c.tu = tu * fra.mau - fra.tu * mau;
        c.mau = mau * fra.mau;
    }
    return (float)c.tu / c.mau;
}

int PhanSo::UCLN(PhanSo fra)
{
    int temp;
    PhanSo t;
    t.tu = abs(t.tu);
    t.mau = abs(t.mau);
    (t.tu > t.mau) ? (t.tu = fra.tu, t.mau = fra.mau) : (t.tu = fra.mau, t.mau = fra.tu);
    while (t.mau != 0)
    {
        temp = t.tu % t.mau;
        t.tu = t.mau;
        t.mau = temp;
    }
    return t.tu;
}

PhanSo PhanSo::rutGon(const PhanSo &fra)
{
    PhanSo c = fra;
    if (c.tu == 0)
        c.mau = 0;
    else if (c.tu == c.mau)
    {
        c.tu = 1;
        c.mau = 1;
    }
    else
    {
        int ucln = UCLN(c);
        c.tu /= ucln;
        c.mau /= ucln;
    }
    return c;
}
