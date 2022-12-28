#include <iostream>
using namespace std;

int main()
{
    int wat;
    float price = 0;
    cout << "Enter KW: ";
    cin >> wat;
    if (wat >= 0 && wat <= 100)
        price += 2000 * wat;
    else if (wat >= 101 && wat <= 200)
        price += 100 * 2000 + (wat - 100) * 2500;
    else if (wat >= 201 && wat <= 300)
        price += 100 * 2000 + 200 * 2500 + (wat - 200) * 3000;
    else if (wat > 300)
        price += 100 * 2000 + 200 * 2500 + 300 * 3000 + (wat - 300) * 5000;

    cout << "Price: " << price << " VND";
    return 0;
}