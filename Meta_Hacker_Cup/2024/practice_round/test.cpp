#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// Function to compute the greatest common divisor (GCD)
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return abs(a);
}

// Function to count how many points lie on the same line defined by two points
int count_on_line(pair<ll, ll> p1, pair<ll, ll> p2, const vector<pair<ll, ll>>& ants) {
    int dx = p2.first - p1.first;
    int dy = p2.second - p1.second;

    // Handle the case where the two points are identical
    if (dx == 0 && dy == 0) {
        return count(ants.begin(), ants.end(), p1);
    }

    // Simplify the slope by dividing by GCD
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;

    int count = 0;
    for (const auto& ant : ants) {
        ll dx2 = ant.first - p1.first;
        ll dy2 = ant.second - p1.second;

        // Handle the case where the ant being compared is the same as p1
        if (dx2 == 0 && dy2 == 0) {
            count++;
            continue;
        }

        ll g2 = gcd(dx2, dy2);
        dx2 /= g2;
        dy2 /= g2;

        // Check if the slopes match
        if (dx == dx2 && dy == dy2) {
            count++;
        }
    }
    return count;
}
// Random sampling to find the approximate number of ants that need to move
int ants_to_move_randomized(const vector<pair<ll, ll>>& ants) {
    int n = ants.size();
    if (n <= 2) return 0;

    srand(time(NULL));  // Seed for randomness
    int max_on_line = 0;
    int trials = 200;  // Limit the number of random trials

    for (int t = 0; t < trials; ++t) {
        // Randomly select two ants to define a line
        int i = rand() % n;
        int j = (i + rand() % (n-1) + 1) % n;
        if (i == j) continue;

        // Count how many ants are on the same line
        int count = count_on_line(ants[i], ants[j], ants);
        max_on_line = max(max_on_line, count);
    }

    return n - max_on_line;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    int i=1;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<ll,ll>> coor(n);
        for(int i=0;i<n;++i) {
            cin>>coor[i].first>>coor[i].second;
        }
        cout << "Case #" << i << ": " << ants_to_move_randomized(coor) << endl;
        ++i;
    }
    return 0;
}
