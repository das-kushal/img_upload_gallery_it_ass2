
#include <bits/stdc++.h>
using namespace std;
// kd83 google kickstart
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// comment in google kickstarts
#ifndef ONLINE_JUDGE
#define kushaldas
#endif

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
typedef long double lld;
typedef unsigned long long ull;
#define test     \
    int test;    \
    cin >> test; \
    while (test--)
#define loop(i, n, k) for (int i = n; i < k; i++)
#define rloop(i, n, k) for (int i = n; i >= k; i--)
#define pb(i) push_back(i)
#define sz(i) ((int)i.size())
#define mkp(i, j) make_pair(i, j)
#define ip pair<int, int>
#define lp pair<ll, ll>
#define FOR(i, n) for (i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

#define file                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr)
#define endl '\n'
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vs vector<string>
#define vip vector<ip>
#define vlp vector<lp>
#define vvi vector<vi>
#define vvl vector<vll>
#define vs vector<string>

#ifdef kushaldas
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
template <class a>
a powmod(a t1, a t2, a mod)
{
    a res = 1;
    t1 = t1 % mod;
    if (t1 == 0)
        return 0;
    while (t2)
    {
        if (t2 & 1)
            res = (res * t1) % mod;
        t1 = (t1 * t1) % mod;
        t2 = t2 >> 1;
    }
    return res;
}
template <class a>
a powmod(a t1, a t2)
{
    a res = 1;
    if (t1 == 0)
        return 0;
    while (t2)
    {
        if (t2 & 1)
            res = (res * t1);
        t1 = (t1 * t1);
        t2 = t2 >> 1;
    }
    return res;
}
template <class T>
void printvec(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
/*--------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
}
int main()
{
    fast;
#ifdef kushaldas
    file;
#endif
    int tt = 1;
    test
    {
        google(tt);
        solve();
        tt++;
    }
    return 0;
}
int main(int argc, char const *argv[])
{

    return 0;
}
