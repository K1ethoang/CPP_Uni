/*
Trần Văn Hậu - 6251071029
Hoàng Gia Kiệt - 6251071049
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SinhVien
{
private:
    string MSV;
    string hoTen;
    int namSinh;
    string lop;
    float DTB;

public:
    SinhVien();
    ~SinhVien();

    string getMSV();
    void setMSV(const string &_MSV);
    string getHoTen();
    void setHoTen(const string &_hoTen);
    int getNamSinh();
    void setNamSinh(const int &_namSinh);
    string getLop();
    void setLop(const string &_lop);
    float getDTB();
    void setDTB(const float &_DTB);

    friend istream &operator>>(istream &is, SinhVien &sv);
    friend ostream &operator<<(ostream &os, const SinhVien &sv);

    bool operator>(const SinhVien &sv);
    bool operator<(const SinhVien &sv);
    bool operator==(const SinhVien &sv);
};

void nhapDS(SinhVien sv[], const int &n);
void xuatDS(SinhVien sv[], const int &n);
void hoanVi(SinhVien &sv1, SinhVien &sv2);
void sapXepGiamDanTheoDTB(SinhVien sv[], const int &n);
void sapXepTangDanTheoNS(SinhVien sv[], const int &n);
void thongKeSinhVienBiCanhCao(SinhVien sv[], const int &n);

void program();

// main
int main()
{
    program();
    return 0;
}

SinhVien::SinhVien()
{
    MSV = "";
    hoTen = "";
    namSinh = -1;
    lop = "";
    DTB = -1;
}

SinhVien::~SinhVien()
{
}

string SinhVien::getMSV()
{
    return MSV;
}

void SinhVien::setMSV(const string &_MSV)
{
    MSV = _MSV;
}

string SinhVien::getHoTen()
{
    return hoTen;
}

void SinhVien::setHoTen(const string &_hoTen)
{
    hoTen = _hoTen;
}

int SinhVien::getNamSinh()
{
    return namSinh;
}

void SinhVien::setNamSinh(const int &_namSinh)
{
    namSinh = _namSinh;
}

string SinhVien::getLop()
{
    return lop;
}

void SinhVien::setLop(const string &_lop)
{
    lop = _lop;
}

float SinhVien::getDTB()
{
    return DTB;
}

void SinhVien::setDTB(const float &_DTB)
{
    DTB = _DTB;
}

istream &operator>>(istream &is, SinhVien &sv)
{
    cout << "\nNhap MSV: ";
    fflush(stdin);
    getline(is, sv.MSV);
    cout << "\nNhap ho ten: ";
    getline(is, sv.hoTen);
    do
    {
        cout << "\nNhap nam sinh: ";
        cin >> sv.namSinh;
    } while (sv.namSinh <= 0);
    cout << "\nNhap lop: ";
    fflush(stdin);
    getline(is, sv.lop);
    do
    {
        cout << "\nNhap diem trung binh: ";
        cin >> sv.DTB;
        if (sv.DTB <= 0 || sv.DTB > 10)
            cout << "\n\tDiem khong hop le !! Nhap lai\n";
    } while (sv.DTB <= 0 || sv.DTB > 10);
    return is;
}

ostream &operator<<(ostream &os, const SinhVien &sv)
{
    os << "\nMSV: " << sv.MSV;
    os << "\nHo ten: " << sv.hoTen;
    os << "\nNam sinh: " << sv.namSinh;
    os << "\nLop: " << sv.lop;
    os << "\nDiem trung binh: " << sv.DTB;
    return os;
}

bool SinhVien::operator>(const SinhVien &sv)
{
    if (DTB > sv.DTB)
        return 1;
    return 0;
}

bool SinhVien::operator<(const SinhVien &sv)
{
    if (DTB < sv.DTB)
        return 1;
    return 0;
}

bool SinhVien::operator==(const SinhVien &sv)
{
    if (DTB == sv.DTB)
        return 1;
    return 0;
}

// hàm ngoài
void nhapDS(SinhVien sv[], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t\tSINH VIEN " << i + 1 << endl;
        cin >> sv[i];
    }
}
void xuatDS(SinhVien sv[], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n\t\tSINH VIEN " << i + 1 << endl;
        cout << sv[i];
    }
}

void hoanVi(SinhVien &sv1, SinhVien &sv2)
{
    SinhVien temp = sv1;
    sv1 = sv2;
    sv2 = temp;
}

void sapXepGiamDanTheoDTB(SinhVien sv[], const int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sv[j] > sv[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i)
            hoanVi(sv[i], sv[maxIndex]);
    }
}
void sapXepTangDanTheoNS(SinhVien sv[], const int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sv[minIndex].getNamSinh() > sv[j].getNamSinh())
                minIndex = j;
        }
        if (minIndex != i)
            hoanVi(sv[i], sv[minIndex]);
    }
}

void thongKeSinhVienBiCanhCao(SinhVien sv[], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (sv[i].getDTB() < 1)
        {
            cout << "\n\n\t\tSINH VIEN " << i + 1 << endl;
            cout << sv[i];
        }
    }
}

void program()
{
    SinhVien sv[100];
    int n, choose;
    bool isExit = false;

    do
    {
        system("cls");
        cout << "1. Nhap ds SV" << endl;
        cout << "2. Xuat ds SV" << endl;
        cout << "3. Sap xep ds giam dan theo DTB" << endl;
        cout << "4. Sap xep ds tang dan theo NS" << endl;
        cout << "5. Thong ke SV bi canh cao" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "\tLua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "1. Nhap ds SV" << endl;
            do
            {
                cout << "\nNhap so luong sinh vien can nhap: ";
                cin >> n;
                if (n <= 0 || n > 100)
                    cout << "\n\tSo luong sv khong hop le !! (0 < n <= 100)\n";
            } while (n <= 0 || n > 100);
            nhapDS(sv, n);
            xuatDS(sv, n);
            system("pause");
            break;
        }
        case 2:
        {
            cout << "2. Xuat ds SV" << endl;
            xuatDS(sv, n);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "3. Sap xep ds giam dan theo DTB" << endl;
            sapXepGiamDanTheoDTB(sv, n);
            xuatDS(sv, n);
            system("pause");
            break;
        }
        case 4:
        {
            cout << "4. Sap xep ds tang dan theo NS" << endl;
            sapXepTangDanTheoNS(sv, n);
            xuatDS(sv, n);
            system("pause");
            break;
        }
        case 5:
        {
            cout << "5. Thong ke SV bi canh cao" << endl;
            thongKeSinhVienBiCanhCao(sv, n);
            system("pause");
            break;
        }
        case 0:
        {
            isExit = true;
            cout << "\nThoat chuong trinh thanh cong!" << endl;
            system("pause");
            break;
        }
        }
    } while (!isExit);
}