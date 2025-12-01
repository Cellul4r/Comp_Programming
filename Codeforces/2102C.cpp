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
const int N =501;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int cnt[N][N];
const int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
void solve(){
    
    int n;
    cin>>n;

    int mid = (n + 1) / 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cnt[i][j] = -1;
        }
    }

    int now = 0, r = mid, c = mid;

    int cur = 1;
    // step increase by 1 every 2 moves for spiral shape
    cnt[r][c] = now++;
    while(now <= n * n - 1) {
        for(int k = 0; k < 4; k++) {
            int step = cur;

            cur += k % 2;

            for(int i = 0; i < step; i++) {
                r += dr[k];
                c += dc[k];
                //cerr << r << " " << c << nl;
                if(r >= 1 && r <= n && c >= 1 && c <= n && cnt[r][c] == -1) {
                    cnt[r][c] = now++;    
                }
                if(now >= n * n) break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << nl;
    }

    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

