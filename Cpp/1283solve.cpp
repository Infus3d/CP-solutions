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
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

set<pii> setik;
int n, arr[N], cn, d[N], vis[N], mx[N];
vector<pii> v;
vector<int> E[N];

int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++)
        scanf("%d", &arr[i]), d[arr[i]]++, mx[arr[i]] = arr[i];
    for(int i=1; i<=n; i++)
        if(!d[i])
            setik.insert({i, i});
    cn = n-1;
    while(cn > 0 && sz(setik) > 0){
        pii tr = *setik.begin(); setik.erase(tr);
        d[arr[cn]]--;
        umax(mx[arr[cn]], tr.ff);
        if(d[arr[cn]] == 0)
            setik.insert({mx[arr[cn]], arr[cn]});
        v.pb({tr.ss, arr[cn]});
        E[tr.ss].pb(arr[cn]);
        E[arr[cn]].pb(tr.ss);
        cn--;
    }
    
    printf("%d\n", arr[1]);
    for(pii i : v)
        printf("%d %d\n", i.ff, i.ss);
        
	return 0;
}

