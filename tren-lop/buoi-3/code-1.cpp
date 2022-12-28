/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
#include <math.h>
using namespace std;

class SoPhuc
{
private:
    float thuc, ao;

public:
    float getThuc();
    float getAo();
    void nhap();
    friend void xuat(const SoPhuc &sp);
    float modun1();
    friend float modun2(const SoPhuc &sp);
    SoPhuc tong(const SoPhuc &sp);
    SoPhuc hieu(const SoPhuc &sp);
    friend SoPhuc tich(const SoPhuc &sp, const SoPhuc &sp1);
    friend SoPhuc thuong(const SoPhuc &sp, const SoPhuc &sp1);
};

int soSanh(SoPhuc sp, SoPhuc sp1);

int main()
{
    SoPhuc sp1, sp2;
    cout << "\n\tSo phuc 1" << endl;
    sp1.nhap();
    xuat(sp1);
    cout << "\n\tSo phuc 2" << endl;
    sp2.nhap();
    xuat(sp2);
    cout << "\nModun: " << sp1.modun1() << endl;
    cout << "\ntong: ";
    xuat(sp1.tong(sp2));
    cout << "\nHieu: ";
    xuat(sp1.hieu(sp2));
    cout << "\nTich: ";
    xuat(tich(sp1, sp2));
    cout << "\nThuong: ";
    xuat(thuong(sp1, sp2));
    cout << "\n\tSo sanh 2 so phuc\n";
    int res = soSanh(sp1, sp2);
    if (res)
        cout << "\nSo phuc 1 = So phuc 2";
    else
        cout << "\nSo phuc 1 != So phuc 2";
    return 0;
}

float SoPhuc::getThuc()
{
    return this->thuc;
}

float SoPhuc::getAo()
{
    return this->ao;
}

void SoPhuc::nhap()
{
    cout << "\nNhap phan thuc: ";
    cin >> thuc;
    cout << "\nNhap phan ao: ";
    cin >> ao;
}

void xuat(const SoPhuc &sp)
{
    cout << sp.thuc;
    if (sp.ao == 1)
        cout << " + "
             << "i";

    else if (sp.ao > 0)
        cout << " + " << sp.ao << "i";
    else if (sp.ao < 0)
        cout << " - " << abs(sp.ao) << "i";
    cout << endl;
}

float SoPhuc::modun1()
{
    return sqrt(pow(thuc, 2) + pow(ao, 2));
}

float modun2(const SoPhuc &sp)
{
    return sqrt(pow(sp.thuc, 2) + pow(sp.ao, 2));
}

SoPhuc SoPhuc::tong(const SoPhuc &sp)
{
    SoPhuc s;
    s.thuc = thuc + sp.thuc;
    s.ao = ao + sp.ao;
    return s;
}

SoPhuc SoPhuc::hieu(const SoPhuc &sp)
{
    SoPhuc s;
    s.thuc = thuc - sp.thuc;
    s.ao = ao - sp.ao;

    return s;
}

SoPhuc tich(const SoPhuc &sp, const SoPhuc &sp1)
{
    SoPhuc s;
    s.thuc = sp.thuc * sp1.thuc - sp.ao * sp1.ao;
    s.ao = sp.thuc * sp1.ao + sp.ao * sp1.thuc;
    return s;
}

SoPhuc thuong(const SoPhuc &sp, const SoPhuc &sp1)
{
    SoPhuc s;
    s.thuc = (sp.thuc * sp1.thuc + sp.ao * sp1.ao) / pow(modun2(sp1), 2);
    s.ao = (sp.ao * sp1.thuc - sp.thuc * sp1.ao) / pow(modun2(sp1), 2);
    return s;
}

int soSanh(SoPhuc sp, SoPhuc sp1)
{

    int res;
    if (sp.getThuc() == sp1.getThuc() && sp.getAo() == sp1.getAo())
        res = 1;
    else
        res = 0;
    return res;
}