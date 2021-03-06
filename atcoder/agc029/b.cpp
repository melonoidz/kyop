#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    multiset<int> a;
    rep(i, n) {
        int num;
        cin >> num;
        a.insert(num);
    }
    int ans = 0;
    vc<int> bek(45);
    bek[0] = 1;
    for (int i = 0; i < 40; i++) {
        bek[i + 1] = bek[i] * 2;
        // cout<<bek[i+1]<<endl;
    }
    while (!a.empty()) {
        auto nu = *a.rbegin();
        int tmp = 0;
        for (int j = 0; j < 29; j++) {
            if (bek[j] > nu) {
                tmp = j;
                break;
            }
        }
        int res = bek[tmp] - nu;
        a.erase(a.find(nu));
        auto fi = a.find(res);
        if (fi != a.end()) {
            a.erase(a.find(res));
            ans++;
        }
    }
    cout << ans << endl;
}