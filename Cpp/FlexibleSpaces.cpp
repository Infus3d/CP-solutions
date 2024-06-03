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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(m+2);
    a[m+1] = n;
    for(int i=1; i<=m; i++){
        scanf("%d", &a[i]);
    }
    vector<int> ans;
    for(int i=0; i<m+2; i++){
        for(int j=i+1; j<m+2; j++){
            ans.push_back(a[j] - a[i]);
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for(int i : ans) printf("%d ", i);
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
