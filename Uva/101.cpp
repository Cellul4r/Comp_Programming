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
int n;
string s;
vector<int> now[25];
int level[25];
void popTop(int l, int x) {
    while(x != now[l].back()) {
        int val = now[l].back();
        now[val].push_back(val);
        level[val] = val;
        now[l].pop_back();
    }

}
void movePile(int from, int fromL, int toL) {
     
    vector<int> tmp;
    while(now[fromL].back() != from) {
        int val = now[fromL].back();
        tmp.push_back(val);
        now[fromL].pop_back();
    }
    now[fromL].pop_back();
    tmp.push_back(from);
    while(!tmp.empty()) {
        level[tmp.back()] = toL;
        now[toL].push_back(tmp.back());
        tmp.pop_back();
    }
}
void solve(){

    cin>>n;
    assert(n < 25);
    for(int i = 0; i < n; i++) {
        level[i] = i;
        now[i].push_back(i);
    }
    while(cin>>s) {
        if(s == "quit") break;
        int a,b;
        string k;
        cin>>a;
        cin>>k;
        cin>>b;
        int la = level[a], lb = level[b];
        if(a == b || la == lb) continue;
        if(s == "move") {
            if(k == "onto") {
                // pop all top a, pop all top b
                popTop(la, a);
                popTop(lb, b);
            } else {
                popTop(la, a);
            }
            now[lb].push_back(a);
            now[la].pop_back();
            level[a] = lb;
        } else {
            if(k == "onto") {
                popTop(lb, b);
            }
            movePile(a, la, lb); 
        }
    }

    for(int i = 0; i < n; i++) {
        cout << i << ":";
        for(int j = 0; j < (int)now[i].size(); j++) {
            cout << " " << now[i][j];
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

