class Solution {
public:

// SOLUTIONS **************************************************
// Uncomment any solution comment block (one at a time)

/*
// Solution 1
// Optimal solution : Using Dijkstra's allgorithm
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)

*/
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Adjacency list
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }


        // ans will be in dist[end]
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto x : adj[curr]) {
                int node = x.first;
                double prob = x.second;
                double newProb = dist[curr] * prob;
                
                if (newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }
        
        return dist[end];
    }

/*
// Solution 2
// Using Bellman-Ford Algorithm
// Time Complexity  : O(V * E)
// Space Complexity : O(E)

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<double> maxProb(n, 0);
    maxProb[start] = 1.0;
    int edgeLen = edges.size();

    for (int i = 0; i < n - 1; i++) {
        bool hasUpdate = false;
        for (int j = 0; j < edgeLen; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            double pathProb = succProb[j];
            if (maxProb[u] * pathProb > maxProb[v]) {
                maxProb[v] = maxProb[u] * pathProb;
                hasUpdate = true;
            }
            if (maxProb[v] * pathProb > maxProb[u]) {
                maxProb[u] = maxProb[v] * pathProb;
                hasUpdate = true;
            }
        }
        if (!hasUpdate) {
            break;
        }
    }

    return maxProb[end];
}
*/

};