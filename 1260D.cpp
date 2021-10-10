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

int las[N], fis[N], a, n, m, k, t;
pair <pii, int> P[N];
vector <int> arr, E[N];

bool can(int x){
    int dd = 0, dest = -1, last = -1;
    for(int i=1; i<=m; i++){
        for(int j : E[i])
            if(P[j].ss > x){
                if(dest == -1)
                    dest = P[j].ff.ss, last = i;
                else
                    umax(dest, P[j].ff.ss);
            }
        
        if(i == dest){
            dd += (dest - last + 1)*2;
            dest = last = -1;
        }
    }
    
    return m+1+dd <= t;
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &t);
    for(int i=1; i<=n; i++) scanf("%d", &a), arr.pb(a);
    for(int i=1; i<=k; i++)
        scanf("%d%d%d", &P[i].ff.ff, &P[i].ff.ss, &P[i].ss), E[P[i].ff.ff].pb(i);
   	sort(all(arr));
   	
   	int lo = 1, hi = N-7;
   	
   	while(lo+1 < hi){
        if(can(mid(lo, hi)))
            hi = mid(lo, hi);
        else
            lo = mid(lo, hi)+1;
    }
   	if(can(lo)) hi = lo;
   	int ind = lower_bound(all(arr), hi)-arr.begin();
   	printf("%d\n", n-ind);
   	
    return 0;
}

