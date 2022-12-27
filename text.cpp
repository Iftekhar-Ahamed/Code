#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string x;
    fstream s, ara, output;
    s.open("string.txt", ios::in);
    ara.open("Array.txt", ios::in);
    output.open("xx.txt", ios::out);
    while (s >> x)
    {
        output << 20 << "\n"
               << x << "\n";
        for (int i = 0; i < 20; i++)
        {
            int t;
            ara >> t;
            output << t << " ";
        }
        output << "\n";
    }
}