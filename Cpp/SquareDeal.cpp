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
    vector<int> a(3), b(3);
    for(int i=0; i<3; i++){
        scanf("%d%d", &a[i], &b[i]);
    }
    for(int mask=0; mask<(1<<3); mask++){
        vector<int> aa(3), bb(3);
        for(int i=0; i<3; i++){
            aa[i] = a[i];
            bb[i] = b[i];
            if((mask>>i)&1){
                swap(aa[i], bb[i]);
            }
        }
        if(aa[0] == aa[1] && aa[1] == aa[2] && (bb[0] + bb[1] + bb[2]) == aa[0]){
            puts("YES");
            return;
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    if(i != j && j != k && i != k){
                        if(aa[i] + aa[j] == aa[k] && bb[i] == bb[j] && bb[i] + bb[k] == aa[i] + aa[j]){
                            puts("YES");
                            return;
                        }
                    }
                }
            }
        }
    }
    puts("NO");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
