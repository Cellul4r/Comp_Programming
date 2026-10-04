/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    string s; cin>>s;
    // even even even even even -> 0
    // odd odd even -> even even even -> 1
    // odd even odd -> 
    // even odd even
    // odd even even even even even even odd -> 4
    // 1 00 11 0 -> 3
    // 1 00 1 -> 0000 -> 2
    // 1 11 10 00 0 -> 4 (5 subsegments reduce to 2 subsegment)
    // 111 10 00 000 -> 3
    // 1 00 11 0 -> 1 11 11 1
    // 1 00 11 0 1 00 11 0
    vector<int> odd;
    vector<int> save(n);
    vector<pair<int,int>> idx;
    int cur = (s[0] == '0' ? 0 : 1), cnt = 1;
    int start = 0;
    int now = 0;
    for(int i = 1; i < n; i++) {
        if(cur == s[i] - '0') {
            cnt++;
            continue;
        }
        if(cnt % 2 == 1) {
            odd.push_back(now);
            idx.push_back({start,i-1});
        }
        save[now] = cur;
        cur = s[i] - '0';
        cnt = 1;
        start = i;
        now++;
    }
    if(cnt > 0) {
        save[now] = cur;
        if(cnt % 2 == 1) {
            odd.push_back(now);
            idx.push_back({start,n-1});
        }
        now++;
    }
    assert(odd.size() % 2 == 0);
    ll ans = 0, mn = now;
    vector<ll> one(n), zero(n);
    one[0] = (s[0] == '1');
    zero[0] = (s[0] == '0');
    for(int i = 1; i < n; i++) {
        one[i] = (s[i] == '1') + one[i-1];
        zero[i] = (s[i] == '0') + zero[i-1];
    }
    auto f = [&](int l, int r, int type) {
        if(type == 0) {
            return zero[r] - (l > 0 ? zero[l-1] : 0);
        } else {
            return one[r] - (l > 0 ? one[l-1] : 0);
        }
    };
    int noww = now;
    for(int i = 0; i < (int)odd.size(); i += 2) {
        ll k = odd[i+1] - odd[i];
        ans += k;
        now = odd[i];
        int nnow = odd[i+1];
        int l = idx[i].first, r = idx[i+1].second;
        mn -= k - 1;
        //cerr << l << " " << r << " " << f(l,r,0);
        if(k == f(l,r,0) && k == f(l,r,1)) {
            // chagne to all 1s or 0s.
            if(now > 0) {
                save[nnow] = save[now-1];
                mn--;
            } else {
                save[nnow] = 2; // can be any type
            }
            mn--;
        }
        else if(k == f(l,r,0)) {
            // change to all 1s.
            save[nnow] = 1;
            if(now > 0 && save[now-1] >= 1) {
                mn--;
            }
            mn--;
        } else if(k == f(l,r,1)) {
            // change to all 0s.
            save[nnow] = 0;
            if(now > 0 && (save[now-1] == 0 || save[now-1] == 2)) {
                mn--;
            } 
            mn--;
        } else {
            // change to 1111..000 or 000..111..
            if(now > 0) {
                mn--;
                if(save[now-1] == 1) {
                    save[nnow] = 0;
                } else {
                    save[nnow] = 1;
                }
            } else {
                save[nnow] = 2;
            }
        }
        //cout << save[now] << " " << save[nnow] << nl;
        if(i == (int)odd.size() - 2 || odd[i+1] + 1 != odd[i+2]) {
            if(nnow+1 < noww) {
                if(save[nnow] == 2 || save[nnow] == save[nnow+1]) {
                    mn--;
                }
            }
        }
    }
    cout << ans << " " << mn << nl;
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

