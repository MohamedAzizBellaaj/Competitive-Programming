#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int a = 0, d = 0;
    for (int i = 0; i < str.size(); i++)
    {
        a += str[i] == 'A';
        d += str[i] == 'D';
    }
    string result = (a > d) ? "Anton" : (a < d) ? "Danik"
                                                : "Friendship";
    cout << result << endl;
    return 0;
}