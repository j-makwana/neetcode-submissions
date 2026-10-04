class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> check_tree(numCourses);
        vector<int> inDegree(numCourses,0);
        queue<int> q;
        for(vector<int>& val: prerequisites){
            int course = val[0];
            int preReq = val[1];
            check_tree[preReq].push_back(course);

        }
        for(int i =0;i<numCourses;i++){
            for(int&val: check_tree[i]){
                inDegree[val]++;

            }
        }
        for(int j =0;j<numCourses;j++){
            if(inDegree[j]==0){
               q.push(j); 
            }
            
        }
        int visited = 0;
        while(!q.empty()){
            ///
            int front = q.front();
            q.pop();
            ///for all neighbors of front, reduce their indegrees
            for(int val: check_tree[front]){
                inDegree[val]--;

                if(inDegree[val]==0){
                    q.push(val);
                }
            }
            visited++;

        }
        if(visited!=numCourses){
            return false;
        }


       


        return true;

        
    }

  
};
