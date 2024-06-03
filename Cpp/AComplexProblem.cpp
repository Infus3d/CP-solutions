//
// Created by icpctest2314 on 11/4/2023.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

int V;
int vis[N], vis2[N], vis3[N];
int component[N], cnt;
vector<int> v;
vector<vector<pair<int,int> > > g;
vector<vector<pair<int,int> > > h;
vector<pair<int, int>> E[N];

void dfs(int u, int par){
    vis[u] = 1;
    for(auto [v, t] : g[u]){
        if(!vis[v] && t == 1){
            dfs(v, u);
        }
    }
    v.push_back(u);
}

void dfs2(int u, int par){
    vis2[u] = 1;
    component[u] = cnt;
    for(auto [v, t] : h[u]){
        if(!vis2[v] && t == 1){
            dfs2(v, u);
        }
    }
}

void dfs3(int u, int par){
    vis3[u] = 1;
    for(auto [v, t] : g[u]){
        if(!vis3[v]){
            dfs3(v, u);
        }
        if(component[u] != component[v]){
            E[component[u]].push_back({component[v], t});
        }
    }
}

int main(){
    int m, n;

    cin >> m >> n;

    map<string,int> idx;
    map<int, string> itoa;
    string s, t;

    for(int i = 0; i < m; i++){
        cin >> s >> t;
        if(idx.find(s) == idx.end()){
            itoa[idx.size()] = s;
            idx.insert(make_pair(s, idx.size()));
            g.push_back(vector<pair<int,int> > ());
        }
        if(idx.find(t) == idx.end()){
            itoa[idx.size()] = t;
            idx.insert(make_pair(t, idx.size()));
            g.push_back(vector<pair<int,int> > ());
        }

        g[idx[s]].push_back(make_pair(idx[t], 1));
    }

    for(int i = 0; i < n; i++){
        cin >> s >> t;
        if(idx.find(s) == idx.end()){
            itoa[idx.size()] = s;
            idx.insert(make_pair(s, idx.size()));
            g.push_back(vector<pair<int,int> > ());
        }
        if(idx.find(t) == idx.end()){
            itoa[idx.size()] = t;
            idx.insert(make_pair(t, idx.size()));
            g.push_back(vector<pair<int,int> > ());
        }

        g[idx[s]].push_back(make_pair(idx[t], 0));
    }

    V = g.size();
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    assert((int)v.size() == V);
    reverse(v.begin(), v.end());
    
    for(int i=0; i<V; i++){
        h.push_back(vector<pair<int, int>>());
    }
    for(int i=0; i<V; i++){
        for(auto j : g[i]){
            h[j.first].push_back({i, j.second});
        }
    }

    for(int i : v){
        if(!vis2[i]){
            dfs2(i, 0);
            cnt++;
        }
    }

    for(int i=0; i<V; i++){
        if(!vis3[i]){
            dfs3(i, 0);
        }
    }

    vector<int> deg(cnt);
    for(int i=0; i<cnt; i++){
        for(auto [v, t] : E[i]){
            deg[v]++;
        }
    }
    queue<int> Q;
    vector<int> dp(cnt, 0);
    for(int i=0; i<cnt; i++){
        if(!deg[i]){
            dp[i] = 1;
            Q.push(i);
        }
    }
    vector<int> ordered;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        ordered.push_back(u);
        for(auto [v, t] : E[u]){
            deg[v]--;
            if(!deg[v]){
                Q.push(v);
            }
        }
    }
    assert((int)ordered.size() == cnt);
    for(int i : ordered){
        // cout << "Node " << i << " (" << dp[i] << "): ";
        for(auto [v, t] : E[i]){
            dp[v] = max(dp[v], dp[i] + !t);
            // cout << "{" << v << ", " << (t ? "dashed" : "solid") << "}" << endl;
        }
        // cout << endl;
    }
    int ans = 0;
    for(int i=0; i<cnt; i++){
        ans = max(ans, dp[i]);
    }
    printf("%d %d\n", ans, cnt);
    return 0;
}
