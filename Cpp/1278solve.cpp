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
 
const int N = 1e2+7;
const int MOD = 1e9+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);
 
ll a, b, t, ans;
 
void solve(){
    ans = 1e18;
    cin >> a >> b; if(a > b)    swap(a, b);
    if(a == b){
        puts("0");
        return;
    }
    ll las = 0;
    umin(ans, (b-a)*2-1);
    while(a < b){
        ++las;
        a += las;
        umin(ans, las+abs(b-a)*2);
    }
    cout << ans << endl;
}
//1+2+3+5 24
//+4 +6 21


int main(){
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    
	return 0;
}
