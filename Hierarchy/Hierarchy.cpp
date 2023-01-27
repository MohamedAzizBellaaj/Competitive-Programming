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
    for (auto &child : intermediate_array)
        cin >> child;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &intermediate_2dmatrix)
{
    for (auto &child : intermediate_2dmatrix)
        cin >> child;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &intermediate_array)
{
    for (auto &child : intermediate_array)
        cout << child << " ";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &intermediate_2dmatrix)
{
    for (auto &child : intermediate_2dmatrix)
        cout << child << ln;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &intermediate_set)
{
    for (auto &child : intermediate_set)
        cout << child << " ";
    return os;
}

template <typename T>
void print(T child) { cout << child; }
void print() { cout << " "; }
template <typename T>
void println(T child) { cout << child << ln; }
void println() { cout << ln; }
template <typename T, typename... Args>
void print(T child, Args... b)
{
    cout << child << " ";
    print(b...);
}
template <typename T, typename... Args>
void println(T child, Args... b)
{
    cout << child << " ";
    println(b...);
}
template <typename T>
void _dbg(T child)
{
    if (typeid(child) == typeid(char))
        cout << '\'';
    if (typeid(child) == typeid(string))
        cout << '\"';
    cout << child;
    if (typeid(child) == typeid(char))
        cout << '\'';
    if (typeid(child) == typeid(string))
        cout << '\"';
    cout << "]" << ln;
}
template <typename T, typename... Args>
void _dbg(T child, Args... b)
{
    if (typeid(child) == typeid(char))
        cout << '\'';
    if (typeid(child) == typeid(string))
        cout << '\"';
    cout << child;
    if (typeid(child) == typeid(char))
        cout << '\'';
    if (typeid(child) == typeid(string))
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

int gcd(int child, int b)
{
    return b == 0 ? child : gcd(b, child % b);
}

ll powa(ll child, ll b, ll m = MOD)
{
    if (b == 0)
        return 1ll;
    else if (b == 1)
        return child;
    else
    {
        ll x = powa(child, b / 2, m);
        x *= x;
        // x %= m;
        if (b % 2)
        {
            x *= child;
            // x %= m;
        }
        return x;
    }
}

vv32 adj;
vector<bool> visited;

void topological_sort(int student, v32 &arr)
{
    visited[student] = true;
    for (int const &child : adj[student])
    {
        if (!visited[child])
        {
            topological_sort(child, arr);
        }
    }
    arr.push_back(student);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int student = 1; student <= k; student++)
    {
        int w, child;
        scanf("%d", &w);
        forn(j, w)
        {
            scanf("%d", &child);
            adj[student].push_back(child);
        }
    }
    v32 topological_sorted_arr;
    for (int student = 1; student <= n; student++)
    {
        if (!visited[student])
        {
            topological_sort(student, topological_sorted_arr);
        }
    }
    int prev = 0;
    int boss_of[n + 1];
    for (int student = n - 1; student >= 0; student--)
    {
        boss_of[topological_sorted_arr[student]] = prev;
        prev = topological_sorted_arr[student];
    }
    for (int student = 1; student <= n; student++)
    {
        printf("%d\n", boss_of[student]);
    }

    return 0;
}