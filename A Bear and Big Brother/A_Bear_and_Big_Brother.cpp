#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b;
    cin >> a >> b;
    int result = 0;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        result++;
    }
    cout << result << "\n";
    return 0;
}