class Solution {
public:
    vector<int> sumZero(int n) {
        int i=0;
        int j = n-1;
        vector<int> ans(n,0);
        int target = 1;

        while(i<j)
        {
            ans[i] = target;
            ans[j] = -target;
            target++;
            i++;
            j--;

        }

        return ans;
        
    }
};