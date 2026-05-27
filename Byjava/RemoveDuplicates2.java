class Solution {
    public int removeDuplicates(int[] nums) {
        int n = 2;
        if (nums.length < 3) return nums.length;
        for (int i = 2; i < nums.length; i++) {
            if (nums[n - 2] != nums[i]) {
                nums[n++] = nums[i];
            }
        }
        return n;
    }
}
