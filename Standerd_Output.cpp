#include <iostream>
using namespace std;

int main()
{
    // int x = 10;
    // int y = 20;
    // cout << "x = " << x << endl
    //      << "y = " << y;

    double sales = 95000;
    cout << "sales =  ₹" << sales << endl;

    const double state_tax_rate = .04;
    double state_tax = sales * state_tax_rate;
    cout << "state_tax = ₹" << state_tax << endl;

    const double country_tax_rate = .02;
    double country_tax = sales * country_tax_rate;
    cout << "country_tax = ₹" << country_tax << endl;

    double total_tax = state_tax + country_tax;
    cout << "total_tax = ₹" << total_tax;

    return 0;
}