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
    vector<char> a(n);
    for(int i=0; i<n; i++){
        scanf(" %c", &a[i]);
    }
    vector<int> b(n, -1);
    b[0] = (a[0] != '*' ? (a[0] == '@' ? 1 : 0) : -1);
    for(int i=1; i<n; i++){
        if(a[i] != '*'){
            if(i > 1 && b[i-2] != -1) b[i] = max(b[i-2] + (a[i] == '@'), b[i]);
            if(i > 0 && b[i-1] != -1) b[i] = max(b[i-1] + (a[i] == '@'), b[i]);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) umax(ans, b[i]);
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
