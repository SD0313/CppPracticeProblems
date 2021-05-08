#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Pair;
vector<int> ooo;
// If I do just vector<vector<Pair>> graph; without the 1e5, it becomes slow
vector<vector<Pair>> graph;
int n, m;
vector<int> ids(1e5);

void dfs(int v, int min_width, int id) {
    if (ids[v] != -1) {
        return;
    }
    ids[v] = id;
    for (auto p : graph[v]) {
        if (p.second < min_width) continue;
        dfs(p.first, min_width, id);
        
    }
}
bool works(int min_width) {
    fill(ids.begin(), ids.end(), -1);
    // visited.clear();
    // ids = {};
    int curr_id = 0;
    for (int i = 0; i < n; i++) {
        if (ids[i] != -1) continue;
        // cout << "id: " << curr_id << endl;    
        dfs(i, min_width, curr_id++);
    }
    // cout << "hi" << endl;

    int prev_id = -1;
    for (int p : ooo) {
        if (prev_id == -1) {
            prev_id = ids[p];
        }
        if (ids[p] != prev_id) {
            return false;
        }
        prev_id = ids[p];
    }
    return true;
}

int main()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    cin >> n >> m;
    // cout << n << " " << m << "\n";
    int max_width = -1;
    for (int i = 0; i < n; i++) {
        int n1;
        cin >> n1;
        n1--;
        if (n1 != i) {
            // Pair p(n1, i);
            ooo.push_back(n1);
        }
    }
    // cout << "size: " << ooo.size() << endl;
    if (ooo.size() == 0) {
        cout << -1 << "\n";
        return 0;
    }

    // vector<vector<Pair>> graph(m);
    for (int i = 0; i < m; i++) {
        vector<Pair> temp;
        graph.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        Pair edge(to-1, weight);
        max_width = max(weight, max_width);
        graph[from-1].push_back(edge);
        Pair edge_rev(from-1, weight);
        graph[to-1].push_back(edge_rev);
    }

    int lo, hi;
    lo = 0; hi = 1e9+1;
    for (--lo; lo < hi;) {
        // cout << lo << ", " << hi << endl;
        int mid = lo+(hi-lo+1)/2;
        if (works(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << "\n";
    return 0;
}