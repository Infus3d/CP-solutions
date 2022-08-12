#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int n,m,d;
int numOurHp[7];
int numTheirHp[7];
unordered_map<long long, double> dp = unordered_map<long long, double>();
int arr[(int)1e8+1];

double odds(const int& dmg) {
    if(numTheirHp[0] == m) return 1;
    if(dmg == 0) return 0;
    long long key = dmg;
    for(int i = 0; i < 7; i++) {
        key = key << 3;
        key = key | numOurHp[i+1];
    }
    for(int i = 0; i < 7; i++) {
        key = key << 3;
        key = key | numTheirHp[i+1];
    }
    if(dp.find(key) != dp.end()) return dp[key];
    double odd = 0;
    double numWays = 0;
    for(int i = 1; i <= 6; i++) {
        if(numOurHp[i] == 0) continue;
        numOurHp[i]--;
        numOurHp[i-1]++;
        odd += odds(dmg-1)*(numOurHp[i]+1);
        numWays += numOurHp[i]+1;
        numOurHp[i]++;
        numOurHp[i-1]--;
    }
    for(int i = 1; i <= 6; i++) {
        if(numTheirHp[i] == 0) continue;
        numTheirHp[i]--;
        numTheirHp[i-1]++;
        odd += odds(dmg-1)*(numTheirHp[i]+1);
        numWays += numTheirHp[i]+1;
        numTheirHp[i]++;
        numTheirHp[i-1]--;
    }
    dp[key] = odd / numWays;
    return odd / numWays;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    cin >> d;
    for(int i = 0; i < n; i++) numOurHp[i] = 0;
    for(int i = 0; i < m; i++) numTheirHp[i] = 0;
    for(int i = 0; i < n; i++) {
        int hp;
        cin >> hp;
        numOurHp[hp]++;
    }
    for(int i = 0; i < m; i++) {
        int hp;
        cin >> hp;
        numTheirHp[hp]++;
    }
    cout << setprecision(8) << odds(d);
}
