// BEST TIME TO BUY AND SELL STOCKS
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minele=prices[0];
        for(int i=1;i<prices.size();i++){
            minele=min(minele,prices[i]);
            ans=max(ans, prices[i]-minele);
        }
        return ans;
    }

// Input: prices = [7,1,5,3,6,4]
// Output: 5