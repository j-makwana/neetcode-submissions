class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> visited;
        unordered_map<string, vector<string>> myMap;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()){
            return 0;
        }
        wordList.push_back(beginWord);
        queue<string> q;
        for(string word: wordList){

        
        for(int i =0; i< word.length(); i++){
            string left = word.substr(0,i);
            string right = word.substr(i+1);
            string masked = left + "*" + right;
            for(string item: wordList){
                string left_b = item.substr(0,i);
                string right_b = item.substr(i+1);
                string masked_b = left_b + "*" + right_b;
                if(masked == masked_b){
                myMap[masked].push_back(item);

                }
        }}}

        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            int q_size = q.size();
            for(int k =0 ;k < q_size;k++){
                string word = q.front();
                q.pop();
            if(word == endWord){
                ans ++;
                return ans;
            }
            if(!visited.contains(word)){
                visited.insert(word);
                for(int j = 0;j<word.size(); j++){
                    string left = word.substr(0,j);
                    string right = word.substr(j+1);
                    string masked = left + "*" + right;
                    for(string item: myMap[masked]){
                        q.push(item);
                    }
                }
        
                
            }

            }
            ans ++;
            
        }
        return 0;


        
        

        
    }


};
