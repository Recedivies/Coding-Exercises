#include <bits/stdc++.h>
using namespace std;

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
    return os << "]";
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

const int N = 1300003;
vector<int> edges[100003];
bool vis[100003];
int cnt;

void dfs(int u) {
	cnt++;
	vis[u] = 1;
	for (int v : edges[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	vector<bool> tmp(N, 1);
	vector<int> pr;
	tmp[0] = tmp[1] = 0;
	for (int i = 2; i < N; i++) {
		if (tmp[i]) {
			pr.push_back(i);
			for (long long j = i; j * i < N; j++) tmp[i * j] = 0;
		}
	}
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
			edges[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cnt = 0;
				dfs(i);
				res = max(res, cnt);
			}
		}
		if (res == 1) printf("%d\n", -1);
		else printf("%d\n", pr[res - 1]);
	}
}

