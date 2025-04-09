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
        deque<int> b;
        bool ok = true;
        for(int i = 0; i < n; i++) b.push_back(a[i]);
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int i = 0; i < n; i++) {
                if(i + 1 == b[i]) flag = true;
            }
            if(!flag) ok = false;
            int u = b.back();
            b.pop_back();
            b.push_front(u);
        }
        if(ok) {
            for(int i = 0; i < n; i++) {
                cerr << a[i] << " ";
            }
            cerr << nl;
        }
    } while(next_permutation(all(a)));
}
void solve(){
    
    int n;
    cin>>n;
    //test(n);
    if(!(n & 1)) {
        cout << -1 << nl;
        return;
    }
    for(int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for(int i = 2; i <= n; i += 2) {
        cout << i << " ";
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

