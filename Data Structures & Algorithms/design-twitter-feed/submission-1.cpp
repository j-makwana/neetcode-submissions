class Twitter {
private:
    int count;
    ///hashmap: number of followers
    unordered_map<int, set<int>> following;
    //hashmap : user, tweets
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() {
        this->count = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
       ///when youre posting a tweet
       /// add count and tweet id
       this->tweets[userId].push_back({count, tweetId});
       count++;
       
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
       ///you have the userId 
       priority_queue<tuple<int, int, int>, vector<tuple<int,int, int>>> max_heap;
       vector<int> people = {userId};
       //the user + everyone the follow
       for(int f: following[userId]){
        if(f != userId){
            people.push_back(f);
        }

       }
       for(int u: people){
        if(tweets[u].empty()){
            continue;
        }
        ///ptherwise last index 
        int idx = tweets[u].size()-1;
        max_heap.push({tweets[u][idx].first, u, idx});

       }

       int popped = 0;
       while(!max_heap.empty() && popped<10){
        //youre popping the first, and then storing the next
        //with the idx --;
        //first: count, second: userId, third: idx
        auto [c, userId, idx] = max_heap.top();
        max_heap.pop();
        result.push_back(tweets[userId][idx].second);
        idx--;
        //if idx >0 then do this
        if(idx >=0){
max_heap.push({tweets[userId][idx].first, userId, idx});
        }
        
        popped++;
        
       }
       return result;
    }
    
    void follow(int followerId, int followeeId) {
      this->following[followerId].insert(followeeId);  
    }
    
    void unfollow(int followerId, int followeeId) {
       this->following[followerId].erase(followeeId);
    }
};
