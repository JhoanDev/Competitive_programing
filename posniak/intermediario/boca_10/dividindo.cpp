#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

double volume(double hliq, double b, double B, double h)
{
    double r = b + (B - b) * hliq / h;
    return M_PI * hliq * (b * b + b * r + r * r) / 3.0;
}

int main()
{
    fastio;
    int c;
    cin >> c;
    for (size_t k = 0; k < c; ++k)
    {
        int pessoas, ml;
        cin >> pessoas >> ml;
        int b, B, h;
        cin >> b >> B >> h;
        double target_alt, lower_alt = 0.0, upper_alt = 100.0;
        double vol_target = ml / (double)pessoas;
        while (upper_alt - lower_alt > 1e-7)
        {
            target_alt = (upper_alt + lower_alt) / 2.0;
            double vol = volume(target_alt, b, B, h);
            if (abs(vol_target - vol) < 1e-7)
                break;
            else if (vol_target < vol)
                upper_alt = target_alt;
            else
                lower_alt = target_alt;
        }
        target_alt = (lower_alt + upper_alt) / 2.0;
        cout << fixed << setprecision(2) << target_alt << endl;
    }
    return 0;
}