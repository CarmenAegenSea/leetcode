int jump(int* nums, int numsSize) {
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int reach = i + nums[i];
        if (reach > curFarthest) { curFarthest = reach; }
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}