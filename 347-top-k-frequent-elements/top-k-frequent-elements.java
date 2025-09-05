class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int num : nums)
        {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a,b) -> 
        a.getValue() - b.getValue());

        for(Map.Entry<Integer, Integer> entry: mp.entrySet()){
            pq.offer(entry);
            if(pq.size() > k)
            {
                pq.poll();
            }
        }

        int[] result = new int[k];
        for(int i= k-1; i>=0; i--)
        {
            result[i] = pq.poll().getKey();
        }
        return result;
        
    }
}