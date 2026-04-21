class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int numberOfFleets = 0;
        vector<float> speed_ordered(target,0.0);
        vector<int> mystack;
        for(int i=0; i<speed.size();i++){
            speed_ordered[position[i]] = (target - position[i]) / (float)speed[i]; 
           
        }
        for(float sp:speed_ordered){
            cout << sp << endl;
        }
        float max_time = 0;
        int fleet_size = 0;
        for(int j=target-1; j>=0; j--){
            if(speed_ordered[j]>max_time){
                max_time = speed_ordered[j];
                fleet_size++;
            }

        }
        return fleet_size;
        

    }
};
