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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int a[N][N];

bool isPrime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}
void solve(){
    
    int n,m;
    cin>>n>>m;
    
    if(!isPrime(m)) {
        for(int i = 0, now = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = now++; 
            }
        }
    } else if(!isPrime(n)) {
        for(int j = 0, now = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                a[i][j] = now++;
            }
        }
    } else {
        int now = 1;
        for(int i = 0; i < n; i += 2) {
            for(int j = 0; j < m; j++) {
                a[i][j] = now++;
            }
        }

        for(int i = 1; i < n; i += 2) {
            for(int  j = 0; j < m; j++) {
                a[i][j] = now++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
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

