class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        long long arr[26][26];
        // Initializing a Floyyd Warshall matrix
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                arr[i][j] = LLONG_MAX;
                if(i==j){
                    arr[i][j] = 0;
                }
            }
        }
        // adding the edges given
        for(int i=0;i<n;i++){
            int u = original[i] -'a';
            int v = changed[i] - 'a';
            arr[u][v] = min(arr[u][v],(long long)cost[i]);
        }
        // Floyyed warshall Algorithm
        for(int k =0;k<26;k++){
            for(int i =0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(arr[i][k] != LLONG_MAX && arr[k][j] != LLONG_MAX){
                        arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                    }
                }
            }
        }
        long long ans =0;
        for(int i=0;i<source.size();i++){
           int u = source[i] -'a';
           int v = target[i] -'a';

           if(u == v){
            continue;
           }
           if(arr[u][v] == LLONG_MAX){
            return -1;
           }
           else{
            ans += arr[u][v];
           }
        }
        return  ans;
    }
};
