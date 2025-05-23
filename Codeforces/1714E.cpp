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

void recur(int x, int& one, int& two) {
    if(x < 10) {
        recur(x + x % 10, one, two);
        return;
    }
    if(x % 10 == 8 && ((x / 10) % 10) % 2 == 0) {
        one++;
        return;
    }
    if(x % 10 == 8 && ((x / 10) % 10) % 2 == 1) {
        two++;
        return;
    }
    recur(x + x % 10, one, two);
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    
    map<int,int> cnt;
    int cntFive = 0, one =  0, two = 0;
    for(auto &x : a) {
        if(x == 0) {
            if(cnt[0] == 0) cntFive++;
            cnt[0]++;
        } else if(x % 10 == 5 || x % 10 == 0) {
            if(x % 10 == 0) x -= 5; 
            if(cnt[x] == 0) cntFive++;
            cnt[x]++;
        } else {
            recur(x, one, two);
        }
    }
    //cerr << cntFive << " " << one << " " << two << nl;
    if(cntFive > 1 || (cntFive == 1 && (one || two))) {
        cout << "NO" << nl;
        return;
    }
    if(one && two) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

