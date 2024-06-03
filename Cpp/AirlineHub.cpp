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
    int n;
    while(cin >> n){
        vector<double> a(n), b(n);
        for(int i=0; i<n; i++){
            cin >> a[i] >> b[i];
        }
        double miniDist = MOD;
        int idx = -1;
        reverse(all(a));
        reverse(all(b));
        for(int i=0; i<n; i++){
            double maxiDist = 0;
            for(int j=0; j<n; j++){
                double lat1 = a[i]*M_PI/180;
                double lat2 = a[j]*M_PI/180;
                double long1 = b[i]*M_PI/180;
                double long2 = b[j]*M_PI/180;
                
                double term1 = sin(lat1) * sin(lat2);
                double term2 = cos(lat1) * cos(lat2) * cos(long2 - long1);
                double dist = acos(term1 + term2) * 6371;
                
                umax(maxiDist, dist);
            }
            if(umin(miniDist, maxiDist)){
                idx = i;
            }
        }
        assert(~idx);
        printf("%.2lf %.2lf\n", a[idx], b[idx]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
