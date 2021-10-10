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

const int N = 1e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, cur, tot, arr[N], p[N], flag[N];
set<pii> s;
ll ans;

int roundUp(int x){ return x%10 == 0 ? x : (x/10+1)*10; }

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]), arr[i] += arr[i-1];
    for(int i=1; i<=n; i++) scanf("%d", &p[i]);
    
    s.insert({n, 1}); 
    flag[0] = flag[n+1] = 1;
    tot = roundUp(arr[n]-arr[0]), cur = 1;
    
    for(int i=1; i<=n; i++){
        pii temp = *s.lower_bound({p[i], 0});
        ans = max(ans, 1LL*tot*cur);
//        printf("i:%d p[i]:%d temp.ff:%d temp.ss:%d tot:%d cur:%d ans:%lld\n", i, p[i], temp.ff, temp.ss, tot, cur, ans);
        
        if(flag[p[i]-1] + flag[p[i]+1] == 0)
            cur++;
        if(flag[p[i]-1] + flag[p[i]+1] == 2)
            cur--;
            
        if(flag[p[i]+1] == 0){
            s.insert({temp.ff, p[i]+1});
            tot += roundUp(arr[temp.ff]-arr[p[i]]);
        }
        
        if(flag[p[i]-1] == 0){
            s.insert({p[i]-1, temp.ss});
            tot += roundUp(arr[p[i]-1]-arr[temp.ss-1]);
        }
        
        tot -= roundUp(arr[temp.ff]-arr[temp.ss-1]);
        s.erase(temp);
        flag[p[i]] = 1;
    }
    
    printf("%lld\n", ans);
    
	return 0;
}

