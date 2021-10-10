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

int testcase, n, m, arr[N];

int main(){
    scanf("%d", &testcase);
    
    while(testcase--){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++) 
            scanf("%d", &arr[i]);
        
        vector <pii> v;
        scanf("%d", &m);
        for(int i=1; i<=m; i++){
            int a, b; scanf("%d%d", &a, &b);
            v.pb({a, b});
        }   
        
        sort(all(v));
        for(int i=m-1; i>=0; i--)
            v[i] = {v[i].ff, max(v[i].ss, i == m-1 ? 0 : v[i+1].ss)};
        
        int cur = 1;
        int flag = 0;
        int ans = 0;
        
        while(cur <= n){
            int cmax = 0, last = -1;
            
            for(int i=cur; i<=n; i++){
                umax(cmax, arr[i]);
                int ind = lower_bound(all(v), mp(cmax, 0))-v.begin();
                
                if(ind == sz(v))    { last = -1; break; }
                if(i-cur+1 > v[ind].ss) break;
                
                last = i;
            }
            
            if(last == -1){
                flag = 1;
                break;
            }
            
            cur = last+1;
            ans++;
        }
        
        printf("%d\n", flag ? -1 : ans);
    }
    
	return 0;
}

