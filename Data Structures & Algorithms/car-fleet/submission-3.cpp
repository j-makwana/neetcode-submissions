class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int numberOfFleets = 0;
        vector<float> speed_ordered(target,0.0);
        vector<int> mystack;
        vector<pair<int, float>> cars;

        for(int i=0; i<speed.size();i++){
            float time = (target - position[i]) / (float)speed[i]; 
            cars.push_back({position[i], time});
           
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });
   
        int fleet_size = 0;
        float max_time = 0;
        for(int i=0; i< cars.size();i++){
            if(cars[i].second>0 && cars[i].second>max_time){
                fleet_size++;
                max_time = cars[i].second;
            }
        }
        return fleet_size;

        

    }
};
