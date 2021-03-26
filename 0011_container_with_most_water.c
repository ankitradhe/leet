int minof(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int maxof(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maxArea(int* height, int heightSize){
    int max  = 0;
    int i = 0;
    int j = heightSize - 1;
    int area = 0;
    
    while (i < j) {
        area = (j - i)*minof(height[i], height[j]);
        max = maxof(max, area);
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }

    return max;
}
