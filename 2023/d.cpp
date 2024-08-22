#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void bellroxo(int node, int N,vector<tuple<int, int, int>> edges, int *distances);

int INF = 1e9;

int main(void) {
    int N, M;
    cin >> N;
    cin >> M;

    vector<tuple<int, int, int>> arestas;
    
    for (int i = 0; i < M; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        arestas.push_back({a, b, c});
        arestas.push_back({b, a, c});
    }

    int distances[N+1];

    
    for (int i = 0; i < 2*M; i+=2) {
        vector<tuple<int, int, int>> arestas_copia;
        arestas_copia.assign(arestas.begin(), arestas.end());
        tuple<int, int, int> temp_edge0 = arestas[i];
        tuple<int, int, int> temp_edge1 = arestas[i+1];
        arestas_copia.erase(arestas_copia.begin() + i);
        arestas_copia.erase(arestas_copia.begin() + i+1);
        bellroxo(get<0>(temp_edge0), N, arestas_copia, distances);
        arestas_copia.clear();
        if (distances[get<1>(temp_edge0)] == INF) {
            cout << -1 << endl;
            continue;
        }
        cout << distances[get<1>(temp_edge0)] << endl;
    }


}

void bellroxo(int node, int N,vector<tuple<int, int, int>> edges, int *distances) {
    for (int i = 1; i <= N; i++) {
        distances[i] = INF;
    }
    distances[node] = 0;
    for (int i = 1; i <= N-1; i++) {
        for (auto edge: edges) {
            int a, b, w;
            tie(a, b, w) = edge;
            distances[b] = min(distances[b], distances[a]+w);
        }
    }
}