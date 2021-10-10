/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include <sstream>

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

string s[N], tmp;
int a[N], t[N], it=1, n, m, K, strind[N], Jane;
ll curT;
pair <string, int> p[N];
set <pii> Set;
pii entrance[N];

int main(){
    scanf("%d%d%d", &n, &m, &K);
    
    getline(cin, tmp);
    for(int i=1; i<=n; i++){
        getline(cin, tmp);
        
        int fir = -1, las = -1;
        
        for(int j=0; j<sz(tmp); j++)
            if(tmp[j] == '"')
                fir = las, las = j;
        
        stringstream strin(tmp.substr(las+2));
        strin >> a[i];
        s[i] = tmp.substr(fir+1, las-fir-1);
    }
    
    for(int i=n+1; i<=n+m; i++){
        scanf("%d", &t[i]);
        getline(cin, tmp);
        
        int fir = -1, las = -1;
        
        for(int j=0; j<sz(tmp); j++)
            if(tmp[j] == '"')
                fir = las, las = j;
        
        stringstream strin(tmp.substr(las+2));
        strin >> a[i];
        s[i] = tmp.substr(fir+1, las-fir-1);
    }
    
    a[n+m+1] = K, s[n+m+1] = "Jane Eyre";
    n += m+1;
    
    for(int i=1; i<=n; i++) p[i] = {s[i], i}, entrance[i] = {t[i], i};
    sort(p+1, p+n+1);
    sort(entrance+1, entrance+n+1);
    
    for(int i=1; i<=n; i++) strind[p[i].ss] = i, Jane = p[i].ff == "Jane Eyre" ? i : Jane;
    
    while(true){
        while(it <= n && entrance[it].ff <= curT)
            Set.insert({strind[entrance[it].ss], entrance[it].ss}), it++;
        
        pii temp = *Set.begin(); Set.erase(temp);
        curT += a[temp.ss];
        
        if(temp.ff == Jane)
            break;
    }
    
    printf("%lld\n", curT);
    
	return 0;
}

