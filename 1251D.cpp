/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb emplace_back
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

int n, testcase;
pii arr[N];
ll k;

int main(){
    scanf("%d", &testcase);
    
    while(testcase--){
        scanf("%d%lld", &n, &k);
        for(int i=1; i<=n; i++) scanf("%d%d", &arr[i].ff, &arr[i].ss);
        
        int l = 0, r = MOD;  
        while(l < r){
            int mid = mid(l+1, r);
            
            vector <int> vec;
            ll tot = 0;
            
            for(int i=1; i<=n; i++){
                if(arr[i].ss >= mid)
                    vec.pb(arr[i].ff);
                else
                    tot += arr[i].ff;
            }
            
            if(sz(vec) <= n/2){
                r = mid-1;
                continue;
            }
            
            sort(all(vec));
            
            for(int i=0; i<sz(vec); i++)
                tot += i < (n/2-(n-sz(vec))) ? vec[i] : max(vec[i], mid);
            
            if(tot <= k)
                l = mid;
            else
                r = mid-1;
        }
        
        printf("%d\n", r);
    }
    
   	return 0;
}

