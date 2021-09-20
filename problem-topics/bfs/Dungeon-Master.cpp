/*
 * Author : recedivies
 * Problem Link : https://www.e-olymp.com/en/problems/432, https://open.kattis.com/problems/dungeon
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
const int MAX = 2e9 + 5;
const int dx[6] = {+1, 0, -1, 0, 0, 0};
const int dy[6] = {0, +1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, +1, -1};
//const int dx[8] = {+1, +1, -1, -1, 0, 0, +1, -1};
//const int dy[8] = {+1, -1, -1, +1, +1, -1, 0, 0};
const int N = 31;
///****************** SOLUTION STARTS HERE ***********************///
///===============================================================///

int l, r, c;
bool vis[N][N][N];

bool isValid(int i, int j, int k) {
	return i >= 0 && j >= 0 && k >= 0 && i < l && j < r && k < c;
}

void solve() {
	while (cin >> l >> r >> c) {
		if (!l && !r && !c) break;
		vector<vector<vector<char>>> a(l, vector<vector<char>>(r, vector<char>(c)));
		int x = -1, y = -1, z = -1;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					vis[i][j][k] = 0;
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S') {
						z = i, x = j, y = k;
					}
				}
			}
		}
		queue<pair<int, pair<int, pair<int, int> > > > q;
		q.push({z, {x, {y, 0}}});
		bool ok = false;
		while (!q.empty()) {
			int u = q.front().first, v = q.front().second.first, w = q.front().second.second.first, cnt = q.front().second.second.second;
			q.pop();
			if (a[u][v][w] == 'E') {
				ok = true;
				cout << "Escaped in " << cnt <<" minute(s)." << '\n';
				break;
			}
			
			for (int i = 0; i < 6; i++) {
				int nz = dz[i] + u;
				int nx = dx[i] + v;
				int ny = dy[i] + w;
				
				if (isValid(nz, nx, ny) && a[nz][nx][ny] != '#' && !vis[nz][nx][ny]) {
					vis[nz][nx][ny] = 1;
					q.push({nz, {nx, {ny, cnt + 1}}});
				}
			}
		}
		if (!ok) cout << "Trapped!" << '\n';
	}
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
