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

const int INF = 1000 * 1000 * 1000;

vector<int> assignment(vector<vector<int>> a) {
    int n = a.size();
    int m = n * 2 + 2;
    vector<vector<int>> f(m, vector<int>(m));
    int s = m - 2, t = m - 1;
    int cost = 0;
    while (true) {
        vector<int> dist(m, INF);
        vector<int> p(m);
        vector<bool> inq(m, false);
        queue<int> q;
        dist[s] = 0;
        p[s] = -1;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            inq[v] = false;
            if (v == s) {
                for (int i = 0; i < n; ++i) {
                    if (f[s][i] == 0) {
                        dist[i] = 0;
                        p[i] = s;
                        inq[i] = true;
                        q.push(i);
                    }
                }
            } else {
                if (v < n) {
                    for (int j = n; j < n + n; ++j) {
                        if (f[v][j] < 1 && dist[j] > dist[v] + a[v][j - n]) {
                            dist[j] = dist[v] + a[v][j - n];
                            p[j] = v;
                            if (!inq[j]) {
                                q.push(j);
                                inq[j] = true;
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < n; ++j) {
                        if (f[v][j] < 0 && dist[j] > dist[v] - a[j][v - n]) {
                            dist[j] = dist[v] - a[j][v - n];
                            p[j] = v;
                            if (!inq[j]) {
                                q.push(j);
                                inq[j] = true;
                            }
                        }
                    }
                }
            }
        }

        int curcost = INF;
        for (int i = n; i < n + n; ++i) {
            if (f[i][t] == 0 && dist[i] < curcost) {
                curcost = dist[i];
                p[t] = i;
            }
        }
        if (curcost == INF)
            break;
        cost += curcost;
        for (int cur = t; cur != -1; cur = p[cur]) {
            int prev = p[cur];
            if (prev != -1)
                f[cur][prev] = -(f[prev][cur] = 1);
        }
    }

    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f[i][j + n] == 1)
                answer[i] = j;
        }
    }
    return answer;
}

void solve(){
    int n; scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    int maxi = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a; scanf("%d", &a);
            umax(maxi, (int)(log(a) * 1000000));
            v[i][j] = -(log(a) * 1000000);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j] += (maxi + 1000000);
        }
    }
    vector<int> res = assignment(v);
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[res[i]] = i;
    }
    for(int i : ans){
        printf("%d ", i+1);
    }
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
