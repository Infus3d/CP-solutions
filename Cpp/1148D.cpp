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

int n, a[N], b[N];
vector<int> A, B;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a[i], &b[i]);
        
        if(a[i] < b[i]) B.pb(i);
        if(a[i] > b[i]) A.pb(i);
    }
    
    sort(all(A), [] (int x, int y){
        return b[x] < b[y];
    });
    
    sort(all(B), [] (int x, int y){
        return b[x] > b[y];
    });
    
    if(sz(A) >= sz(B)){
        printf("%d\n", sz(A));
        for(int i : A)
            printf("%d ", i);
        puts("");
    }
    else{
        printf("%d\n", sz(B));
        for(int i : B)
            printf("%d ", i);
        puts("");
    }
        
	return 0;
}

