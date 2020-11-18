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
int inf = 1<<30;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

// 木の直径を求める
// 1. 適当な点xから最も遠い点xをBFSで求める
// 2. xから最も遠い点yをBFSで求める
// 3. xとyの距離が木の直径

class Edge{
public:
    int t,w;
    Edge(){}
    Edge(int t,int w): t(t),w(w) {}
};

vector<Edge> G[100000];
int n,d[100000];

void bfs(int s){
    for (int i = 0; i < n; ++i) d[i] = inf;
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // 繋がっているところを見ていって、そこまでの重みの累計をdに入れる
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = G[u][i];
            if(d[e.t] == inf){
                d[e.t] = d[u] + e.w;
                q.push(e.t);
            }
        }
    }
}

int main() {
    int s,t,w;
    cin >> n;

    for (int i = 0; i < n-1; ++i) {
        cin >> s >> t >> w;
        G[s].emplace_back(Edge(t,w));
        G[t].emplace_back(Edge(s,w));
    }

    // まず0から最も遠い点farxを求める
    bfs(0);
    // 一番重みでかいところが遠い
    int farx = 0,tmp = 0;
    for (int i = 0; i < n; ++i) {
        if(d[i] == INF) continue;
        if(d[i] > tmp){
            tmp = d[i];
            farx = i;
        }
    }

    // xから最も遠い点yを求める
    bfs(farx);
    tmp = 0;
    for (int i = 0; i < n; ++i) {
        if(d[i] == INF) continue;
        if(d[i] > tmp){
            // 一番遠い点の重みが大きいから，これがfarxとfary間の重み，つまり木の直径
            tmp = d[i];
        }
    }

    cout << tmp << endl;
    return 0;
}
