class TimeMap {
private:
        unordered_map<string, vector<pair<string, int>>> myTimeMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myTimeMap[key].push_back({value, timestamp});
        
    }
    
    string get(string key, int timestamp) {
        //need to binary search int the array t
        //to find the target or anything 
        //
        //first check if the key exists
        if(!myTimeMap.contains(key)) return "";
        //if it exists i need the array to loop in
        const auto& arr= myTimeMap.at(key);

        int left = 0;
        int right = arr.size() -1;
        string value = "";
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid].second==timestamp){
                return arr[mid].first;
            }
            if(arr[mid].second>timestamp){
                right = mid-1;
            }else{
                //but store this value?
                value = arr[mid].first;
                left = mid+1;
            }
        }
        return value;
        
    }
};
