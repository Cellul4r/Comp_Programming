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

void test(int n) {
    
    for(int a = 0; a <= n; a++) {
        for(int b = 0; b <= n; b++) {
            vector<int> p(n);
            iota(all(p), 1);
            do {
                int aa = 0, bb = 0;
                for(int i = 1; i < n - 1; i++) {
                    if(p[i-1] < p[i] && p[i] > p[i+1]) {
                        aa++;
                    }
                    if(p[i-1] > p[i] && p[i] < p[i+1]) {
                        bb++;
                    }
                }
                if(a == aa && b == bb) {
                    cerr << a << " " << b << nl;
                    for(auto &x : p) {
                        cerr << x << " ";
                    }
                    cerr << nl;
                    break;
                }
            }while(next_permutation(all(p)));
        }
    }
}
void solve(){
    
    int n,a,b;
    cin>>n;
    //test(n);
    cin>>a>>b;
    if(a + b > n - 2) {
        cout << -1 << nl;
        return;
    }
    
    if(a == 0 && b == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << nl;
        return;
    }

    if(b < a - 1 || b > a + 1) {
        cout << -1 << nl;
        return;
    }

    vector<int> aa(n);
    int l = 1, r = n;
    if(a >= b) {
        for(int i = 1, c = 0; i < n - 1 && c < a; i += 2, c++) { 
            aa[i] = l++;
            aa[i+1] = r--;
            swap(aa[i],aa[i+1]);
        }
        for(int i = 0; i < n; i++) {
            if(aa[i] == 0) aa[i] = l++;
        }
    } else if(a < b) {
        // put min first then max
        iota(all(aa), 1);
        for(int i = 0, c = 0; i < n - 1 && c < b; i += 2, c++) {
            swap(aa[i], aa[i+1]);
        }
    }
    for(auto &x : aa) {
        cout << x << " ";
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

