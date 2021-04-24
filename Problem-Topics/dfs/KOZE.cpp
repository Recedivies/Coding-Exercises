#include <bits/stdc++.h>
using namespace std; 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef string str;
 
#define io() ios::sync_with_stdio(false);	 cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(a) ((ll)(a).size())
#define mset(a , b) memset(a , b , sizeof(a))
#define aout(a , n) for(int iii = 0 ; iii < n ; iii++) cout << a[iii] << " "; cout << '\n';
#define aout2(a , n , m) for(ll iii = 0 ; iii < n ; iii++){for(ll jjj = 0 ; jjj < m ; jjj++){cout << a[iii][jjj] << " ";} cout << '\n';}
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
 
void print(ll t){cerr<<t;}
void print(int t){cerr<<t;}
void print(str t){cerr<<t;}
void print(char t){cerr<<t;}
void print(ld t){cerr<<t;}
void print(double t){cerr<<t;}
void print(ull t){cerr<<t;}
 
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p){cerr<< "{";print(p.F);cerr<<",";print(p.S);cerr<<"}";}
 
template <class T> void print(vector <T> v){cerr<<"[ ";for(T i: v){print(i);cerr<<" ";}cerr << "]";cerr << '\n';}
template <class T> void print(set <T> v){cerr<<"[ ";for(T i: v){print(i);cerr<<" ";}cerr << "]";cerr << '\n';}
template <class T> void print(multiset <T> v){cerr<<"[ ";for(T i: v){print(i);cerr<<" ";}cerr << "]";cerr << '\n';}
template <class T, class V> void print(map <T, V> v){cerr<<"[ ";for(auto i: v){print(i);cerr<<" ";}cerr << "]";cerr << '\n';}
//void print(indexed_set &v){cerr<<"[ ";for(int i: v){print(i);cerr<<" ";}cerr << "]";cerr << '\n';}
 
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a > 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a)/__gcd<T>(a, b)*(b);}
 
//const ll MOD = 1e9+7;
const ll MOD = (119 << 23) + 1;
const ll INF = (ll) 1e18;
const ld PI = acos((ld)-1);
const ld EPS = 1e-9;
const int MAX = 2e9 + 5;
const int N = 250;
 
///****************** SOLUTION STARTS HERE ***********************///
///===============================================================///
 
char a[N + 1][N + 1];
bool vis[N + 1][N + 1];
int dx[4] = {+1, -1, 0, 0};
int dy[4] = {0, 0, +1, -1};
int n, m, k, vv , ktot, vtot;
 
void dfs(int u, int v) {
	if (a[u][v] == 'k') k++;
	else if (a[u][v] == 'v') vv++;
	vis[u][v] = 1;
	
	for (int i = 0; i < 4; i++) {
		int r = u + dx[i];
		int c = v + dy[i];
		
		if (r >= 0 && c >= 0 && r < n && c < m) {
			if (!vis[r][c] && a[r][c] != '#') {
				dfs(r, c);
			}
		}
	}
}
 
void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s\n", a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && a[i][j] != '#') {
				dfs(i, j);
				if (k > vv) ktot += k;
				else vtot += vv;
				k = vv = 0;
			}
		}
	}
	printf("%d %d", ktot, vtot);
}
 
int main() {
	io();
	int TC = 1;
	//scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		//cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
