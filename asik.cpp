#include <bits/stdc++.h>
using namespace std;
int a[1002];
void precal()
{
  int ind = 1;
  for (int num = 1; ind <= 1000; num++)
  {
    if (num % 3 == 0 || num % 10 == 3)
    {
    }
    else
    {
      a[ind] = num;
      ind++;
    }
  }
}

int main()
{
  int t;
  precal();
  cin >> t;
  while (t--)
  {
    int num;
    cin >> num;
    cout << a[num] << endl;
  }

  return 0;
}