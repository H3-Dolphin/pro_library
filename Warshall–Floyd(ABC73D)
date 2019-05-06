#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll INF = 1LL<<60;
int main(void){
    int n,m,r;
    ll d[210][210];
    cin >> n >> m >> r;
    vector<int> v;
    for(int i = 0;i < r;i++){
        int x;
        cin >> x;
        x--;
        v.push_back(x);
    }
    
    for(int i = 0;i < 210;i++){
        for(int j = 0;j < 210;j++) d[i][j] = INF;
        d[i][i] = 0;
    }
    
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    
    for(int k = 0;k < n;k++)for(int i = 0;i < n;i++)for(int j = 0;j < n;j++)
    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    
    ll ans = INF;
    sort(v.begin(),v.end());
    do{
        ll tmp = 0;
        for(int i = 0;i < v.size()-1;i++) tmp += d[v[i]][v[i+1]];
        ans = min(ans,tmp);
    }while(next_permutation(v.begin(),v.end()));
    
    cout << ans << endl;
    return 0;
}
