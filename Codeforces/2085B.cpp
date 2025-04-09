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

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<pi> ans;
    while((int)a.size() != 1) {
        bool zero = false;
        vector<int> b;
        /*for(int i = 0; i < (int)a.size(); i++) {
            cerr << a[i] << " ";
        }
        cerr << nl;*/
        for(int i = 0; i < (int)a.size(); i++) {
            //cerr << i << nl;
            if(a[i] == 0 && !zero) {
                zero = true;
                if(i == (int)a.size() - 1) {
                    b.pop_back();
                    ans.push_back(make_pair(i - 1, i));
                } else {
                    ans.push_back(make_pair(i, i+1));
                }
                b.push_back(1);
                i++;
            } else {
                b.push_back(a[i]);
            }
        }
        if(!zero) {
            ans.push_back(make_pair(0,(int)a.size() - 1));
            a = vector<int>{0};
            break;
        }
        a = b;
    }
    assert(a[0] == 0);
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << nl;
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

