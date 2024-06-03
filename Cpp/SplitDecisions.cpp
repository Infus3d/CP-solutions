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
    int n; cin >> n;
    vector<string> a;
    set<string> setik;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        setik.insert(s);
    }
    for(string i : setik){
        a.push_back(i);
    }
    n = (int)a.size();
    map<string, int> mk[21];
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i].length() == a[j].length()){
                vector<int> idx;
                for(int t=0; t<(int)a[i].length(); t++){
                    if(a[i][t] != a[j][t]){
                        idx.push_back(t);
                    }
                }
                if((int)idx.size() == 2 && idx[0] + 1 == idx[1]){
                    string t = a[i].substr(idx[0], 2) + a[j].substr(idx[0], 2);
                    t += idx[0];
                    mk[(int)a[i].length()][t]++;
                }
            }
        }
    }
    int ans = 0;
    for(int j=0; j<21; j++){
        for(auto i : mk[j]){
            if(i.ss == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while(testcase--){
        solve();
    }
    return 0;
}
