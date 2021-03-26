long long unsigned int get_sum(long long unsigned int n)
{
    int res = 0;
    long long unsigned int sum = 0;

    while (n) {
        res = n%10;
        sum += res*res;
        n = n/10;
    }
    return sum;
}

bool isHappy(int n){
    long long unsigned int sum = n;
    bool ret = false;
    int count = 400;

    do {
        if (sum == 1) {
            ret = true;
            break;
        }
        sum = get_sum(sum);
    } while ((sum != n) && (count--));
    return ret;
}
