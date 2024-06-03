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
const int K = 5;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int m, vis[K][K];
bool solvable;
char g[K][K];
map<char, vector<pair<int, int>>> endpoints;
set<char> colors;
vector<char> vcolors;

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

bool ok(int x, int y, int c){
    return (0 <= x && x < 4 && 0 <= y && y < 4 && (g[x][y] == c || g[x][y] == 'W'));
}

void dfs(int x, int y, int c){
    vis[x][y] = 1;
    if(x == endpoints[vcolors[c]][1].ff && y == endpoints[vcolors[c]][1].ss){
        // puts("putaaaaaa 1");
        c++;
        if(c == sz(vcolors)){
            // puts("putaaaaaa 2");
            int allOK = 1;
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    allOK &= vis[i][j];
                    // printf("%d", vis[i][j]);
                }
                // puts("");
            }
            solvable |= allOK;
        } else {
            dfs(endpoints[vcolors[c]][0].ff, endpoints[vcolors[c]][0].ss, c);
        }
        vis[x][y] = 0;
        return;
    }
    for(int i=0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(ok(newx, newy, vcolors[c]) && !vis[newx][newy]){
            dfs(newx, newy, c);
        }
    }
    vis[x][y] = 0;
}

void solve(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            scanf(" %c", &g[i][j]);
            if(g[i][j] != 'W'){
                colors.insert(g[i][j]);
            }
        }
    }
    for(char c : colors){
        vcolors.push_back(c);
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(g[i][j] != 'W' && endpoints.find(g[i][j]) == endpoints.end()){
                endpoints[g[i][j]] = vector<pair<int, int>>();
                endpoints[g[i][j]].push_back({i, j});
                for(int ii=0; ii<4; ii++){
                    for(int jj=0; jj<4; jj++){
                        if(!(ii == i && jj == j) && g[i][j] == g[ii][jj]){
                            // printf("***** %d %d\n", ii, jj);
                            endpoints[g[ii][jj]].push_back({ii, jj});
                            break;
                        }
                    }
                }
            }
        }
    }
    // for(char c : colors){
        // printf("%c\n", c);
        // for(auto coor : endpoints[c]){
            // printf("%d %d\n", coor.ff, coor.ss);
        // }
    // }
    m = (int)colors.size();
    solvable = false;
    auto coor = endpoints[vcolors[0]][0];
    dfs(coor.ff, coor.ss, 0);
    puts(solvable ? "solvable" : "not solvable");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
