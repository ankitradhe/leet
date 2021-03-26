char * convert(char * s, int numRows){

    int i, j, sum, gi, slen;
    char *ret = (char *)malloc(strlen(s)+1);
    int idx = 0;
    
    if (!numRows) {
        numRows = 1;
    }
    gi = 2*numRows - 2;
    
    slen = strlen(s);
    if (numRows >= slen) {
        return s;
    }
    ret = (char *)malloc(slen+1);
    
    
    for (i = 0; i < numRows; i ++) {
        for (j = i, sum = 2*i; j < slen;) {
            ret[idx++] = s[j];
            if (sum < gi) {
                sum = gi - sum;
            }
            
            if (numRows < 2) {
                j++;
            } else {
                j+=sum;
            }
        }
    }
    
    ret[idx] = '\0';
    return ret;
}
