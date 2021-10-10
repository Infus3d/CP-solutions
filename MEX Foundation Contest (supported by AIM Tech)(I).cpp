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

const int N = 5e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int arr[N], n, m;
vector <int> E[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        
        E[a].pb(b);
        E[b].pb(a);
    }
    
    for(int i=1; i<=n; i++){
        if(arr[i] == 0){
            int flag = 1;
            for(int j : E[i])
                if(arr[j] != 1)
                    flag = 0;
            
            if(flag == 1){
                printf("%d\n", i);
                break;
            }
        }
    }
    
	return 0;
}

