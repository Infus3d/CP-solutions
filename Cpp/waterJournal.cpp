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
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector<int> v(n-1);
    for(int i=0; i<n-1; i++){
        scanf("%d", &v[i]);
    }
    sort(all(v));
    if(v[0] > a && v[n-2] < b) printf("-1\n");
    else if(v[0] > a) printf("%d\n", a);
    else if(v[n-2] < b) printf("%d\n", b);
    else{
        for(int i=a; i<=b; i++){
            printf("%d\n", i);
        }
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
