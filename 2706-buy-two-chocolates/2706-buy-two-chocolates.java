class Solution {
    public int buyChoco(int[] prices, int money) {
        Arrays.sort(prices);
        int initialMoney=money;
        money-=prices[0];
        money-=prices[1];
        if(money<0)return initialMoney;
        return money;
    }
}