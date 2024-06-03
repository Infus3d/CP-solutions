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

const int N = 5e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
char s[N][N];


void solve(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", s[i]);
    }
    vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
    vector<vector<int>> esc(n+1, vector<int>(n+1, 0));
    vector<vector<char>> pred(n+1, vector<char>(n+1));
    map<char, pair<int, int>> delta;
    map<pair<int, int>, char> alted;
    
    alted[{-1, 0}] = 'D';
    alted[{1, 0}] = 'U';
    alted[{0, -1}] = 'R';
    alted[{0, +1}] = 'L';
    delta['U'] = {1, 0};
    delta['D'] = {-1, 0};
    delta['L'] = {0, -1};
    delta['R'] = {0, 1};
    
    queue<pair<int, int>> SQ;
    for(int i=0; i<n; i++){
        if(s[0][i] == 'U' || s[0][i] == '?'){
            // printf("************* %d %d\n", 0, i);
            esc[0][i] = 1;
            s[0][i] = 'U';
            SQ.push({0, i});
        }
        if(s[n-1][i] == 'D' || s[n-1][i] == '?'){
            esc[n-1][i] = 1;
            s[n-1][i] = 'D';
            SQ.push({n-1, i});
        }
        if(s[i][0] == 'L' || s[i][0] == '?'){
            esc[i][0] = 1;
            s[i][0] = 'L';
            SQ.push({i, 0});
        }
        if(s[i][n-1] == 'R' || s[i][n-1] == '?'){
            esc[i][n-1] = 1;
            s[i][n-1] = 'R';
            SQ.push({i, n-1});
        }
    }
    
    while(!SQ.empty()){
        auto [i, j] = SQ.front(); SQ.pop();
        // printf("popping {%d, %d} from the SQ\n", i, j);
        
        queue<pair<int, int>> Q;
        Q.push({i, j});
        vis[i][j] = 1;
        while(!Q.empty()){
            auto [x, y] = Q.front(); Q.pop();
            for(auto delt : delta){
                auto [dx, dy] = delt.ss;
                int newx = x + dx, newy = y + dy;
                if(0 <= newx && newx < n && 0 <= newy && newy < n && !vis[newx][newy]){
                    if(alted[{dx, dy}] == s[newx][newy] || s[newx][newy] == '?'){
                        vis[newx][newy] = 1;
                        if(s[newx][newy] == '?'){
                            esc[newx][newy] = 1;
                            s[newx][newy] = alted[{dx, dy}];
                            SQ.push({newx, newy});
                        } else {
                            Q.push({newx, newy});
                        }
                    }
                }
            }
        }
    }
    
    bool ok = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c", s[i][j]);
            }
            puts("");
        }
    } else {
        puts("-1");
    }
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
