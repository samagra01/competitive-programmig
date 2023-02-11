// Author : Samagra Pathak //
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//........................// pbds //..........................................
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//         tree_order_statistics_node_update>
//         op_set;

// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//.............................................................................

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define forr(i,a,b) for(ll i = a; i >= b; i--)

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

/***************************************************(debugging)*****************************************************************************************************************************************************************/
#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void privv(vector<vi> &v) {for (auto it : v) {for (auto x : it) {cout << x << " "; } cout << endl;}}

/***************************************************(functions)*******************************************************************************************************************************************************************/
//functions
const int MAX_SIZE = 2800001; vector<int>isprime(MAX_SIZE , true); vector<int> idx(MAX_SIZE); vector<int> prime; vector<int>SPF(MAX_SIZE);
void manipulated_seive(int N) {  isprime[0] = isprime[1] = false ; for (int i = 2; i < N ; i++) {  if (isprime[i]) { prime.push_back(i);     SPF[i] = i;  }  for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {  isprime[i * prime[j]] = false;   SPF[i * prime[j]] = prime[j] ; }  }   for (int i = 0; i < (int)prime.size(); i++) { idx[prime[i]] = i + 1; }}
vector<ll> primeFactors(ll n) { vector<ll> factors; while (n > 1) { factors.push_back(SPF[n]); n /= SPF[n]; } return factors;}
ll binpo(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
ll binpomo(ll a, ll b, ll m) {a %= m; ll res = 1; while (b > 0) {if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
void precision(int a) {cout << setprecision(a) << fixed;}
ll gcd(ll a, ll b) {return (b == 0 ? a : gcd(b, a % b));}
ll mminvprime(ll a, ll b) {return binpomo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
// aa.resize(unique(all(aa)) - aa.begin());

vector<vector<ll>> best_path;
vector<vector<int>> v;
ll n, x, y;
ll rec(int ind) {
    if (ind == n + 1) {
        return 0;
    }
    ll ans = 1e18;

    for (int i = ind; i <= n; i++ ) {

        ll cost = x + best_path[ind][i];

        ans = min(ans, cost + rec(i + 1));
    }
    return ans;
}

ll bp (ll i, ll j) {

    vector<int> vv;

    for (int k = i; k <= j; k++) {
        vv.push_back(k);
    }
    if (i == j) {
        return (v[0][vv[0]] * 2 + + v[vv.size() - 1][n + 1] * 2) * y;
    }
    debug(vv)
    ll ans = 1e18;
    do {
        ll t_ans = 0;
        for (int k = 0; k < vv.size() - 1; k++) {

            t_ans += v[vv[k]][vv[k + 1]];
        }
        ans = min(ans, (t_ans * 2 + v[0][vv[0]] * 2 + + v[vv.size() - 1][n + 1] * 2  ) * y );
    } while (next_permutation(all(vv)));

    return ans;
}
void solve() {

    cin >> n >> x >> y;

    v.resize(n + 3, vector<int>(n + 3));
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            cin >> v[i][j];
        }
    }

    best_path.resize(n + 3, vector<long long int>(n + 3));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {

            best_path[i][j] = bp(i, j);

        }
    }
    debug(best_path)
    ll ans = 0;
    ans += rec(1);

    cout << ans << endl;



}



int main() {

    fastio();
    ll T = 1;
    // cin >> T;

    // manipulated_seive(2000002);
    // int number = 1;

    while (T--) {
        // cout << "Case #" << number << ": ";

        solve();
        // number++;

    }

}

