int maxProfit(int* prices, int pricesSize){

    bool can_buy = true;
    unsigned int max_profit = 0;
    int buy_idx = 0;
    int i = 0;

    while (i < pricesSize - 1) {
        if ((can_buy) && (prices[i] < prices[i+1])) {
            can_buy = false;
            buy_idx = i;
            i++;
            continue;
        }
        
        if ((!can_buy) && (prices[i] > prices[i+1])){
            can_buy = true;
            max_profit += prices[i] - prices[buy_idx];
        }
        i++;
    }
    
    if (!can_buy) {
        max_profit += prices[i] - prices[buy_idx];
    }
    
    return max_profit;
}
