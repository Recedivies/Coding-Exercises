#include <bits/stdc++.h>
using namespace std; 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef string str;

#define io() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(a) ((int)(a).size())
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
const double EPS = 1e-9;
const int MAX = 2e9 + 5;
const int dx[4] = {+1, -1, 0, 0};
const int dy[4] = {0, 0, +1, -1};
//const int dx[8] = {+1, +1, -1, -1, 0, 0, +1, -1};
//const int dy[8] = {+1, -1, -1, +1, +1, -1, 0, 0};
const int N = 1005;
 
///****************** SOLUTION STARTS HERE ***********************///
///===============================================================///
 
bool vis[N][N];
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<str> a(n);
	int x = 0, y = 0;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!ok) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'A') {
					x = i, y = j;
					ok = true;
					break;
				}
			}
		}
	}
	queue<pair<int, int> > q;
	map<pair<int, int>, pair<int, int>> mp;
	mp[{x, y}] = {-1, -1};
	q.push({x, y});
	vis[x][y] = 1;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		if (a[u][v] == 'B') {
			vector<char> path;
			while (u != x || v != y) {
				int tmp1 = mp[{u, v}].first;
				int tmp2 = mp[{u, v}].second;
				if (tmp1 == u - 1) path.PB('D');
				if (tmp1 == u + 1) path.PB('U');
				if (tmp2 == v - 1) path.PB('R');
				if (tmp2 == v + 1) path.PB('L');
				u = tmp1; v = tmp2;
			}
			printf("YES\n%d\n", sz(path));
			for (int i = sz(path) - 1; i >= 0; i--) {
				printf("%c", path[i]);
			}
			return;
		}
		for (int i = 0; i < 4; i++) {
			int r = u + dx[i];
			int c = v + dy[i];
			
			if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && a[r][c] != '#') {
				mp[{r, c}] = {u, v};
				vis[r][c] = 1;
				q.push({r, c});
			}
		}
	}
	printf("NO\n");
}
 
 
int main() {
	io();
	int TC = 1;
	//scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
 
/*
 
*/
