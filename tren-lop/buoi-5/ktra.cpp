/*
    Hoàng Gia Kiệt
    6251071049
    CNTT - K62
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// SV
class SV
{
private:
    string lop;
    string hoTen;

public:
    SV();
    ~SV();
    void input();
    void output();
};

// SVSP
class SVSP : public SV
{
private:
    float Dtb;
    string hocBong;

public:
    SVSP();
    void input();
    void output();
    bool operator<(const SVSP &svsp);
    bool operator>(const SVSP &svsp);
    bool operator==(const SVSP &svsp);
};

// SVCN
class SVCN : public SVSP
{
private:
    float hocPhi;

public:
    SVCN();
    void input();
    void output();
    bool operator<(const SVCN &svnc);
    bool operator>(const SVCN &svnc);
    bool operator==(const SVCN &svnc);
};

// Program
void program();

// main
int main()
{
    program();
    return 0;
}

// SV
SV::SV()
{
    lop = "-1";
    hoTen = "-1";
}

SV::~SV()
{
}

void SV::input()
{
    cout << "\n\t\tNHAP THONG TIN\n";
    fflush(stdin);
    cout << "\nNhap ma lop: ";
    getline(cin, lop);
    cout << "\nNhap ho va ten: ";
    getline(cin, hoTen);
}

void SV::output()
{
    cout << "\nMa lop: " << lop << endl;
    cout << "Ho va ten: " << hoTen << endl;
}

// SVSP
SVSP::SVSP()
{
    SV();
    Dtb = 0;
    hocBong = "-1";
}

void SVSP::input()
{
    SV::input();
    do
    {
        cout << "\nNhap DTB: ";
        cin >> Dtb;
        if (Dtb < 0 || Dtb > 10)
            cout << "\n\tDTB khong hop le!!";
    } while (Dtb < 0 || Dtb > 10);
    cout << "\nNhap hoc bong: ";
    fflush(stdin);
    getline(cin, hocBong);
}

void SVSP::output()
{
    SV::output();
    cout << "DTB: " << Dtb << endl;
    cout << "Hoc bong: " << hocBong << endl;
}

bool SVSP::operator<(const SVSP &svsp)
{
    if (Dtb < svsp.Dtb)
        return 1;
    return 0;
}

bool SVSP::operator>(const SVSP &svsp)
{
    if (Dtb > svsp.Dtb)
        return 1;
    return 0;
}

bool SVSP::operator==(const SVSP &svsp)
{
    if (Dtb == svsp.Dtb)
        return 1;
    return 0;
}

// SVCN
SVCN::SVCN()
{
    SVSP();
    hocPhi = -1;
}

void SVCN::input()
{
    SVSP::input();
    do
    {
        cout << "\nNhap Hoc Phi: ";
        cin >> hocPhi;
        if (hocPhi < 0)
            cout << "\n\tHoc Phi khong hop le!!";
    } while (hocPhi < 0);
}

void SVCN::output()
{
    SVSP::output();
    cout << "Hoc phi: " << hocPhi << endl;
}

bool SVCN::operator<(const SVCN &svcn)
{
    if (hocPhi < svcn.hocPhi)
        return 1;
    return 0;
}

bool SVCN::operator>(const SVCN &svcn)
{
    if (hocPhi < svcn.hocPhi)
        return 1;
    return 0;
}

bool SVCN::operator==(const SVCN &svcn)
{
    if (hocPhi < svcn.hocPhi)
        return 1;
    return 0;
}

void program()
{
    int choose = -1;
    vector<SVSP> svspList;
    vector<SVCN> svcnList;
    bool isExit = false;
    do
    {
        system("cls");
        cout << "1. Them 1 SVSP" << endl;
        cout << "2. Them 1 SVCN" << endl;
        cout << "3. Xem Ds SVSP" << endl;
        cout << "4. Xem Ds SVCN" << endl;
        cout << "5. Sap xep SVSP tang dan theo DTB" << endl;
        cout << "6. Sap xep SVCN giam dan theo hoc phi" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "\tLua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "1. Them 1 SVSP" << endl;
            SVSP svsp;
            svsp.input();
            cout << "\n\t\tTHONG TIN VUA NHAP\n";
            svsp.output();
            svspList.push_back(svsp);
            cout << "\nThem thanh cong!" << endl;
            system("pause");
            break;
        }
        case 2:
        {
            cout << "2. Them 1 SVCN" << endl;
            SVCN svcn;
            svcn.input();
            cout << "\n\t\tTHONG TIN VUA NHAP\n";
            svcn.output();
            svcnList.push_back(svcn);
            cout << "\nThem thanh cong!" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            cout << "3. Xem Ds SVSP" << endl;
            for (int i = 0; i < svspList.size(); i++)
            {
                cout << "\n\tSVSP "
                     << "thu " << i + 1 << endl;
                svspList[i].output();
            }
            system("pause");
            break;
        }
        case 4:
        {
            cout << "4. Xem Ds SVCN" << endl;
            for (int i = 0; i < svcnList.size(); i++)
            {
                cout << "\n\tSVCN "
                     << "thu " << i + 1 << endl;
                svcnList[i].output();
            }
            system("pause");
            break;
        }
        case 5:
        {
            cout << "5. Sap xep SVSP tang dan theo DTB" << endl;
            if (svspList.size() == 0)
                cout << "\nDS rong!!" << endl;
            else
            {
                for (int i = 0; i < svspList.size() - 1; i++)
                {
                    int minIndex = i;
                    for (int j = i + 1; j < svspList.size(); j++)
                    {
                        if (svspList[j] < svspList[minIndex])
                            minIndex = j;
                    }
                    if (minIndex != i)
                    {
                        SVSP t = svspList[i];
                        svspList[i] = svspList[minIndex];
                        svspList[minIndex] = t;
                    }
                }
                cout << "\n\tDa sap xep xong!" << endl;
            }
            system("pause");
            break;
        }
        case 6:
        {
            cout << "6. Sap xep SVCN giam dan theo hoc phi" << endl;
            if (svcnList.size() == 0)
                cout << "\nDS rong!!" << endl;
            else
            {
                for (int i = 0; i < svcnList.size() - 1; i++)
                {
                    int maxIndex = i;
                    for (int j = i + 1; j < svcnList.size(); j++)
                    {
                        if (svcnList[maxIndex] > svcnList[j])
                            maxIndex = j;
                    }
                    if (maxIndex != i)
                    {
                        SVCN t = svcnList[i];
                        svcnList[i] = svcnList[maxIndex];
                        svcnList[maxIndex] = t;
                    }
                }
                cout << "\n\tDa sap xep xong!" << endl;
            }
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
    svspList.clear();
    svcnList.clear();
}
