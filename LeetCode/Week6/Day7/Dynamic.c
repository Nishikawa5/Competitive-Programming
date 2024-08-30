

// given an array of integers, return the maximum length of a positive subarray
int getMaxLen(int* nums, int numsSize)
{
    // maximum
    int maxlen = 0;
    // current lenghts
    int neglen = 0;
    int poslen = 0;

    for (int i = 0; i < numsSize; i++)
    {
        // it is positive, so add 1 to positive
        // and add 1 to negative if it is already multiplying by a negative
        if (nums[i] > 0)
        {
            poslen++;
            neglen = neglen ? neglen + 1:0;
        }
        // negative, so change signs
        // positive become negative and negative become positive
        else if (nums[i] < 0)
        {
            int temp = poslen;

            poslen = neglen ? neglen + 1:0;
            neglen = temp + 1;
        }
        else // if (nums[i] == 0)
        {
            poslen = 0;
            neglen = 0;
        }

        if (poslen > maxlen) maxlen = poslen;
    }

    return maxlen;
}


// given an array of prices, return the maximum profit can be made
// you can buy and sell more than 1 time
// can sell and buy in the same day
int maxProfit(int* prices, int pricesSize){
    int i = 0;
    int buy, sell;
    int profit = 0;

    pricesSize--;
    while (i < pricesSize)
    {
        while (i < pricesSize && prices[i + 1] <= prices[i]) i++;
        buy = prices[i];

        while (i < pricesSize && prices[i + 1] > prices[i]) i++;
        sell = prices[i];

        profit += sell - buy;
    }
    return profit;
}

// same approach
int maxProfit2(int* prices, int pricesSize){
    int i = 0;
    int buy, sell;
    int profit = 0;

    pricesSize--;
    while (i < pricesSize)
    {
        // try to find a day to buy the stock
        // it will only be profitable if the price of next day is strictly bigger than the price from current day
        // and you can sell and buy a stock at the same day, so if it find a more profitable day to sell is the same as
        // sell and buy again (for example: 1 7 9 -> buy at 1, sell at 7, buy at 7, sell at 9 == -1 + 7 - 7 + 9)
        while (i < pricesSize && prices[i + 1] <= prices[i]) i++;
        buy = prices[i];

        if (i < pricesSize) 
        {
            sell = prices[++i];
            profit += sell - buy;
        }
    }
    return profit;
}

// same logic, but better code
int maxProfit3(int* prices, int pricesSize)
{
    pricesSize--;
    int profit = 0;

    for(int i = 0; i < pricesSize; i++)
    {
        // try to find a day to buy the stock
        // it will only be profitable if the price of next day is strictly bigger than the price from current day
        // and you can sell and buy a stock at the same day, so if it find a more profitable day to sell is the same as
        // sell and buy again (for example: 1 7 9 -> buy at 1, sell at 7, buy at 7, sell at 9 == -1 + 7 - 7 + 9)
        if (prices[i + 1] > prices[i]) profit += prices[i + 1] - prices[i];
    }
}




#define max(a,b) a > b ? a:b

// given an array of values, return the maximum     values[i] + values[j] + i - j
int maxScoreSightseeingPair(int* values, int valuesSize)
{
    int maxscore = 0;

    for (int i = 0, curscore = 0; i < valuesSize; i++)
    {
        // the current score decrease by 1 every iteration (j increases 1 and i stay the same)
        curscore--;
        // stores the maximum score
        maxscore = max(curscore + values[i], maxscore);
        // store the greatest current score
        if (curscore < values[i]) curscore = values[i];
    }
    return maxscore;
}



// same logic as approach 1
int maxScoreSightseeingPair2(int* values, int valuesSize)
{
    int maxscore = 0;

    for (int i = 0, curscore = 0; i < valuesSize; i++, curscore--)
    {
        maxscore = max(curscore + values[i], maxscore);
        curscore = max(curscore, values[i]); // curscore = max(curscore, values[i]) - 1; don't work
        // for some reason, defined procedures don't work if operate with them in same line
    }
    return maxscore;
}