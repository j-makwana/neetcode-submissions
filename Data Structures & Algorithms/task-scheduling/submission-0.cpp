class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> counts(26,0);
       for(char c: tasks){
        counts[c-'A']++;
       }
       priority_queue<pair<int, char>> pq;
       for(int i = 0; i< 26;i++){
        if(counts[i]>0){
            pq.push({counts[i], 'A'+i});
            cout << char('A' + i) << " "<< counts[i] << endl;
        }
       }
       int result = 0;
       while(!pq.empty()){
        vector<int> temp(26,0);
        int pop = 0;
        while(!pq.empty()&& pop < (n+1)){
            char c = pq.top().second; 
            int freq = pq.top().first;
            temp[c-'A'] = freq;
            pq.pop();
            pop++ ;
        }
        for(int i= 0; i<26;i++ ){
            temp[i]--;
            if(temp[i]>0){
                pq.push({ temp[i], 'A'+i});

            }
        }
        if(pq.empty()){
            result+= pop;
        }else{
            result += n+1;
        }
        

       }

      

       return result;
    }
};
