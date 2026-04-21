class Solution {
    private:
        int alphabets[26] = {0};
        int window_size = 0;
public:
    bool isPermutation(){
        int sum = 0;
        for(int j: alphabets){
            if(j!=0){
                return false;
            }
        }
        return true;


    }
    bool checkInclusion(string s1, string s2) {
        //whatver the smaller window is, you use the permutation if it
        window_size = s1.size();
        if(s2.size() < s1.size()) return 0;
       
        for(int i = 0; i< window_size;i++){
            alphabets[s2[i]-'a']++;
        }
        for(int i =0; i< window_size; i++){
                alphabets[s1[i]-'a']--;
            }
        if(isPermutation()){
                return true;
            }
        for(int j = window_size; j< s2.size();j++){

          
            alphabets[s2[j]-'a']++;
            alphabets[s2[j-window_size]-'a']--;
              if(isPermutation()){
                return true;
            }
        }
        //nowcreate the window 
        //but you also need to check for permutations right

        return false;
    }
};
