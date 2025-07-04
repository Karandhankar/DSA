class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>> arr; //(value, index);

        for(int i=0; i<n; i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        for(int i=0; i<n-1; i++)
        {
            int x = target - arr[i].first;
            int start = i+1;
            int end = n-1;

            while(start <= end)
            {
                int mid = start + (end-start)/2;
                if(arr[mid].first == x)
                {
                    return{arr[i].second, arr[mid].second};
                }

                else if(arr[mid].first < x)
                {
                    start = mid + 1;
                }

                else{
                    end = mid-1;
                }

            }


        }

        return {};
    }
};