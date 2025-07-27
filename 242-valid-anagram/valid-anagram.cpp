class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        //count the frequency of character in string s
        for(auto ch : s){
            mp[ch]++;
        }

        //Decrease the frequency of character in string t
        for(auto ch : t){
            mp[ch]--;
        }

        //check if any char freq is non- zero
        for(auto ch : mp){
            if(ch.second != 0){
                return false;
            }
        }

        return true;

        
    }
};