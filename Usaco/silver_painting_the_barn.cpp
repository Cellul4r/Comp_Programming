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

int n,k;
int board[1002][1002];
void solve(){
    
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++,y1++,x2++,y2++;
        board[x1][y1]++;
        board[x1][y2]--;
        board[x2][y1]--;
        board[x2][y2]++;
    }

    int cnt = 0;
    for(int i = 1; i <= 1001; i++) {
        for(int j = 1; j <= 1001; j++) {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
            cnt += (board[i][j] == k);
        }
    }

    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    string s = "paintbarn";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    

    //cin>>t;
    while(t--)solve();

    return 0;
}

