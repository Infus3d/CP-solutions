#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
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
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 2e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase, n;
int a[N], b[N], m[N];

void solve(){
    scanf("%d", &n);
    map<int, vector<int>> mk;
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &a[i], &b[i], &m[i]);
        mk[a[i]+b[i]-m[i]].pb(i);
    }
    
    int ans = 0;
    vector<pii> taste(n);
    for(auto &v : mk){
        vector<int> ind = v.second;
        vector<pii> intervals;
        for(int i : ind){
            int left_end = max(0, a[i]-m[i]);
            int right_end = a[i] - max(0, m[i] - b[i]);
            intervals.pb({right_end, left_end});
        }
        sort(all(intervals));
        int maxx = -MOD;
        vector<int> groups;
        for(pii i : intervals)
            if(maxx < i.ss){  //if previous right end of the interval is smaller than current intervals left end ---> we have a new group
                maxx = i.ff;  //keeping track of the right end of our new group
                groups.pb(maxx); //greedily selecting the right end to be the 'meeting point'
            }
        ans += sz(groups);  //there are groups.size() of different 'groupings' --> variety
        
        for(int i : ind){
            int right_end = a[i] - max(0, m[i] - b[i]);
            int belong = upper_bound(all(groups), right_end)-groups.begin()-1; // finding the corresponding group for this interval ---> what amount of meal a[i] should be left
            taste[i].ff = a[i] - groups[belong];
            taste[i].ss = m[i] - taste[i].ff;
        }
    }
    printf("%d\n", ans);
    for(pii i : taste)
        printf("%d %d\n", i.ff, i.ss);
}

int main(){
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
	return 0;
}
