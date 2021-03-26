void moveZeroes(int* nums, int numsSize){

    int count = 0;
    int i = 0;

    for (; i < numsSize; i++) {
        if (!nums[i]) {
            count++;
            continue;
        }
        
        nums[i-count] = nums[i];
    }
    
    for (i = (numsSize - count); i < numsSize; i++) {
        nums[i] = 0;
    }
}
