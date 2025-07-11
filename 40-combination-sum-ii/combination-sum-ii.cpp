class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> &curr, int idx, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target<0)
        return;

        for(int i = idx; i<candidates.size(); i++)
        {
            
                if(i>idx && candidates[i] == candidates[i-1]){
                    continue;
                }

                curr.push_back(candidates[i]); //Do
                solve(candidates, target-candidates[i], curr, i+1, ans); //Explore
                curr.pop_back(); //UNDO
            
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr;

        sort(candidates.begin(), candidates.end());
        solve(candidates,target, curr, 0, ans );
        return ans;


    }
};