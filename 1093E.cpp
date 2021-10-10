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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, a[N], b[N], pos[N], arr[N];
ordered_set fen[N];
 
inline int query(int pos, int low, int high) {
	pos ++;
	int ans = 0;
	while(pos > 0) {
		ans += fen[pos].order_of_key(high + 1) - fen[pos].order_of_key(low);
		pos -= (pos & (-pos));
	}
	return ans;
}
 
inline int get(int L, int R, int low, int high) {
	return query(R, low, high) - query(L - 1, low, high);
}
 
inline void upd(int pos, int value, int op) {
	pos ++;
	while (pos < N) {
		if(op == 1) fen[pos].insert(value);
		else fen[pos].erase(value);
		pos += (pos & (-pos));
	}
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]), pos[a[i]] = i;
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
        arr[i] = pos[b[i]];
        upd(i, arr[i], 1);
    }
    
    while(m--){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int aa, bb, xx, yy;
            scanf("%d%d%d%d", &xx, &yy, &aa, &bb);
            printf("%d\n", get(aa, bb, xx, yy));
        }
        else{
            int aa, bb;
            scanf("%d%d", &aa, &bb);
            upd(aa, arr[aa], -1);
            upd(bb, arr[bb], -1);
            upd(aa, arr[bb], 1);
            upd(bb, arr[aa], 1);
            swap(arr[aa], arr[bb]);
        }
    }
	return 0;
}

