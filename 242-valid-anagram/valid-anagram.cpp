class Solution {
public:
    bool isAnagram(string s, string t) {
        int count [26] = {0};

        for(char ch : s){
            count[ch - 'a']++;
        }

        //Decrement the frequency of characters
        for(char ch : t){
            count[ch - 'a']--;
        }

        //check if any character has non zero frequency
        for(int val : count){
            if(val != 0){
                return false;
            }
        }
        return true;
        
    }
};