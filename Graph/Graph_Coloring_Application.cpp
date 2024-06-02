class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Create an adjacency list to represent the graph
        vector<int> adj[n];
        for(int i = 0; i < paths.size(); i++) {
            // Adjust the 1-indexed garden numbers to 0-indexed for internal processing
            adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
            adj[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        // Vector to store the color of each garden, initialized to -1 (no color)
        vector<int> color(n, -1);

        // Iterate over each garden to assign a color
        for(int i = 0; i < n; i++) {
            // Boolean array to track which colors are used by adjacent gardens
            vector<bool> used(5, false);

            // Check the colors of adjacent gardens
            for(int neighbour : adj[i]) {
                if(color[neighbour] != -1) {
                    // Mark the color as used if the adjacent garden is colored
                    used[color[neighbour]] = true;
                }
            }

            // Find the first available color that is not used by adjacent gardens
            for(int available_color = 1; available_color < 5; available_color++) {
                if(!used[available_color]) {
                    // Assign the available color to the current garden
                    color[i] = available_color;
                    break;
                }
            }
        }

        // Return the final coloring of the gardens
        return color;
    }
};
