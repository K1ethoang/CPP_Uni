/*
    Hoàng Gia Kiệt - 6251071049
    CNTT - K62
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
    string fullname;
    short sex;
    float informaticsMark, philosophyMark, oopMark;
};

void nhapAStudent(Student &s);
void xuatAStudent(const Student &s);
float calculatorAverageScore(const Student &s);

int main()
{
    Student *student = new Student();
    cout << "\n\n\t\tNHAP THONG TIN SINH VIEN\n";
    nhapAStudent(*student);
    cout << "\n\n\t\tTHONG TIN SINH VIEN\n";
    xuatAStudent(*student);
    cout << "\n\n\t\tDIEM TRUNG BINH\n";
    cout << calculatorAverageScore(*student);
    delete student;
    return 0;
}

void nhapAStudent(Student &s)
{
    cout << setprecision(2) << fixed;
    cout << "\nNhap ho ten: ";
    fflush(stdin);
    getline(cin, s.fullname);
    do
    {
        cout << "0. Nu";
        cout << "\n1. Nam";
        cout << "\nChon gioi tinh: ";
        cin >> s.sex;
        if (s.sex != 0 && s.sex != 1)
            cout << "\nChon lai!";
    } while (s.sex != 0 && s.sex != 1);
    cout << "Nhap diem tin hoc: ";
    cin >> s.informaticsMark;
    cout << "Nhap diem triet hoc: ";
    cin >> s.philosophyMark;
    cout << "Nhap diem lap trinh huong doi tuong: ";
    cin >> s.oopMark;
}

void xuatAStudent(const Student &s)
{
    cout << "\nHo ten: " << s.fullname;
    cout << "\nGioi tinh: " << ((s.sex) ? "Nam" : "Nu");
    cout << "\nDiem tin hoc: " << s.informaticsMark;
    cout << "\nDiem triet hoc: " << s.philosophyMark;
    cout << "\nDiem lap trinh huong doi tuong: " << s.oopMark;
}

float calculatorAverageScore(const Student &s)
{
    return (float)(s.informaticsMark + s.philosophyMark + s.oopMark) / 3;
}
