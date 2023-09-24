#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<double> vd;
typedef vector<string> vs;
typedef unordered_set<int> s32;
typedef unordered_set<ll> s64;
typedef unordered_set<double> sd;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;

ll MOD = 1000000007;
#define INF 2e18
#define EPS 1e-9
#define ln "\n"
#define ins insert
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ook order_of_key  // Number of elements STRICTLY smaller than X
#define fbo find_by_order //  *ITERATOR* pointing to the kth element (0 order)
#define all(_x) begin(_x), end(_x)
#define sz(_x) ((ll)(_x).size())
#define forn(_i, _e) for (ll _i = 0; _i < _e; ++_i)
#define forsn(_i, _s, _e) for (ll _i = _s; _i < _e; ++_i)
#define rforn(_i, _s) for (ll _i = _s; _i >= 0; --_i)
#define rforsn(_i, _s, _e) for (ll _i = _s; _i >= _e; --_i)
#define tt     \
    ll _t;     \
    cin >> _t; \
    while (_t--)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
istream &operator>>(istream &is, vector<T> &intermediate_array)
{
    for (auto &a : intermediate_array)
        cin >> a;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &intermediate_2dmatrix)
{
    for (auto &a : intermediate_2dmatrix)
        cin >> a;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &intermediate_array)
{
    for (auto &a : intermediate_array)
        cout << a << " ";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &intermediate_2dmatrix)
{
    for (auto &a : intermediate_2dmatrix)
        cout << a << ln;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &intermediate_set)
{
    for (auto &a : intermediate_set)
        cout << a << " ";
    return os;
}

template <typename T>
void print(T a) { cout << a; }
void print() { cout << " "; }
template <typename T>
void println(T a) { cout << a << ln; }
void println() { cout << ln; }
template <typename T, typename... Args>
void print(T a, Args... b)
{
    cout << a << " ";
    print(b...);
}
template <typename T, typename... Args>
void println(T a, Args... b)
{
    cout << a << " ";
    println(b...);
}
template <typename T>
void _dbg(T a)
{
    if (typeid(a) == typeid(char))
        cout << '\'';
    if (typeid(a) == typeid(string))
        cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char))
        cout << '\'';
    if (typeid(a) == typeid(string))
        cout << '\"';
    cout << "]" << ln;
}
template <typename T, typename... Args>
void _dbg(T a, Args... b)
{
    if (typeid(a) == typeid(char))
        cout << '\'';
    if (typeid(a) == typeid(string))
        cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char))
        cout << '\'';
    if (typeid(a) == typeid(string))
        cout << '\"';
    cout << ",	";
    _dbg(b...);
}
template <typename... Args>
void dbg(Args... b)
{
    cout << '[';
    _dbg(b...);
}

void swap(ll &x, ll &y)
{
    ll temp = y;
    y = x;
    x = temp;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll powa(ll a, ll b, ll m = MOD)
{
    if (b == 0)
        return 1ll;
    else if (b == 1)
        return a;
    else
    {
        ll x = powa(a, b / 2, m);
        x *= x;
        // x %= m;
        if (b % 2)
        {
            x *= a;
            // x %= m;
        }
        return x;
    }
}

int main()
{
    fast_cin();
    int n, k;
    cin >> n >> k;
    v32 v(n);
    cin >> v;
    v32 prefix_sum(n);
    v32 sum_heights(n - k + 1);
    partial_sum(all(v), begin(prefix_sum));
    sum_heights[0] = prefix_sum[k - 1];
    forsn(i, 1, n - k + 1)
    {
        sum_heights[i] = prefix_sum[k - 1 + i] - prefix_sum[i - 1];
    }
    print(distance(begin(sum_heights), min_element(all(sum_heights))) + 1);

    return 0;
}