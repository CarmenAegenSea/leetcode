int removeDuplicates(int* nums, int numsSize) {
    int n = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[n] != nums[i]){
            nums[n++] = nums[i++];
        }
    }

    return n;
}