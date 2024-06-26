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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    map<string, vector<int>> mk;
    for(int i=0; i<n; i++){
        string s;
        int a;
        cin >> s >> a;
        mk[s].push_back(a);
    }
    for(auto &i : mk){
        sort(all(i.ss));
    }
    int m; cin >> m;
    for(int i=0; i<m; i++){
        string s;
        int a;
        cin >> s >> a;
        printf("%d\n", mk[s][a-1]);
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
