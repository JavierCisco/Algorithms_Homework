#include <graph.hpp> 
#include <sort.hpp> 

int find(int u, std::vector<int> &parent) {
    if (parent[u] == -1)
        return u;
    else
        return parent[u] = find(parent[u], parent);
}

std::vector<Edge> mst(Graph G) {
    std::vector<Edge> edges;
    std::vector<ArrayValue> array;
    int n = G.n;
    int cnt = 0; 
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G.e[u].size(); i += 1) {
            Edge tmp = Edge(G.e[u][i]);
            edges.push_back(tmp);
            array.push_back(ArrayValue(tmp.w, cnt));
            ++cnt;
        }
    }

    std::vector<int> parent(n, -1);
    sort(array, 0, array.size()-1);
    std::vector<Edge> tree;
    for (int j = 0; j < array.size(); ++j) {
        int i = array[j].value;
        int u = edges[i].u;
        int v = edges[i].v;
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu != pv) {
            parent[pu] = pv;
            tree.push_back(Edge(edges[i]));
        } 
    }
    return tree;
}

