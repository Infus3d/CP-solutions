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
    vector<vector<char>> board(8, vector<char>(8));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            scanf(" %c", &board[i][j]);
        }
    }
    map<char, vector<pair<int, int>>> delta;
    delta['p'] = {{+1, -1}, {+1, +1}};
    delta['n'] = {{-2, -1}, {-2, +1}, {+2, -1}, {+2, +1}, {-1, -2}, {-1, +2}, {+1, -2}, {+1, +2}};
    delta['b'] = {{-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}};
    delta['r'] = {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}};
    delta['q'] = {{-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}, {-1, 0}, {0, -1}, {+1, 0}, {0, +1}};
    vector<char> pieces{'p', 'n', 'b', 'r', 'q'};
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            for(char piece : pieces){
                if(piece == board[i][j]){
                    bool isCheck = false;
                    for(auto dir : delta[piece]){
                        int moveCnt = (piece == 'p' || piece == 'n') ? 1 : 8;
                        int newi = i + dir.first, newj = j + dir.second;
                        char foundPiece = '#';
                        while(0 <= newi && newi < 8 && 0 <= newj && newj < 8 && moveCnt > 0){
                            if(board[newi][newj] != '.'){
                                foundPiece = board[newi][newj];
                                break;
                            }
                            newi += dir.first;
                            newj += dir.second;
                            moveCnt--;
                        }
                        if(foundPiece == 'K'){
                            isCheck = true;
                            break;
                        }
                    }
                    if(isCheck){
                        // printf("i: %d, j: %d, piece: %c\n", i, j, piece);
                        puts("Yes");
                        return;
                    }
                }
            }
        }
    }
    puts("No");
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
