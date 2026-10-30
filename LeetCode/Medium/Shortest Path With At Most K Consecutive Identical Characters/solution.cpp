#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // 1. Build adjacency list: graph[u] -> vector of {neighbor_v, edge_weight}
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // 2. Distance table: dist[u][count] stores the minimum path weight to node u
        // with exactly 'count' consecutive identical characters ending at u.
        const int INF = 1e9; // Safe infinity to prevent overflow when adding weights
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // 3. Min-heap priority queue storing elements as: {current_weight, node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Base case: start at node 0 with a consecutive count of 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [curr_w, u, count] = pq.top();
            pq.pop();

            // Since it's a min-heap, the first time we pop node n - 1, it's guaranteed to be the shortest path
            if (u == n - 1) {
                return curr_w;
            }

            // Skip outdated states
            if (curr_w > dist[u][count]) {
                continue;
            }

            // Process neighbors
            for (const auto& [v, weight] : graph[u]) {
                int next_count = (labels[u] == labels[v]) ? (count + 1) : 1;

                // Skip invalid transitions that violate the max constraint k
                if (next_count > k) {
                    continue;
                }

                // Relaxation condition
                if (curr_w + weight < dist[v][next_count]) {
                    dist[v][next_count] = curr_w + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        return -1;
    }
};
