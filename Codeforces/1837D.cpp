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
    string s;
    cin>>n>>s;

    vector<int> ans(n);
    
    stack<pair<int,char>> st,st2;

    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(make_pair(i,s[i]));
        } else if(!st.empty() && st.top().second == '('){
            if(!flag) {
                flag = true;
                cnt++;
            }
            ans[st.top().first] = cnt;
            ans[i] = cnt;
            st.pop();
        }
    }

    flag = false;
    for(int i = n - 1; i >= 0; i--) {
        if(ans[i] != 0) continue;
        if(s[i] == '(') {
            st.push(make_pair(i,s[i]));
        } else if(!st.empty() && st.top().second == '('){
            if(!flag) {
                flag = true;
                cnt++;
            }
            ans[st.top().first] = cnt;
            ans[i] = cnt;
            st.pop();
        }
    }

    for(auto &x : ans) {
        if(x == 0) {
            cout << -1 << nl;
            return;
        }
    }
    cout << cnt << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

