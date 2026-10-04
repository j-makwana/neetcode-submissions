class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
       vector<int> parent(n+1);
       vector<int> rank(n+1, 1);
       for(int i =0; i<(n+1);i++){
        parent[i]=i;
       }
       for(vector<int>& val: edges){
            int x = val[0];
            int y = val[1];
            if(!my_union(x,y, rank, parent)){
                return {x,y};
            }

       }
     
    }
    int find(int val, vector<int> &parent){
        if(parent[val]!= val){
            parent[val] = find(parent[val], parent);
        }
        return parent[val];
    }
    bool my_union(int x, int y, vector<int>& rank, vector<int>& parent){
        int root_x = find(x, parent);
        int root_y = find(y,parent);
        if(root_x == root_y){
            return false;
        }
        if(rank[root_x]<rank[root_y]){
            parent[root_x] = root_y;
        }else if(rank[root_x]> rank[root_y]){
            parent[root_y] = root_x;
        }else{
            parent[root_y] = root_x;
            rank[root_x]++;
        }
        return true;
    }

};
