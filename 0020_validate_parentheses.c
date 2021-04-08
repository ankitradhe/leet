char stack [10004] = {0};
int idx = -1;

void push(char c) {
    if (idx < 10004) {
        stack[++idx] = c;
    }
}

char pop() {
    if (idx >= 0) {
        return stack[idx--];
    }
    return '\0';
}

bool isValid(char * s) {
    int i = 0;
    char c = '\0';
    bool ret = true;

    for (; s[i]; i++) {
        switch (s[i]) {
            case '(':
            case '{':
            case '[':
                push(s[i]);
                break;
            case ')':
                c = pop();
                if (c != '(') {
                    ret = false;
                    goto EXIT;
                }
                break;
            case '}':
                c = pop();
                if (c != '{') {
                    ret = false;
                    goto EXIT;
                }
                break;
            case ']':
                c = pop();
                if (c != '[') {
                    ret = false;
                    goto EXIT;
                }
                break;
            default:
                ret = false;
                goto EXIT;
        }
    }
    
    if (idx != -1) {
        ret = false;
    }

EXIT:
    return ret;
}
