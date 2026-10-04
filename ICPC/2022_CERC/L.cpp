/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int cards[99];
vector<int> players;
vector<int> groups[4];
pi playCard() {
    // backward trick
    for(int i = 0; i < players.size(); i++) {
        for(int j = 0; j < 2; j++) {
            if(players[i] < groups[j].back() && groups[j].back() - players[i] == 10) {
                return make_pair(j,i);
            }
        }
        for(int j = 2; j < 4; j++) {
            if(players[i] > groups[j].back() && players[i] - groups[j].back() == 10) {
                return make_pair(j,i);
            }
        }
    }

    // normal play
    int val = INF, group = INF, idx = INF;
    for(int i = 0; i < players.size(); i++) {
        for(int j = 0; j < 2; j++) {
            if(players[i] < groups[j].back()) continue;
            int x = players[i] - groups[j].back();
            if(x < val) {
                val = x;
                group = j;
                idx = i;
            } else if(x == val) {
                if(i < idx) {
                    idx = i;
                    group = j;
                } else if(i == idx) {
                    if(j < group) {
                        group = j;
                    }
                }
            }
        }
        for(int j = 2; j < 4; j++) {
            if(players[i] > groups[j].back()) continue;
            int x = groups[j].back() - players[i];
            if(x < val) {
                val = x;
                group = j;
                idx = i;
            } else if(x == val) {
                if(i < idx) {
                    idx = i;
                    group = j;
                } else if(i == idx) {
                    if(j < group) {
                        group = j;
                    }
                }
            }
        }
    }

    return make_pair(group,idx);
}
void solve(){

    for(int i = 1; i <= 8; i++) {
        cin>>cards[i];
        players.push_back(cards[i]);
    }
    for(int i = 9; i <= 98; i++) cin>>cards[i];
    for(int i = 0; i < 2; i++) groups[i].push_back(1);
    for(int i = 2; i < 4; i++) groups[i].push_back(100);
    int k = 9;
    while(true) {
        int cnt = 0;
        pi now = playCard();
        if(now.first != INF) {
            cnt++;
            groups[now.first].push_back(players[now.second]);
            players.erase(players.begin() + now.second);
        }
        now = playCard();
        if(now.first != INF) {
            cnt++;
            groups[now.first].push_back(players[now.second]);
            players.erase(players.begin() + now.second);
        }
        if(cnt != 2) break;

        if(k <= 98) players.push_back(cards[k]);
        if(k+1 <= 98) players.push_back(cards[k+1]);
        k += 2;
    }

    for(int i = 0; i < 4; i++) {
        for(auto &x : groups[i]) {
            cout << x << " ";
        }
        cout << nl;
    }

    for(auto &x : players) {
        cout << x << " ";
    }
    cout << nl;

    for(; k <= 98; k++) {
        cout << cards[k] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

