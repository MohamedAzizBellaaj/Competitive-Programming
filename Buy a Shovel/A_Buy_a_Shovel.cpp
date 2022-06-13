#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(_i, _e) for (ll _i = 0; _i < _e; _i++)
#define forsn(_i, _s, _e) for (ll _i = _s; _i < _e; _i++)
#define rforn(_i, _s) for (ll _i = _s; _i >= 0; _i--)
#define rforsn(_i, _s, _e) for (ll _i = _s; _i >= _e; _i--)
#define ln "\n"
#define print(_x) std::cout << _x
#define prints(_x) std::cout << _x << " "
#define println(_x) std::cout << _x << "\n"
#define printarr(_arr)    \
    for (auto &_x : _arr) \
    std::cout << _x
#define printsarr(_arr)   \
    for (auto &_x : _arr) \
    std::cout << _x << " "
#define printlnarr(_arr)  \
    for (auto &_x : _arr) \
        std::cout << _x;  \
    std::cout << "\n"
#define printslnarr(_arr)       \
    for (auto &_x : _arr)       \
        std::cout << _x << " "; \
    std::cout << "\n"
#define dbg(_x) cout << #_x << " = " << _x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define EPS 1e-9
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(_x) (_x).begin(), (_x).end()
#define sz(_x) ((ll)(_x).size())

int main()
{
    fast_cin();
    int k, r;
    cin >> k >> r;
    int s = k;
    int i = 1;
    while (s % 10 != r && s % 10 != 0)
    {
        s += k;
        i++;
    }
    print(i);

    return 0;
}