struct edge {ll to,cost;};
typedef pair<ll,ll> P;
vector<vector<edge>> G(100010),GG(100010);
vector<ll> d(100010);

void dijkstra(ll s){
    // 小さい順に取り出す
    priority_queue<P,vector<P>,greater<P>> pq;
    fill(d.begin(),d.end(),INF);
    d[s] = 0;
    pq.push(P(0,s));
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                pq.push(P(d[e.to],e.to));
            }
        }
    }
}

for (int i = 0; i < m; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        GG[b].push_back({a,c});
}
