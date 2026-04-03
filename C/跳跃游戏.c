bool canJump(int* nums, int numsSize) {
    int maxX = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (i > maxX) {
            return false;
        }
        if (i + nums[i] > maxX) {
            maxX = i + nums[i];
        }
        if (maxX >= numsSize - 1) {
            return true;
        }
    }
    return true;
}