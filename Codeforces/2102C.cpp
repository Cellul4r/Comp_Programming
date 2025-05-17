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
void solve(){
    
    int n;
    cin>>n;

    int count = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = k; l <= n; l++) {
                    count++;
                    for(int x = i; x <= j; x++) {
                        for(int y = k; y <= l; y++) {
                            cnt[x][y]++;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cerr << cnt[i][j] << " ";
            cnt[i][j] = 0;
        }
        cerr << nl;
    }
    int mid = (n + 1) / 2;
    if(true) {
        for(int level = 1, now = 1; level < mid; level++) {
            for(int i = 0; i <= level; i++) {
                cerr << now << " " << mid - level << " " << i << nl;
                cnt[mid - i][mid - level]  = now++;
                if(mid - level != n - (mid - level) + 1) cnt[mid - i][n - (mid - level) + 1] = now++;
                if(mid - i != n - (mid - i) + 1) {
                    cnt[n - (mid - i) + 1][mid - level] = now++;
                    if(mid - level != n - (mid - level) + 1) cnt[n - (mid - level) + 1][n - (mid - i) + 1] = now++;
                }
                //if(i != n - i + 1) cnt[mid + level][n - i + 1] = now++; 
                //cnt[i][mid - level] = now++;
                //if(i != n - i + 1) cnt[n - i + 1][mid - level] = now++;
                //cnt[i][mid + level] = now++;
                //if(i != n - i + 1) cnt[n - i + 1][mid + level] = now++;
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

