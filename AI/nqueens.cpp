// Aryan Jangid
#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (ll i = 0; i < n; i++)
#define rl(i, m, n) for (ll i = n; i >= m; i--)
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it;
    return ostream;
}
vector<ll> fact;
vector<ll> inversefact;
ll modularinaryExponentiation(ll base, ll exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    ll result = modularinaryExponentiation(base, exponent / 2);
    if (exponent % 2 == 1)
    {
        return (((result * result) % mod) * base) % mod;
    }
    else
    {
        return (result * result) % mod;
    }
}
// a^p=a   a^p-1=1  a^p-2=1/a
void factorial(ll n, ll mod)
{
    fact.resize(n + 1);
    inversefact.resize(n + 1);
    fact[0] = inversefact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inversefact[i] = modularinaryExponentiation(fact[i], mod - 2);
    }
}
// LCM(A, B) = (A*B) / GCD(A, B)
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int factorial(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}
int nCr(int n, int r) { return factorial(n) / (factorial(r) * factorial(n - r)); }
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
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
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
}
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
}

void invec(vector<ll> &vec, ll n)
{
    fl(i, n)
    {
        ll x;
        cin >> x;
        vec.pb(x);
    }
}

ll sumvec(vector<ll> &vec)
{
    ll sum = 0;
    for (auto i : vec)
    {
        sum += i;
    }
    return sum;
}

void printBoard(vector<string> vec)
{
    for (auto i : vec)
    {
        cout << i << endl;
    }
}


bool check(int col,int row,vector<string>&vec,int n){
        int tr=row;
        int tc=col;
        while(col>=0 && row>=0){
            if(vec[row][col]=='Q'){
                return false;
            }
            col--;
            row--;
        }
        row=tr;
        col=tc;
        
        while(col>=0){
              if(vec[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=tr;
        col=tc;
        while(col>=0 && row<n){
              if(vec[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
}


void dfs(int col,int n,vector<string>&vec,vector<vector<string>>&ans){
    // cout<<col<<endl;
    if(col==n){
        ans.push_back(vec);
        return;
    }
    for(int row=0;row<n;row++){
        if(check(col,row,vec,n)){
            vec[row][col]='Q';
            dfs(col+1,n,vec,ans);
            vec[row][col]='.';
        }
    }
}

void solve()
{
    ll n = 4;
    vector<vector<string>> ans;
    vector<string> vec;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        vec.push_back(s);
    }

    dfs(0, n, vec, ans);

    for(auto i:ans){
        for(auto k:i){
            cout<<k<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}