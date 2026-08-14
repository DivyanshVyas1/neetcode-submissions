class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int ans=0;
        int buy=0;
        int sell=1;
        while(buy<prices.size()&&sell<prices.size()){
            if(prices[buy]>prices[sell]){
                buy=sell;
                sell++;
            }
            else if(prices[sell]>prices[buy]){
                pro=prices[sell]-prices[buy];
                ans=max(pro,ans);
                sell++;
            }
            else{
                sell++;
            }

        }
        return ans;
        
    }
};
