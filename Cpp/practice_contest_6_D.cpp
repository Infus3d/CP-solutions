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

int n, k, arr[N], start[32], ans;

bool can(int x){
    int counter = 0, soFar = 0, curRes = 0;
    
    for(int bit=30; bit>=0; bit--)
        if(start[bit]){
            int pos = start[bit];
            counter = soFar = curRes = 0;
            
            while(counter < n){
                curRes |= arr[pos];
                
                if((curRes&x) >= x){
                    soFar++;
                    curRes = 0;
                }
                
                if(soFar == k)
                    return 1;
                
                counter++; pos = pos == n ? 1 : pos+1;
            }
        }
    
    return 0;
}

int main(){
    scanf("%d%d", &n, &k);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        
        for(int j=30; j>=0; j--)
            if(!start[j] && (arr[i]&(1<<j)))
                start[j] = i;
    }
    
    for(int bit=30; bit>=0; bit--)
        if(can(ans|(1<<bit)))
            ans |= (1<<bit);

    assert(ans < (1<<30) && ans >= 0);

    printf("%d\n", ans);
    
//    for(int i=0; i<=29; i++)
//        printf("%d ", (1<<i));
//    puts("1000000000");
    
	return 0;
}

