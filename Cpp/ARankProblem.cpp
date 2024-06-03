#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char ta[10], tb[10];
int rrank[101];
int n, m;

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        rrank[i] = i;
    }
    for(int i=0; i<m; i++){
        scanf("%s%s", ta, tb);
        int a = 0, b = 0;
        for(int j=1; j<(int)strlen(ta); j++){
            a = a * 10 + (ta[j] - '0');
        }
        for(int j=1; j<(int)strlen(tb); j++){
            b = b * 10 + (tb[j] - '0');
        }
        int rranka = rrank[a], rrankb = rrank[b];
        if(rranka > rrankb){
            for(int j=1; j<=n; j++){
                if(rrankb < rrank[j] && rrank[j] <= rranka){
                    rrank[j]--;
                }
            }
            rrank[b] = rranka;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(rrank[j] == i){
                printf("T%d ", j);
            }
        }
    }
    puts("");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
