// Problem Link : https://codeforces.com/contest/1520/problem/G

#include <bits/stdc++.h>
using namespace std; 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

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
const int MAX = 2e9 + 5;
const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, +1, 0, -1};
//const int dx[8] = {+1, +1, -1, -1, 0, 0, +1, -1};
//const int dy[8] = {+1, -1, -1, +1, +1, -1, 0, 0};
const int N = 2e3 + 2;
///****************** SOLUTION STARTS HERE ***********************///
///===============================================================///

ll a[N][N];
ll dis[N][N];
ll ans;
ll n, m, w;

bool isValid(int i, int j) {
	return i < n && j < m && i >= 0 && j >= 0;
}

ll bfs(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dis[i][j] = INF;
		}
	}
	ll ret = INF;
	queue<pair<ll, ll>> q;
	q.push({x, y});
	dis[x][y] = 0;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int r = u + dx[k];
			int c = v + dy[k];
			
			if (isValid(r, c) && a[r][c] >= 0) {
				if (dis[r][c] > dis[u][v] + w) {
					dis[r][c] = dis[u][v] + w;
					q.push({r, c});
				}
			}
		}
	}
	if (x == 0 && y == 0) ans = min(ans, dis[n - 1][m - 1]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0 && dis[i][j] < INF)
				ret = min(ret, dis[i][j] + a[i][j]);
		}
	}
	return ret;
}

void solve() {
	n = Read(); m = Read(); w = Read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	ans = INF;
	ll res1 = bfs(0, 0);
	ll res2 = bfs(n - 1, m - 1);
	ans = min(ans, res1 + res2);
	if (ans == INF) {
		puts("-1");
	} else {
		Write(ans);
	}
}

int main() {
	//freopen("outofplace.in", "r", stdin);
	//freopen("outofplace.out", "w", stdout);
	io();
	int TC = 1;
	//cin >> TC;
	for (int i = 1; i <= TC; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
