/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

map <ll, int> Map;
int F[N], n, cn;
ll t, ans, arr[N];

void upd(int x){
    for(; x>0; x -= x&(-x))
        F[x]++;
}

ll get(int x){
    ll sum = 0;
    for(; x<N; x += x&(-x))
        sum += F[x];
    
    return sum;
}

int main(){
    scanf("%d%lld", &n, &t);
    
    Map[0] = 1;
    for(int i=1; i<=n; i++) scanf("%lld", arr+i), arr[i] += arr[i-1], Map[arr[i]] = 1;
    tr(i, Map)  i->ss = ++cn;
    
    for(int i=1; i<=n; i++){
        upd(Map[arr[i-1]]);
        auto upper = Map.upper_bound(arr[i]-t);
        ans += get(upper == Map.end() ? N : upper->ss);
    }
    
    printf("%lld\n", ans);
    
	return 0;
}

