class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        HashSet <Integer> hs = new HashSet<>();
        for(int num : nums){
            if(hs.contains(num)){
                ans.add(num);
            }
            else{
                hs.add(num);
            }
        }
        return ans;
        
    }
}