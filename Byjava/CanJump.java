class Solution {
    public boolean canJump(int[] nums) {
        int maxX = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxX) return false;
            if (i + nums[i] > maxX) maxX = i + nums[i];
            if (maxX >= nums.length - 1) return true;
        }
        return true;
    }
}
