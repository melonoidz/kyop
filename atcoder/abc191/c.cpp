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
    int H, W;
    cin >> H >> W;
    vc<string> S;
    rep(i, H) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W - 1; j++) {
            int cnt = 0;
            if (S[i][j] == '#') cnt++;
            if (S[i + 1][j] == '#') cnt++;
            if (S[i + 1][j + 1] == '#') cnt++;
            if (S[i][j + 1] == '#') cnt++;
            if (cnt == 3 || cnt == 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}