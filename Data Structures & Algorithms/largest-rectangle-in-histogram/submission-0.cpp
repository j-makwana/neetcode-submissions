class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()){
            return 0;
        }
        int max_area = heights[0];
        vector<pair<int, int>> area_stack;
        area_stack.push_back({0,heights[0]});

        for(int i =1; i< heights.size(); i++){
            int prev_height = area_stack.back().second;
            int prev_index = area_stack.back().first;
            int index_start = i;
            while(!area_stack.empty() && prev_height> heights[i]){
                area_stack.pop_back();
                //everytime theres a pop calcualte max area
                max_area = max(max_area, (i - prev_index)*prev_height);
                index_start = prev_index;
                prev_height = area_stack.back().second;
                prev_index = area_stack.back().first;
                }
            area_stack.push_back({index_start, heights[i]});
            
        }
        for(auto& n: area_stack){
            cout << n.first << n.second <<endl;
            int height = n.second;
            int start_index = n.first;
            max_area = max(max_area,(int)(heights.size()-start_index)*height);
        }
        return max_area;
    }
};
