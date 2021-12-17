#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
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
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 1e5+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

ll a, b, cna, cnb;
vector<int> A, digA(10), B, digB(10), sofar(20);

int disassemble(ll x, vector<int> &v, vector<int> &dig){
    int cn = 0;
    while(x > 0){
        dig[x%10]++;
        v.pb(x%10);
        x/=10;
        cn++;
    }
    reverse(all(v));
    return cn;
}

bool isOk(int ind){
    vector<int> lim(10, 0);
    for(int i=ind+1; i<cna; i++)
        for(int j=0; j<=9; j++)
            if(lim[j] < digA[j]){
                sofar[i] = j;
                lim[j]++;
                break;
            }
    
    ll num = 0;
    for(int i=0; i<cna; i++)
        num = num*10 + sofar[i];
    
    return num <= b;
}

int main(){
    scanf("%lld%lld", &a, &b);
    cna = disassemble(a, A, digA);
    cnb = disassemble(b, B, digB);
    
    assert(cna <= cnb);
    if(cna < cnb){
        for(int i=9; i>=0; i--)
            while(digA[i]--)
                printf("%d", i);
    }
    else{
        for(int i=0; i<cna; i++){
            for(int dig=9; dig>=0; dig--)
                if(digA[dig]){
                    digA[dig]--;
                    sofar[i] = dig;
                    if(isOk(i))
                        break;
                    digA[dig]++;
                }
        }
        for(int i=0; i<cna; i++)
            printf("%d", sofar[i]);
    }
    puts("");
    
	return 0;
}
