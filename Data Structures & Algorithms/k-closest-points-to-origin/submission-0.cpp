class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, greater<pair<float, vector<int>>>> min_pq;
            vector<vector<int>> result;
        for (vector<int>& pairs : points) {
            int x = pairs[0];
            int y = pairs[1];
            float eD = euclideanDistance(x, y);
            min_pq.push({eD, pairs});

        }
        while(k>0 && !min_pq.empty()){
           result.push_back(min_pq.top().second);
           min_pq.pop() ;
           k--;
        }
        return result;
    }
    float euclideanDistance(int x, int y) { return sqrt((x * x) + (y * y)); }
};
