#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

// トポロジカルソート
// グラフの有向辺が全て左から右へ向かうように頂点を水平に並べる
vector<int> G[100000];
vector<int> out;
bool seen[100000];
int n;

// トポロジカルソート
void dfs(int v){
    // 未到達な点を訪れる
    seen[v] = true;
    // 繋がっているところで見れるところを再帰的に見ていく
   for (auto nv:G[v]) {
        if(!seen[nv]) dfs(nv);
    }

    // 訪れたところを格納する
    out.push_back(v);
}

int main() {
    int s,t,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) seen[i] = false;
    for (int i = 0; i < m; ++i) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    for (int i = 0; i < n; ++i) {
        if(!seen[i]) dfs(i);
    }

    for (int i = out.size()-1; i >= 0; --i) {
        cout << out[i] << endl;
    }

    return 0;
}
