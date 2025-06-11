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
   string s;
   cin>>n>>s;
   vector<int> packman; 
   deque<int> food;
   for(int i = 0; i < n; i++) {
       if(s[i] == 'P') {
           packman.push_back(i);
       } else if(s[i] == '*'){
           food.push_back(i);
       }
   }

   auto f = [&](int times, deque<int> food) {
        for(auto &x : packman) {
            vector<int> eats;
            while(!food.empty() && food.front() < x) {
                eats.push_back(food.front());
                food.pop_front();
            }
            
            if(eats.empty()) {
                // eat right! 
                while(!food.empty() && food.front() - x <= times) food.pop_front(); 
            } else {
                if(x - eats[0] > times) {
                    return false;
                }

                // should we go left and then right
                int leftTime = x - eats[0];
                int rightTime = times - 2 * leftTime;
                int right = -1; 
                while(right + 1 < (int)food.size() && food[right+1] - x <= rightTime) right++; 
                // should we go right and then left
                int left = -1;
                rightTime = times - leftTime;
                while(left + 1 < (int)food.size() && (food[left+1] - x) * 2 <= rightTime) left++;

                for(int i = 0; i < max(left,right) + 1; i++) {
                    food.pop_front();
                }
            }
        }

        return food.empty();
   };
   int l = 0, r = 2 * n;
   while(l < r) {
       int mid = l + (r - l) / 2;
       if(f(mid, food)) {
           r = mid;
       } else {
           l = mid + 1;
       }
   }
   cout << l;
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

