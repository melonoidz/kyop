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
    int n, k, l;
    cin >> n >> k >> l;
    atcoder::dsu uf1(n + 1);
    atcoder::dsu uf2(n + 1);
    rep(i, k) {
        int p, q;
        cin >> p >> q;
        uf1.merge(p, q);
    }
    rep(i, l) {
        int r, s;
        cin >> r >> s;
        uf2.merge(r, s);
    }
    vc<int> cnt1(n + 1), cnt2(n + 1);
    int tmp = 0;
    for (auto g : uf1.groups()) {
        tmp++;
        for (auto u : g) {
            cnt1[u] = tmp;
        }
    }
    tmp = 0;
    for (auto g : uf2.groups()) {
        tmp++;
        for (auto u : g) {
            cnt2[u] = tmp;
        }
    }
    map<pair<int, int>, int> res;
    for (int i = 1; i <= n; i++) {
        pi p;
        p.first = cnt1[i];
        p.second = cnt2[i];
        res[p]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[pi(cnt1[i], cnt2[i])] << " ";
    }
    cout << endl;
}