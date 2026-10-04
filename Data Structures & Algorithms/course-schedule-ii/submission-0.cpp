class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ///i need to calculatge the indegrees
        vector<int> inDegrees(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int preReq = prerequisites[i][1];
            adjList[preReq].push_back(course);
        }
        queue<int> q;
        ///calculate indegrees
        for(vector<int> lists: adjList){
            for(int value: lists){
                inDegrees[value]++;
            }
        }
        for(int i=0;i<numCourses; i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }
        vector<int> visited;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int val: adjList[front]){
                inDegrees[val]--;
                if(inDegrees[val]==0){
                    q.push(val);
                }
            }
            visited.push_back(front);

        }
        if(visited.size()!=numCourses){
            return {};
        }
        return visited;
        
    }
};
