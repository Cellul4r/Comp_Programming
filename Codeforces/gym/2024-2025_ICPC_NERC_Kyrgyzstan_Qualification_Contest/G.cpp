#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
typedef long long ll;
typedef pair<int,int> pi;
int n;
ll w;
map<int,pi> gb;
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>w>>n;
    set<pi> save;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        save.insert(make_pair(y,i));
        gb[i] = make_pair(x,y);
    }
    
    priority_queue<pi> pq;
    while(!save.empty() && (*save.begin()).first == 0) {
        int idx = (*save.begin()).second;
        pq.push(make_pair(gb[idx].first, (*save.begin()).second));
        save.erase(save.begin());
    }
    int mons = 0;
    ll now = 0;
    while(now < w && !pq.empty()) {
        int idx = pq.top().second; 
        int val = pq.top().first;
        pq.pop();
        now += val;
        ans.push_back(idx);
        while(!save.empty() && (*save.begin()).first <= now) {
            int idx = (*save.begin()).second;
            pq.push(make_pair(gb[idx].first, (*save.begin()).second));
            save.erase(save.begin());
        }
    }

    if(now < w) {
        cout << -1;
    } else {
        cout << ans.size() << '\n';
        for(auto &x : ans) {
            cout << x + 1 << " ";
        }
    }
    return 0;
}
