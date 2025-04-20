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

void test() {

    for(int i = 1; i <= 1000; i++) {
        bool valid = false;
        int x = 0;
        for(int j = 0; j <= i; j++) {
            x ^= j;
        }
        for(int j = 0; j <= i; j++) {
            int y = x ^ j; 
            if(y > i) {
                valid = true;
                break;
            }
        }
        if(valid) {
            cerr << i << nl;
        }
    }
}
void solve(){
    
    int n;
    cin>>n;
    cout << (n % 2 == 0 ? "YES" : "NO");
    //test();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

