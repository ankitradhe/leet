char * longestCommonPrefix(char ** strs, int strsSize){

    int i = 0;
    int j=0;
    char c = 0;
    char *buf = NULL;
    
    if (!strsSize) {
        return "";
    }
    
    buf = (char *)calloc(201, sizeof(char));
    for (j = 0; j < 201; j++) {
        c = strs[0][j];
        if (c == '\0') {
            return buf;
        }
        
        for (i=0; i < strsSize; i++) {
            if (strs[i][j] == '\0') {
                return buf;
            }
            
            if (c != strs[i][j]) {
                return buf;
            }
        }
        buf[j] = c;
    }
    
    return buf;
}
