#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; 
    cin>>n;
    int ans=10000000;
    for(int i=0; i<=10; i++){
        int tmp=i*1000;
        if(tmp>=n){
        ans=min(ans,tmp-n);
        }
    }
    cout<<ans<<endl;
    return 0;
}