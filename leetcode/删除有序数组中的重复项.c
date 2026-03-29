int removeDuplicates(int* nums, int numsSize) {
    int n = 1;

    if(numsSize == 0) return 0; //如果數組爲空， 直接返回0

    for(int i = 1; i < numsSize; i++){
        if(nums[n - 1] != nums[i]){ //如果當前元素與前一個元素不相同，則將當前元素放到新數組的末尾
            nums[n++] = nums[i];
        }
    }

    return n;
}