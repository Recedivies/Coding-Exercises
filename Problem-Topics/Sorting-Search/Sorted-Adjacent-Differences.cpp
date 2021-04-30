// Problem Link : https://codeforces.com/contest/1339/problem/B

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

typedef long long ll;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		int j = n/2;
		if (n & 1) {
			printf("%d ", a[j]);
			j = n/2 + 1;
		}
		for (int i = n/2 - 1; i >= 0; i--, j++) {
			printf("%d %d ", a[i], a[j]);
		}
		printf("\n");
	}
}
