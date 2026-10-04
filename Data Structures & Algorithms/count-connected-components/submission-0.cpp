class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int> visited;
        vector<vector<int>> adjList(n);
        for(vector<int>& values: edges){
            int first = values[0];
            int second = values[1];
            adjList[first].push_back(second);
            adjList[second].push_back(first);
        }
        int ans = 0;
        for(int i =0; i<n;i++){
            if(!visited.contains(i)){
               dfs(i,visited,-1,adjList);
               ans+=1;
            }
        }
       return ans; 
    }
    void dfs(int node, set<int>&visited, int parent, vector<vector<int>>& adjList){
        visited.insert(node);
        for(int& val: adjList[node]){
            if(val == parent){
                continue;
            }else if(!visited.contains(val)){
                dfs(val,visited, node, adjList);
            }
        }
    }
};
