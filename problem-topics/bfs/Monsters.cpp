/*
 * Author : recedivies
 * Problem Link : https://cses.fi/problemset/task/1194
 * Mei 13, 2021
 */
#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef string str;

#define io() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define mset(a, b) memset(a, b, sizeof(a))
#define lsi(a) (a & (-a))
#define print(a, n) for(int _i = 0 ; _i < n ; _i++) cout << a[_i] << " "; cout << '\n';
#define print2(a, n, m) for(int _i = 0 ; _i < n ; _i++){for(int _j = 0 ; _j < m ; _j++){cout << a[_i][_j] << " ";} cout << '\n';}

int dd[123];

ll Read() {
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  ll v = 0;
  while ('0' <= ch && ch <= '9') {
    v = v * 10 + (int) (ch - '0');
    ch = getchar();
  }
  return v;
}
 
void Write(ll x) {
  int len = 0;
  while (x > 0) {
    dd[len++] = x % 10;
    x /= 10;
  }
  for (int i = len - 1; i >= 0; i--) {
    putchar('0' + dd[i]);
  }
  if (len == 0) {
    putchar('0');
  }
  putchar('\n');
}

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]\n";
}
#define deb(args...) do {cerr << #args << " = "; faltu(args); } while(0)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s Time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

void faltu () {
    cerr << endl;
}
template <typename T>
void faltu( T a[], int n ) {
    for (int i = 0; i < n; ++i)
        cerr << a[i] << ' ';
    cerr << endl;
}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
    cerr << arg << ' ';
    faltu(rest...);
}
 
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a > 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a)/__gcd<T>(a, b)*(b);}

//const int MOD = (119 << 23) + 1;
const ll MOD = 1e9 + 7;
const ll INF = (ll) 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const int MAX = 2e9;
const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, +1, 0, -1};
//const int dx[8] = {+1, +1, -1, -1, 0, 0, +1, -1};
//const int dy[8] = {+1, -1, -1, +1, +1, -1, 0, 0};
const int N = 1e5 + 2;

vector<pair<int, int>> out;
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dis(n, vector<int>(m));
	vector<str> a(n);
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			dis[i][j] = MAX;
			if (a[i][j] == 'A') {
				x = i, y = j;
			}
		}
	}
	map<pair<int, int>, pair<int, int>> mp;
	mp[{x, y}] = {-1, -1};
	queue<pair<int, int> > q;
	q.push({x, y});
	vector<vector<int>> distance{dis};
	distance[x][y] = 0;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		if (u == 0 || v == 0 || u == n - 1 || v == m - 1) {
			out.push_back({u, v});
		}
		for (int i = 0; i < 4; i++) {
			int r = u + dx[i];
			int c = v + dy[i];
			
			if (r >= 0 && c >= 0 && r < n && c < m && a[r][c] != '#' && a[r][c] != 'M' && distance[r][c] >= distance[u][v]) {
				distance[r][c] = distance[u][v] + 1;
				q.push({r, c});
				mp[{r, c}] = {u, v};
			}
		}
	}
	bool ok = false, valid = false, moster = false;
	for (int i = 0; i < sz(out); i++) {
		vector<vector<int>> dist{dis};
		dist[out[i].first][out[i].second] = 0;
		queue<pair<int, pair<int, int> > > qq;
		qq.push({out[i].first, {out[i].second, 0}});
		while (!qq.empty()) {
			int u = qq.front().first, v = qq.front().second.first, w = qq.front().second.second;
			qq.pop();
			if (a[u][v] == 'M') {
				moster = true;
				if (distance[out[i].first][out[i].second] < w) {
					x = out[i].first, y = out[i].second;
					ok = true;
				}
				break; 
			}
			if (u == 0 || v == 0 || u == n - 1 || v == m - 1) {
				x = out[i].first, y = out[i].second;
				valid = true;
			}
			for (int j = 0; j < 4; j++) {
				int r = u + dx[j];
				int c = v + dy[j];
				
				if (r >= 0 && c >= 0 && r < n && c < m && a[r][c] != '#' && dist[r][c] > dist[u][v]) {
					dist[r][c] = dist[u][v] + 1;
					qq.push({r, {c, w + 1}});
				} 
			}
		}
		if (ok) break;
		if (valid && !moster) {
			ok = true;
		}
	}
	if (ok) {
		vector<char> path;
		while (x != -1 || y != -1) {
			int p1 = mp[{x, y}].first;
			int p2 = mp[{x, y}].second;
			if (p1 == -1 && p2 == -1) break;
			if (p1 - 1 == x) path.push_back('U');
			if (p1 + 1 == x) path.push_back('D');
			if (p2 - 1 == y) path.push_back('L');
			if (p2 + 1 == y) path.push_back('R');
			x = p1; y = p2;
		}
		cout << "YES\n" << sz(path) << "\n";
		for (int i = sz(path) - 1; i >= 0; i--) cout << path[i];
		return;
	}
	cout << "NO\n";
}

int main() {
	io();
	int TC = 1;
	//cin >> TC;
	for (int i = 1; i <= TC; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
