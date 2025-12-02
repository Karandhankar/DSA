class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorResult = 0;
        int n = nums.size();

        for(int i=0; i<=n; i++){
            xorResult ^= i;
        }

        for(int num : nums){
            xorResult ^= num;
        }

        return xorResult;
        
    }
};