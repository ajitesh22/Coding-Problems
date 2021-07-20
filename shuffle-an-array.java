//https://leetcode.com/problems/shuffle-an-array/
class Solution {
    
    private List<Integer> originalArray;
    private List<Integer> shuffledArray;
    int[] nums ;
    public Solution(int[] nums) {
        this.originalArray = new ArrayList<>();
        this.nums = new int[nums.length];
        for(int num : nums){
            originalArray.add(num);
        }
        this.shuffledArray = new ArrayList<>(originalArray);
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        resetShuffledToOriginalArray(originalArray);
        return this.nums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        Collections.shuffle(shuffledArray);
        resetShuffledToOriginalArray(shuffledArray);
        return this.nums;
    }
    
    private void resetShuffledToOriginalArray(List<Integer> list){
        
        for(int i=0;i<list.size();i++){
            nums[i] = list.get(i);
        }
    }
    
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
