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
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;
const int SQ = 316;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, q, L, R, B, a, b, block_sw[SQ+10];
char s[N];
pair<pll, pll> block[N];

int add(ll x, ll y){
    return (int)((0LL + x + y) % MOD);
}

ll add1(ll x, ll y){
    return (int)(0LL + x + y);
}

int mul(ll x, ll y){
    return (int)((1LL * x * y) % MOD);
}

pair<pll, pll> calc(int x, int y){
    pll A = {1, 0}, B = {0, 1};
    
    for(int i=x; i<=y; i++){
        if(s[i] == 'A'){
            A.ff = add(A.ff, B.ff);
            A.ss = add(A.ss, B.ss);
        }
        else{
            B.ff = add(B.ff, A.ff);
            B.ss = add(B.ss, A.ss);
        }
    }
    
    assert(A.ff < 1000000000000000000LL &&  A.ff >= 0);
    assert(B.ff < 1000000000000000000LL &&  B.ff >= 0);
    assert(A.ss < 1000000000000000000LL &&  A.ss >= 0);
    assert(B.ss < 1000000000000000000LL &&  B.ss >= 0);
    
    return {A, B};
}

void unveil(int x){
    if(!block_sw[x])    return;
    
    for(int i=x*SQ; i<min((x+1)*SQ, n); i++)
        s[i] = (s[i] == 'A' ? 'B' : 'A');
    
    block_sw[x] ^= 1;
}

int main(){
    scanf("%d%d", &n, &q);
    scanf("%s", s);
        
    for(int i=0; i<n; i += SQ)
        block[i/SQ] = calc(i, min(n, i+SQ-1));
    
    while(q--){
        int type;
        
        scanf("%d%d%d", &type, &L, &R); L--, R--;
        
        if(type == 1){
            if(L/SQ == R/SQ){
                unveil(L/SQ);
                
                for(int i=L; i<=R; i++)
                    s[i] = (s[i] == 'A' ? 'B' : 'A');
                
                block[L/SQ] = calc(L/SQ*SQ, (L/SQ+1)*SQ-1);
            }
            else{
                unveil(L/SQ); unveil(R/SQ);
                
                for(int i=L; i<(L/SQ+1)*SQ; i++)
                    s[i] = s[i] == 'A' ? 'B' : 'A';
                for(int i=R/SQ*SQ; i<=R; i++)
                    s[i] = s[i] == 'A' ? 'B' : 'A';
                
                for(int i=L/SQ+1; i<R/SQ; i++)
                    block_sw[i] ^= 1;
                
                block[L/SQ] = calc(L/SQ*SQ, (L/SQ+1)*SQ-1);
                block[R/SQ] = calc(R/SQ*SQ, (R/SQ+1)*SQ-1);
            }
        }
        else{
            scanf("%d%d", &a, &b);
            
            if(L/SQ == R/SQ){
                unveil(L/SQ);
                pair <pll, pll> C = calc(L, R); //printf("%d %d %d %d\n", C.ff.ff, C.ff.ss, C.ss.ff, C.ss.ss);
                int resa = add(mul(C.ff.ff, a), mul(C.ff.ss, b));
                int resb = add(mul(C.ss.ff, a), mul(C.ss.ss, b));
                a = resa; b = resb;
                
                block[L/SQ] = calc(L/SQ*SQ, (L/SQ+1)*SQ-1);
            }
            else{
                unveil(L/SQ); unveil(R/SQ);
                pair <pll, pll> C = calc(L, (L/SQ+1)*SQ-1);
                
                int resa = add(mul(C.ff.ff, a), mul(C.ff.ss, b));
                int resb = add(mul(C.ss.ff, a), mul(C.ss.ss, b));
                a = resa; b = resb;
                
                for(int i=L/SQ+1; i<R/SQ; i++){
                    C = block[i];
                    
                    if(block_sw[i]){
                        swap(C.ff, C.ss);
                        swap(C.ff.ff, C.ff.ss);
                        swap(C.ss.ff, C.ss.ss);
                    }
                    
                    resa = add(mul(C.ff.ff, a), mul(C.ff.ss, b));
                    resb = add(mul(C.ss.ff, a), mul(C.ss.ss, b));
                    
                    a = resa;
                    b = resb;
                }
                
                C = calc((R/SQ)*SQ, R);
                resa = add(mul(C.ff.ff, a), mul(C.ff.ss, b));
                resb = add(mul(C.ss.ff, a), mul(C.ss.ss, b));
                a = resa; b = resb;
                
                block[L/SQ] = calc(L/SQ*SQ, (L/SQ+1)*SQ-1);
                block[R/SQ] = calc(R/SQ*SQ, (R/SQ+1)*SQ-1);
            }
            assert(a < MOD && a >= 0);
            assert(b < MOD && b >= 0);
            printf("%d %d\n", a, b);
        }
    }
    
	return 0;
}

