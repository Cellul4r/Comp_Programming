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
int n,m,k;
void solve(){

    while(true) {
        cin>>n>>m>>k;
        if(n == 0) break;
        string board; cin>>board;
        vector<string> a(k);
        for(auto &x : a) cin>>x;
        vector<int> now(n,0);
        int play = 0;
        bool found = false;
        for(int i = 0; i < k; i++) {
            now[play]++;
            while(now[play] < (int)board.size() && board[now[play]-1] != a[i][0]) {
                now[play]++;
            }
            if(a[i].size() == 2) {
                now[play]++;
                while(now[play] < (int)board.size() && board[now[play]-1] != a[i][1]) {
                    now[play]++;
                }
            }
            if(now[play] >= (int)board.size()) {
                found = true;
                cout << "Player " << play + 1 << " won after " << i + 1 << " cards.";
                break;
            }
            //cout << play << " " << now[play] << nl;
            play = (play + 1) % n;
        }
        if(!found) cout << "No player won after " << k << " cards.";
        cout << nl;
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

