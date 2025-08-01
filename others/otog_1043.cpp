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
    
    string s;
    map<string, int> cnt;
    cin>>s;
    stack<pair<string,int>> st;
    int i = 0, n = s.size();
    string now = "";
    while(i < n) {
        //cerr << i << nl;
        if(s[i] == '/') {
            if(now != "") {
                st.push(make_pair(now,cnt[now]));
                cnt[now]++;
                //cerr << cnt[now] << " " << now << nl;
                now = "";
            }
        } else if(s[i] == '.' && now == "") {
            string k = "";
            while(i < n && s[i] != '/') {
                k += s[i++];
            }
            if(k == "..") {
                if(!st.empty()) st.pop();
            } else if(k == ".") {

            } else {
                st.push(make_pair(k,cnt[k]));
                cnt[k]++;
            }
        } else {
            now += s[i];
        }
        i++;
    }
    for(auto &x : cnt) {
        cerr << x.second << nl;
    }
    if(now != "") {
        st.push(make_pair(now, cnt[now]));
        cnt[now]++;
    }
    vector<pair<string,int>> check;
    while(!st.empty()) {
        check.push_back(st.top());
        st.pop();
    }
    reverse(all(check));
    string ans = "/";
    for(auto &x : check) {
        //cout << x << nl;
        if(cnt[x.first] == 1) {
            ans += x.first;
        } else {
            ans += x.first + to_string(x.second);
        }
        ans += "/";
    }
    //ans.pop_back();
    if((int)check.size() != 0) ans.pop_back();
    cout << ans;
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

