#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

int a[100];
vector<int> player;
vector<int> groups[4];
const int INF = 1e9+7;
pi choose() {
    for(int i = 0; i < player.size(); i++) {
        for(int j = 0; j < 2; j++) {
            if(groups[j].back() - 10 == player[i]) {
                return {j,i};
            }
        }
        for(int j = 2; j < 4; j++) {
            if(groups[j].back() + 10 == player[i]) {
                return {j,i};
            }
        }
    }
    // regular moves
    vector<pair<int,pi>> res;
    for(int i = 0; i < player.size(); i++) {
        for(int j = 0; j < 2; j++) {
            if(player[i] < groups[j].back()) continue;
            int k = player[i] - groups[j].back();
            res.push_back({k,{i, j}});
        }
        for(int j = 2; j < 4; j++) {
            if(player[i] > groups[j].back()) continue;
            int k = -player[i] + groups[j].back();
            res.push_back({k,{i, j}});
        }
    }

    if(res.empty()) return {INF, INF};
    sort(res.begin(), res.end());
    return {res[0].second.second, res[0].second.first};
}
int main() {
    
    groups[0].push_back(1);
    groups[1].push_back(1);
    groups[2].push_back(100);
    groups[3].push_back(100);
    for(int i = 1; i <= 98; i++) {
        cin>>a[i];
    }
    int k = 1;
    for(; k <= 8; k++) {
        player.push_back(a[k]);
    }
    
    for(; ; k += 2) {
        vector<int> tmp = player;
        int cnt = 0;
        pi ans1 = choose();
        if(ans1.second != INF) {
            groups[ans1.first].push_back(player[ans1.second]);
            player.erase(player.begin() + ans1.second);
            cnt++; 
        }
        pi ans2 = choose();
        if(ans2.second != INF) {
            groups[ans2.first].push_back(player[ans2.second]);
            player.erase(player.begin() + ans2.second);
            cnt++; 

        }

        if(cnt != 2) {
            break;
        }

        if(k <= 98) player.push_back(a[k]);
        if(k + 1 <= 98) player.push_back(a[k+1]);
    }

    for(int i = 0; i < 4; i++) {
        for(auto &x : groups[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
    for(auto &x : player) {
        cout << x << " ";
    }
    cout << '\n';
    for(; k <= 98; k++) {
        cout << a[k] << " ";
    }
    cout << '\n';
    return 0;
}

