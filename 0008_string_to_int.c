int myAtoi(char * str){
    double ret = 0;
    int idx = 0;
    int sign = 1;
    bool no_space = false;
    
    while(str[idx]) {
        switch (str[idx]) {
            case '-':
                if ((!ret) && (!no_space)) {
                    sign = -1;
                    no_space = true;
                } else {
                    return (int)sign*ret;
                }
                break;
            case '+':
                if ((!ret) && (!no_space)) {
                    no_space = true;
                } else {
                    return (int)sign*ret;
                }
                break;
            case ' ':
                if ((ret) || (no_space)) {
                    return (int)sign*ret;
                }
                break;
            default:
                if ((str[idx] <= '9') && (str[idx] >= '0')) {
                    no_space = true;
                    ret = ret * 10 + str[idx] - '0';
                    if (sign*ret > INT_MAX) {
                        return INT_MAX;
                    } else if (sign*ret < INT_MIN) {
                        return INT_MIN;
                    }
                } else {
                    return (int)sign*ret;
                }
        }
        idx++;
    }
    return (int)sign*ret;
}
