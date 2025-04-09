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

void test(int n) {
    vector<int> a(n);
    iota(all(a), 1);
    do {
        bool flag = true;
        for(int i = 1; i < n; i++) {
            if(max(a[i-1],a[i]) % (i+1) != i) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(int i = 0; i < n; i++) cerr << a[i] << " ";
            cerr << nl;
        }
    }while(next_permutation(all(a)));
}
void solve(){
    
    int n;
    cin>>n;
    if(n % 2 == 0) {
        cout << -1 << nl;
        return;
    }
    //test(n);
    cout << n << " ";
    for(int i = 1; i < n; i++) cout << i << " ";
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

