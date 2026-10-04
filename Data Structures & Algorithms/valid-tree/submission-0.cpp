class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //create an adjacency lsit
        vector<vector<int>> adjList(n);
        for(vector<int> nodes: edges){
            int node1 = nodes[0];
            int node2 = nodes[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        set<int> visited;
        bool ret = dfs(0,visited,adjList,-1);
         for(int c :visited){
                cout << c <<endl;
            }

        if(ret && n==visited.size()){
            for(int c :visited){
                cout << c <<endl;
            }
            return true;
        }

        return false;



    }
    bool dfs(int node, set<int>& visited, vector<vector<int>>&adjList, int parent){
        
        visited.insert(node);
        for(int val: adjList[node]){
            if(val==parent){
                continue;
            }else if(!visited.contains(val))
            {
                dfs(val,visited,adjList,node);
            }else{
                return false;
            }

        }
        
        return true;
    }
};
