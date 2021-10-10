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

const int N = 3e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n;
pair<pii, int> arr[N];
vector<pair<pii, int>> ans;
ll curs;
vector<int> toR, toL;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i].ff.ff);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i].ff.ss), arr[i].ss = i;
    sort(arr+1, arr+n+1);
    
    for(int i=1; i<=n; i++){
        curs += arr[i].ff.ss-arr[i].ff.ff;
        
        if(arr[i].ff.ss > arr[i].ff.ff) 
            toR.pb(i);
        if(arr[i].ff.ss < arr[i].ff.ff)
            toL.pb(i);
        
        if(curs < 0){
            puts("NO");
            return 0;
        }
    }
    if(curs != 0LL){
        puts("NO");
        return 0;
    }
    
    int cc = 0;
    for(int i : toR){
        while(cc < sz(toL) && arr[i].ff.ff < arr[i].ff.ss){
            if(arr[toL[cc]].ff.ff == arr[toL[cc]].ff.ss)    { cc++; continue; }
            if(arr[toL[cc]].ff.ff-arr[toL[cc]].ff.ss >= arr[i].ff.ss-arr[i].ff.ff){
                ans.pb({{arr[i].ss, arr[toL[cc]].ss}, arr[i].ff.ss-arr[i].ff.ff});
                arr[toL[cc]].ff.ss += arr[i].ff.ss-arr[i].ff.ff;
                break;
            }
            ans.pb({{arr[i].ss, arr[toL[cc]].ss}, arr[toL[cc]].ff.ff-arr[toL[cc]].ff.ss});
            arr[i].ff.ff += arr[toL[cc]].ff.ff-arr[toL[cc]].ff.ss;
            cc++;
        }
    }
    
    puts("YES");
    printf("%d\n", sz(ans));
    for(pair<pii, int> i : ans)
        printf("%d %d %d\n", i.ff.ff, i.ff.ss, i.ss);
    
	return 0;
}
/*
20
53 86 76 100 16 12 13 97 79 23 28 64 42 10 23 56 59 76 48 12
48 49 49 49 48 49 48 49 49 49 48 48 48 49 49 49 49 49 49 48
*/
