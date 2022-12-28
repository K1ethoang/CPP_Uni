/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
using namespace std;

class TaiKhoan
{
private:
    float m_fSoDu = 0;

public:
    float baoSoDu();
    void napTien(const float &fSoTien);
    void rutTien(const float &fSoTien);
};

class TaiKhoanTietKiem : public TaiKhoan
{
private:
    float kyHanGui = 0;
    float laiSuat = 0;
    int soThangDaGui = 0;

public:
    void napTien(const float &fSoTien);
    void rutTien(const float &fSoTien);
    void tangSoThangGui(const int &soThangTangThem);
    void TinhSoDuCuaThoiDiemHienTai();
};

int main()
{
    TaiKhoanTietKiem tktk;
    tktk.napTien(100000);
    tktk.rutTien(300000);
    return 0;
}

// TaiKhoan
float TaiKhoan::baoSoDu()
{
    return m_fSoDu;
}

void TaiKhoan::napTien(const float &fSoTien)
{
    m_fSoDu += fSoTien;
}

void TaiKhoan::rutTien(const float &fSoTien)
{
    if (fSoTien <= m_fSoDu)
        m_fSoDu -= fSoTien;
}

// TaiKhoanTietKiem
void TaiKhoanTietKiem::napTien(const float &fSoTien)
{
    TaiKhoan::napTien(fSoTien);
    soThangDaGui = 0;
}

void TaiKhoanTietKiem::rutTien(const float &fSoTien)
{
    if (soThangDaGui >= kyHanGui)
        TaiKhoan::rutTien(fSoTien);
}

void TaiKhoanTietKiem::tangSoThangGui(const int &soThangTangThem)
{
    if (soThangTangThem > 0)
        soThangDaGui += soThangTangThem;
}

void TaiKhoanTietKiem::TinhSoDuCuaThoiDiemHienTai()
{
}
