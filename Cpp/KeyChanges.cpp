#include "bits/stdc++.h"

#define all(x) ((x).begin(), (x).end())

using namespace std;

const int MOD = 1e9+7;
const int N = (int)1e5+2;

int m, k, c;
int idx[40000000];
vector<int> notes;
vector<int> keys;

void rec(int pos, int x){
    if(pos >= k){
        assert((int)notes.size() == k);
        int note = 0;
        for(int i=0; i<k; i++){
            note |= (1<<notes[i]);
        }
        keys.push_back(note);
        return;
    }
    for(int i=x; i<m; i++){
        notes.push_back(i);
        rec(pos+1, i+1);
        notes.pop_back();
    }
    
}

int main(){
    
    cin >> m >> k >> c;
    cin >> ws;
    //~ scanf("%d%d%d", &m, &k, &c);
    rec(0, 0);
    for(int i=0; i<(int)keys.size(); i++){
        assert(keys[i] < 40000000);
        idx[keys[i]] = i;
    }
    vector<vector<int>> chords;
    while(!cin.eof()){
        string line; getline(cin, line);
        cin >> ws;
        int cur = 0;
        vector<int> chord;
        for(int i=1; i<(int)line.length()-1; i++){
            if(line[i] == ' '){
                chord.push_back(cur);
                cur = 0;
            } else {
                cur = cur * 10 + (line[i] - '0');
            }
        }
        chord.push_back(cur);
        //~ for(int i : chord){
            //~ cout << i << " ";
        //~ }
        //~ cout << endl;
        chords.push_back(chord);
    }
    int n = (int)chords.size();
    
    auto getSupersetCount = [&](int x){
        int cnt = 0;
        for(int i : keys){
            if((i & x) == x){
                cnt++;
            }
        }
        return cnt;
    };
    
    int knownKey = -1;
    int lastChange = 0;
    int curOr = 0;
    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++){
        //~ cout << "current chord:" << std::endl;
        int curNum = 0;
        for(int j=0; j<(int)chords[i].size(); j++){
            //~ cout << chords[i][j] << " ";
            curNum |= (1<<chords[i][j]);
        }
        curOr |= curNum;
        //~ cout << endl;
        //~ cout << i << " " << curOr << " ";
        int cnt = getSupersetCount(curOr);
        //~ cout << "cnt: " << cnt << " known key: " << knownKey << " last change: " << lastChange << endl;
        if(knownKey == -1 && cnt == 1){
            knownKey = curOr;
            ans.push_back({lastChange, idx[knownKey]});
        } else if(knownKey == -1 && cnt == 0) {
            //~ assert(cnt > 1);
            ans.push_back({lastChange, -1});
            lastChange = i;
            curOr = 0;
            i--;
        } else if(knownKey != -1 && cnt == 1 && knownKey != curOr){
            knownKey = -1;
            lastChange = i;
            curOr = 0;
            i--;
        } else if(knownKey != -1 && cnt != 1){
            assert(cnt == 0);
            lastChange = i;
            knownKey = -1;
            curOr = 0;
            i--;
            //~ cout << "known key changed yo" << endl;
        }
    }
    if(getSupersetCount(curOr) == 1){
        knownKey = curOr;
    }
    //~ cout << "last knownKey: " << knownKey << " last change: " << lastChange << endl;
    ans.push_back({lastChange, knownKey == -1 ? -1 : idx[knownKey]});
    ans.push_back({n, -1});
    for(int i=0; i<(int)ans.size()-1; i++){
        for(int j=ans[i].first; j<ans[i+1].first; j++){
            if(ans[i].second == -1){
                cout << "?" << endl;
            } else {
                cout << ans[i].second << endl;
            }
        }
    }
    return 0;
}
