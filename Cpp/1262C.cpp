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

const int N = 2e3+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, t;
char arr[N];
vector<pii> v;

int main(){
    scanf("%d", &t);
    while(t--){
        v.clear();
        scanf("%d%d", &n, &m); m--;
        scanf("%s", arr);
        
        for(int i=0; i<m*2; i+=2){
            int ind = i;
            for(int j=i; j<n; j++)
                if(arr[j] == '('){
                    ind = j;
                    break;
                }
            
            if(ind-i > 0){
                v.pb({i, ind});
                for(int j=i; j<(i+ind+1)/2; j++)
                    swap(arr[j], arr[ind-(j-i)]);
            }
            
            ind = i+1;
            
            for(int j=i+1; j<n; j++)
                if(arr[j] == ')'){
                    ind = j;
                    break;
                }
            
            if(ind-(i+1) > 0){
                v.pb({i+1, ind});
                for(int j=i+1; j<(i+1+ind+1)/2; j++)
                    swap(arr[j], arr[ind-(j-(i+1))]);
            }
        }
        
        for(int i=m*2; i<n-((n-m*2)/2); i++){
            int ind = i;
            for(int j=i; j<n; j++)
                if(arr[j] == '('){
                    ind = j;
                    break;
                }
            
            if(ind-i > 0){
                v.pb({i, ind});
                for(int j=i; j<(i+ind+1)/2; j++)
                    swap(arr[j], arr[ind-(j-i)]);
            }
        }
        
        for(int i=m*2+(n-m*2)/2; i<n; i++){
            int ind = i;
            for(int j=i; j<n; j++)
                if(arr[j] == ')'){
                    ind = j;
                    break;
                }
            
            if(ind-i > 0){
                v.pb({i, ind});
                for(int j=i; j<(i+ind+1)/2; j++)
                    swap(arr[j], arr[ind-(j-i)]);
            }
        }
        
        printf("%d\n", sz(v));
        for(pii i : v)
            printf("%d %d\n", i.ff+1, i.ss+1);
    }
    
	return 0;
}

