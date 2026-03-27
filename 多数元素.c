int majorityElement(int* nums, int numsSize) {
    int x = nums[0];
    int count = 1;

    for(int i = 1; i < numsSize; i++){
        if(nums[i] == x){
            count++;
        }else{
            count--;
            if(count == 0){
                x = nums[i];
                count = 1;
            }
        }
    }
    return x;
}