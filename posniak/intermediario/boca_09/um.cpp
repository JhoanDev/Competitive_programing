#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int num_digits = 1;
        int resto = 0;
        while (true)
        {
            resto = (resto * 10 + 1) % n;
            if (resto == 0)
                break;
            num_digits++;
        }
        cout << num_digits << endl;
    }
}