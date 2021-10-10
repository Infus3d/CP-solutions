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

int n, m, arr[N], pos[N];
vector <pii> v;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]), pos[arr[i]] = i;
    
    for(int i=1; i<=n; i++){
        if(pos[i] == i) continue;
        
        if(abs(pos[i]-i) >= n/2)
            v.pb({i, pos[i]});
        else{
            if(i > n/2){
                v.pb({1, pos[i]});
                v.pb({1, i});
                v.pb({1, pos[i]});
            }
            else{
                if(i-pos[i] >= n/2)
                    v.pb({i, pos[i]});
                else{
                    if(pos[i] > n/2){
                        v.pb({1, pos[i]});
                        v.pb({1, n});
                        v.pb({i, n});
                        v.pb({1, n});
                        v.pb({1, pos[i]});
                    }
                    else{
                        v.pb({pos[i], n});
                        v.pb({i, n});
                        v.pb({pos[i], n});
                    }
                }
            }
        }
        
        int ps = pos[i];
        pos[arr[i]] = pos[i];
        pos[i] = i;
        swap(arr[i], arr[ps]);
    }
    
    printf("%d\n", sz(v));
    for(pii i : v)
        printf("%d %d\n", i.ff, i.ss);
    
	return 0;
}

