//Author biswa_rx
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define rep(i, a) for (int i = 0; i < a; i++)
#define forl(i, a, b) for (int i = a; i <= b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define set_bits __builtin_popcountll
#define parity __builtin_parityll
#define ctz __builtin_ctzll//count trailing zeros
#define clz __builtin_clzll//lead zeros
#define MOD 1e9 + 7
#define MOD1 998244353
#define INF 1e18
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define sor(a) sort(a.begin(),a.end());
#define rev(a) reverse(a.begin(),a.end());

// template<class T>using oset=tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
/*---------------------------------------------------------------------------------------------------------------------------*/
bool revsort(ll a, ll b) {return a > b;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
void google(int t) {cout << "Case #" << t << ": ";}
void precision(int a) {cout << setprecision(a) << fixed;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
/*--------------------------------------------------------------------------------------------------------------------------*/
// template ㋛
vector<int> sieveX(int range){

    vector<int> vect(range,0);
    for (int i = 2; i < range; i++)
    {
        if(vect[i]==0){
            int j=1;
            while(i*j<range){
                vect[i*j]++;
                j++;
            }       
        }     
    }
    return vect;
}
vector<vector<int>>dynamicProgramming(){
    vector<vector<int>> vect(6,vector<int>(100001,0));
    vector<int> siev=sieveX(100001);
    for (int i = 0; i < 6; i++)
    {
        for (int j =1; j < 100001; j++)
        {
            if(siev[j]==i){
                vect[i][j]=vect[i][j-1]+1;
            }else{
                vect[i][j]=vect[i][j-1];
            }
        }
    }
    return vect;
}
vector<vector<int>> dpTable;
void run()
{
    int a,b,k;
    cin>>a >> b >> k;
    int ans=dpTable[k][b]-dpTable[k][a-1];
    cout<<ans<<nline;
    
}
int32_t main(){
    fastio();
    
    dpTable=dynamicProgramming();
    int T;
    cin >> T;
    while (T--) {
        run();
    }
    return 0;
}