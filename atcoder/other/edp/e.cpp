#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;
    long long W; cin>>W;
    vector<long long >weight(N+1,0);
    vector<int> value(N+1,0);
    vector<long long> cost(N+1,0);
    rep(i,N) cin>>weight[i]>>value[i];
    
    return 0;
}