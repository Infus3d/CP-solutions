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

const int N = 3e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N];

void solve(){
    int n; scanf("%d", &n);
    scanf("%s", s);
    vector<int> a;
    int b = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            b++;
        } else if(b > 0){
            a.push_back(b);
            b = 0;
        }
    }
    if(b > 0){
        a.push_back(b);
    }
    int m = (int)a.size();
    int nights = n+1;
    for(int i=0; i<m; i++){
        if((i == 0 && s[0] == '1') || (i == m-1 && s[n-1] == '1')){
            nights = min(nights, a[i] - 1);
        } else {
            nights = min(nights, (a[i] - 1) / 2);
        }
    }
    // printf("nights: %d\n", nights);
    int ans = 0;
    for(int i=0; i<m; i++){
        int div = nights*2 + 1;
        ans += (a[i] + div - 1) / div;
    }
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
