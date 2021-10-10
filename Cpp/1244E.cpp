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

ll n, arr[N], d[N], m, costl[N], costr[N], l, r;
set<ll> s;
map<ll, int> mk;
ll k;

int main(){
    scanf("%lld%lld", &n, &k);
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
        s.insert(arr[i]);
        mk[arr[i]]++;
    }
    
    for(ll i : s)  d[++m] = i;
    for(int i=1; i<=m; i++) costl[i] = mk[d[i]] + costl[i-1];
    for(int i=m; i>=1; i--) costr[i] = mk[d[i]] + costr[i+1];
    
    l = 1, r = m;
    
    while(l < r && k > 0LL){
        if(costl[l] < costr[r]){
            if(k < 1LL*costl[l]*(d[l+1]-d[l])){
                d[l] += k/costl[l];
                break;
            }
            else{
                k -= 1LL*costl[l]*(d[l+1]-d[l]);
                l++;
            }
        }
        else{
            if(k < costr[r]*(d[r]-d[r-1])){
                d[r] -= k/costr[r];
                break;
            }
            else{
                k -= 1LL*costr[r]*(d[r]-d[r-1]);
                r--;
            }
        }
    }
    
    printf("%lld\n", d[r]-d[l]);
    
	return 0;
}

