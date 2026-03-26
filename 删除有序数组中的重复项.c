int removeDuplicates(int* nums, int numsSize) {
    int n = 1;

    if(numsSize == 0) return 0;

    for(int i = 1; i < numsSize; i++){
        if(nums[n - 1] != nums[i]){
            nums[n++] = nums[i];
        }
    }

    return n;
}