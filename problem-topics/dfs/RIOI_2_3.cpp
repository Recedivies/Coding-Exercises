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
 
//const int MOD = (119 << 23) + 1;
const int MOD = 1e9+7;
const ll INF = (ll) 1e18;
const double PI = acos(-1);
const ld EPS = 1e-9;
const int MAX = 2e9;
const int dx[4] = {+1, -1, 0, 0};
const int dy[4] = {0, 0, +1, -1};
//const int dx[8] = {+1, +1, -1, -1, 0, 0, +1, -1};
//const int dy[8] = {+1, -1, -1, +1, +1, -1, 0, 0};
const int N = 51;
 
///****************** SOLUTION STARTS HERE ***********************///
///===============================================================///
 
vector<vector<vector<bool>>> vis;
 
void solve() {
	int n;
	scanf("%d", &n);
	vis.clear();
	vis.resize(n, vector<vector<bool>>(n, vector<bool>(1025)));
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int sx, sy, ex, ey, ans = INT_MAX;
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	stack<pair<int, pair<int, int>>> s;
	int newMask, mask = 1<<a[sx][sy];
	s.push({mask, {sx, sy}});
	vis[sx][sy][mask] = 1;
	while (!s.empty()) {
		int i = s.top().second.first;
		int j = s.top().second.second;
		mask = s.top().first;
		s.pop();
		for (int k = 0; k < 4; k++) {
			int r = i + dx[k];
			int c = j + dy[k];
			
			if (r >= 0 && c >= 0 && r < n && c < n && !vis[r][c][mask]) {
				newMask = mask | (1 << a[r][c]);
				auto f = [&](int q) {
					int ret = 0;
					while (q) {
						if (q & 1) {
							ret++;
						}
						q /= 2;
					}
					return ret;
				};
				if (r == ex && c == ey) {
					ans = min(ans, f(newMask));
				}
				vis[r][c][newMask] = 1;
				s.push({newMask, {r, c}});
			}
		}
	}
	cout << ans << '\n';
	//for (int i = 0; i < n; i++) {
		//for (int j = 0; j < n; j++) {
			//for (int k = 0; k < 1024; k++) {
				//cout << vis[i][j][k] << " ";
			//}
			//cout << '\n';
		//}
		//cout << '\n';
	//}
}
 
int main() {
	io();
	int TC = 1;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		//cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
