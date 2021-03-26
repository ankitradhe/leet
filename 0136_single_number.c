int singleNumber(int* nums, int numsSize){
    
    int i = 1;
    int res = nums[0];
    
    if (!numsSize) {
        return 0;
    }

    for (; i < numsSize; i++) {
        res = res ^ nums[i];
    }
    
    return res;
}
