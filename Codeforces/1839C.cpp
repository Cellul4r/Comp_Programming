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
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<array<int,2>> save;
    for(int i = 0; i < n;) {
        int j = i;
        int one = 0, zero = 0;
        while(j < n && a[j] == 1) {
            one++;
            j++;
        }
        while(j < n && a[j] == 0) {
            zero++;
            j++;
        }
        if(zero == 0) {
            cout << "NO" << nl;
            return;
        }
        save.push_back({zero,one});
        i = j;
    }
    reverse(all(save));
    // if some block has #zero = 0 -> NO
    cout << "YES" << nl;
    for(auto &x : save) {
        int zero = x[0], one = x[1];
        for(int i = 0; i < one + zero - 1; i++) {
            cout << 0 << " ";
        }
        cout << one << " ";
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

