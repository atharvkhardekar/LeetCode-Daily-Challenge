// LeetCode Problem No. 3203
// Daily Challenge - 24/12/2024

class Solution {
    int diameter(unordered_map<int, vector<int>>& graph, int totalNodes) {
        vector<bool> visited(totalNodes, false);
        queue<int> nodeQueue;
        nodeQueue.push(0);
        visited[0] = true;
        int farthestNode;
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                farthestNode = nodeQueue.front();
                nodeQueue.pop();
                visited[farthestNode] = true;
                for (int neighbor : graph[farthestNode]) {
                    if (!visited[neighbor])
                        nodeQueue.push(neighbor);
                }
            }
        }
        
        nodeQueue.push(farthestNode);
        int hopCount = 0;
        vector<int> nodeVisited(totalNodes, false);
        nodeVisited[farthestNode] = true;
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();
                nodeVisited[currentNode] = true;
                for (int neighbor : graph[currentNode]) {
                    if (!nodeVisited[neighbor])
                        nodeQueue.push(neighbor);
                }
            }
            hopCount += 1;
        }
        return hopCount - 1;
    }

    int findDiameter(vector<vector<int>>& edgeList) {
        if (edgeList.size() == 0)
            return 0;
        unordered_map<int, vector<int>> graph;
        unordered_set<int> nodes;
        for (auto& edge : edgeList) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        return diameter(graph, nodes.size());
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDiameter(edges1);
        int dia2 = findDiameter(edges2);

        int radius1 = (dia1 + 1) / 2;
        int radius2 = (dia2 + 1) / 2;
        int totalDiameter = 1 + radius1 + radius2;
        return max(totalDiameter, max(dia1, dia2));
    }
};
