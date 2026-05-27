class Solution {
    public int removeDuplicates(int[] nums) {
        int n = 1;
        if (nums.length == 0) return 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[n - 1] != nums[i]) {
                nums[n++] = nums[i];
            }
        }
        return n;
    }
}
