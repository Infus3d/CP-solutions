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

void solve(){
    int n; scanf("%d", &n);
    if(n == 1){
        puts("1");
    } else if(n == 2 || n == 3){
        puts("-1");
    } else if(n == 4){
        puts("2 4 1 3");
    } else if(n == 5){
        puts("3 1 4 2 5");
    } else if(n == 6){
        puts("2 5 3 6 4 1");
    } else if(n == 7){
        puts("7 2 5 3 6 4 1");
    } else {
        // 8 3 6 1 4 2 5 7
        for(int i=n/2*2; i>=2; i-=2){
            printf("%d ", i);
            if(i == 8){
                printf("3 ");
            }
            if(i == 6){
                printf("1 ");
            }
        }
        for(int i=5; i<=n; i+=2){
            printf("%d ", i);
        }
        puts("");
    }
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
