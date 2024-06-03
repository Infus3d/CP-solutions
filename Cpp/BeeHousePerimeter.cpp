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
    int dx[] = {0, -1, -1, 0, +1, +1};
    int dy[] = {-1, -1, 0, +1, +1, 0};
    int r, k; scanf("%d%d", &r, &k);
    vector<int> a(k);
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    sort(all(a));
    int n = r * 2 + 1;
    vector<vector<int>> v(n, vector<int>(n, -1));
    int cnt = 0, p = 0;
    for(int i=1; i<n-1; i++){
        for(int j=1+max(0, i-r); j<n-1+min(0, i-r); ++j){
            ++cnt;
            if(p < k && cnt == a[p]){
                v[i][j] = a[p];
                p++;
                // printf("i: %d, j: %d\n", i, j);
            }
        }
    }
    queue<pair<int, int>> Q;
    vector<vector<int>> d(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0 || i == n-1 || j == 0 || j == n-1){
                Q.push({i, j});
                v[i][j] = 0;
            }
        }
    }
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        // printf("x: %d, y: %d\n", x, y);
        for(int i=0; i<6; i++){
            auto [newx, newy] = make_pair(x + dx[i], y + dy[i]);
            if(0 <= newx && newx < n && 0 <= newy && newy < n){
                if(v[newx][newy] == -1){
                    v[newx][newy] = 0;
                    Q.push({newx, newy});
                }
                d[newx][newy]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] > 0){
                ans += d[i][j];
            }
        }
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
