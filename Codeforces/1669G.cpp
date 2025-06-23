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
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m));
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '*') {
                a[i][j] = 1;
            } else if(s[j] == 'o') {
                a[i][j] = 2;
            }
        }
    }
    for(int j = 0; j < m; j++) {
        a[n][j] = 2;
    }

    vector<vector<int>> answer(n+1,vector<int>(m));
    for(int j = 0; j < m; j++) {
        int stone = 0;;
        vector<pi> stones;
        for(int i = 0; i <= n; i++) {
            if(a[i][j] == 1) {
                stone++;
            } else if(a[i][j] == 2) {
                stones.push_back(make_pair(i,stone));
                stone = 0; 
            }
        }

        for(auto &[r,st] : stones) {
            answer[r][j] = 2; 
            for(int i = 1; i <= st; i++) {
                answer[r-i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        string now;
        for(int j = 0; j < m; j++) {
            if(answer[i][j] == 0) {
                now += '.';
            } else if(answer[i][j] == 1) {
                now += '*';
            } else {
                now += 'o';
            }
        }
        cout << now << nl;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

