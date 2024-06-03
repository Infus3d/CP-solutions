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
    vector<int> a(n), b(n+1);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        b[a[i]] = i+1;
    }
    if(b[n] < min(b[1], b[2])) printf("%d %d\n", b[n], min(b[1], b[2]));
    else if(b[n] > max(b[1], b[2])) printf("%d %d\n", b[n], max(b[1], b[2]));
    else printf("%d %d\n", b[n], b[n]);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
