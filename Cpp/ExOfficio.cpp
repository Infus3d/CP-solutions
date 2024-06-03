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
    int r, c;
    scanf("%d%d", &r, &c);
    for(int i=1; i<=2*c; i++) {
        if(i % 2) printf(" ");
        else printf("_");
    }
    puts("");
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=(2*c+1); j++) {
            if (j == 1 || j == (2*c+1)) {
                printf("|");
            } else if (j % 2 == 0 && i == r) {
                printf("_");
            } else {
                if(j % 2){
                    printf("%c", (r % 2 == 1 && (i != (r/2+1))) ? '|' : ' ');
                } else {
                    printf("%c", (r % 2 == 0 && (j/2 != (c/2+1))) ? '_' : ' ');
                }
            }
        }
        puts("");
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
