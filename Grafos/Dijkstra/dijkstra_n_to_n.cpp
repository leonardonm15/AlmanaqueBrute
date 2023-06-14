const int MAX = 505;
const ll INF = 1e18 + 18;

vector<ii> adj[MAX];
ll dist[MAX][MAX];

void dk(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    for (int s = 0; s < n; s++) {
        priority_queue<ii, vector<ii>, greater<>> fila;
        dist[s][s] = 0;
        fila.emplace(dist[s][s], s);
        while (!fila.empty()) {
            auto [d, u] = fila.top();
            fila.pop();
            if (d != dist[s][u]) continue;
            for (auto [w, v]: adj[u]) {
                if (dist[s][v] > d + w) {
                    dist[s][v] = d + w;
                    fila.emplace(dist[s][v], v);
                }
            }
        }
    }
}
