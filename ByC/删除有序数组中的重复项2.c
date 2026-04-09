int removeDuplicates(int* nums, int numsSize) {
    int n = 2;

    if(numsSize < 3) return numsSize; //如果數組長度小於3，則直接返回數組長度

    for(int i = 2; i < numsSize; i++){
        if(nums[n - 2] != nums[i]){ // 如果當前元素與前兩個元素不相同，則將當前元素放到新數組的末尾
            nums[n++] = nums[i];
        }
    }

    return n;
}