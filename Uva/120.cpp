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
const int N =35;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int a[N];
string s;
void solve(){
    
    while(getline(cin,s)) {
        stringstream ss(s);
        int n = 0;
        while((ss>>a[n])) {
            n++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << nl;
        for(int i = n-1; i >= 0; i--) {
            int idx = i;
            for(int j = i - 1; j >= 0; j--) {
                if(a[j] > a[idx]) {
                    idx = j;  
                }
            }

            if(idx != i) {
                // move this idx to the top
                if(idx != 0) {
                    ans.push_back(n-idx);
                    for(int j = 0; j <= idx / 2; j++) {
                        swap(a[j], a[idx-j]);
                    }
                }
                ans.push_back(n-i);
                for(int j = 0; j <= i / 2; j++) {
                    swap(a[j], a[i - j]);
                }
            }
        }
        ans.push_back(0);
        for(auto &x : ans) {
            cout << x << " ";
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

