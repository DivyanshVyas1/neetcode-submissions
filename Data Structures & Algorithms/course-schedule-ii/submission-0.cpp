class Solution {
public:
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    
    // Step 1: Graph + indegree banao
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    
    for (auto& pre : prerequisites) {
        int course = pre[0];
        int prereq = pre[1];
        adj[prereq].push_back(course);
        indegree[course]++;
    }
    
    // Step 2: Queue mein daalo jinki indegree == 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i]==0) q.push(i);
    }
    
    // Step 3: BFS
    vector<int> result;
    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor]==0) q.push(neighbor);  // kab queue mein daalna hai?
        }
    }
    
    // Cycle check
    if (result.size() == n) return result;
    return {};
}
};
