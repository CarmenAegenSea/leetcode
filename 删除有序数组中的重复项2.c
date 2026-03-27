int removeDuplicates(int* nums, int numsSize) {
    int n = 2;

    if(numsSize < 3) return numsSize;

    for(int i = 2; i < numsSize; i++){
        if(nums[n - 2] != nums[i]){
            nums[n++] = nums[i];
        }
    }

    return n;
}