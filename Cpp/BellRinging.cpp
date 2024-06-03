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
    vector<vector<int>> a;
    a.push_back(vector<int>(1, 1));
    for(int i=2; i<=n; i++){
        vector<vector<int>> b;
        int cnt = 0;
        for(vector<int> &v : a){
            vector<vector<int>> curStack;
            for(int j=0; j<=(int)v.size(); j++){
                vector<int> temp;
                for(int k=0; k<j; k++){
                    temp.push_back(v[k]);
                }
                temp.push_back(i);
                for(int k=j; k<(int)v.size(); k++){
                    temp.push_back(v[k]);
                }
                curStack.push_back(temp);
            }
            cnt++;
            if(cnt % 2 == 1){
                reverse(curStack.begin(), curStack.end());
            }
            for(vector<int> temp : curStack){
                b.push_back(temp);
            }
        }
        a = b;
    }
    int idx = 0;
    for(vector<int> &v : a){
        int innerIdx = 0;
        for(int i : v){
            printf("%d", i);
            if(++innerIdx != (int)v.size()){
                printf(" ");
            }
        }
        if(++idx != (int)a.size()){
            puts("");
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
