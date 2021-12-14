
// Longest Path Problem
// Frincy Lyn C. Urdas

#include <bits/stdc++.h>
using namespace std;

// Function to traverse the DAG to find longest path
void dfs(int node, vector<int> adj[], int dp[], bool vstd[])
{
    // Mark as visited
    vstd[node] = true;

    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++) {

        // If not visited
        if (!vstd[adj[node][i]])
            dfs(adj[node][i], adj, dp, vstd);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
    // Dp array
    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    // Checking of the visited array
    bool vstd[n + 1];
    memset(vstd, false, sizeof vstd);

    // Call DFS for every unvisited nodes
    for (int i = 1; i <= n; i++) {
        if (!vstd[i])
            dfs(i, adj, dp, vstd);
    }

    int ans = 0;

    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Main Code
int main()
{
    int n = 5;
    vector<int> adj[n + 1];

    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 3);
    addEdge(adj, 5, 1);
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 3);

    //Print longest path value
    cout << "Longest Path: " << findLongestPath(adj, n) << "\n";

    return 0;
}
