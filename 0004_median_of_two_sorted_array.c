int find_max(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

int find_min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int low = 0;
    int high = nums1Size;
    int part1 = 0;
    int part2 = 0;
    int max1left = 0;
    int min1right = 0;
    int max2left = 0;
    int min2right = 0;
    
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    while (low <= high) {
        part1 = (low+high+1)/2;
        part2 = (nums1Size + nums2Size + 1)/2 - part1; 
        
        if (!part1) {
            max1left = INT_MIN;
        } else {
            max1left = nums1[part1 - 1];
        }
        
        if (part1 == nums1Size) {
            min1right = INT_MAX;
        } else {
            min1right = nums1[part1];
        }
        
        if (!part2) {
            max2left = INT_MIN;
        } else {
            max2left = nums2[part2 - 1];
        }
        
        if (part2 == nums2Size) {
            min2right = INT_MAX;
        } else {
            min2right = nums2[part2];
        }
        
        if ((max1left <= min2right) && (max2left <= min1right)) {
            if ((nums1Size+nums2Size)%2) {
                return find_max(max1left, max2left);
            } else {
                return (find_max(max1left, max2left) + find_min(min1right, min2right))/2.0;
            }
        }
        
        if (max2left > min1right) {
            low = part1 + 1;
        }
        
        if (max1left > min2right) {
            high = part1 - 1;
        }
    }
    return 0.0;
}
