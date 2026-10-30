class Solution {

public :
    int coinChange(vector<int>& coins, int amount) {
        vector<int> F1(1 + amount);
        F1[0] = 0;
        for(int t = 1; t <= amount; t++) {
            F1[t] = -1;
            for(int i = 0; i < coins.size(); i++) {
                if(coins[i] <= t) {
                    int sub = F1[t - coins[i]];
                    if(sub != -1) {
                        if(F1[t] == -1 || 1 + sub < F1[t]) {
                            F1[t] = 1 + sub;
                        }
                    }
                }
            }
        }
        return F1[amount];
    }
};



class Solution1a {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> F1(1 + amount, -2);
        return f1(coins, amount, F1);
    }

private :
    int f1(vector<int>& coins, int amount, vector<int>& F1) {
        if(F1[amount] != -2)
            return F1[amount];
        if(amount == 0)
            return F1[amount] = 0;
        int minCoins = -1;
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= amount) {
                int sub = f1(coins, amount - coins[i], F1);
                if(sub != -1) {
                    if(minCoins == -1 || 1 + sub < minCoins) {
                        minCoins = 1 + sub;
                    }
                }
            }
        }
        return F1[amount] = minCoins;
    }
};


class Solution1b {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int minCoins = -1;
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= amount) {
                int sub = coinChange(coins, amount - coins[i]);
                if(sub != -1) {
                    if(minCoins == -1 || 1 + sub < minCoins) {
                        minCoins = 1 + sub;
                    }
                }
            }
        }
        return minCoins;
    }
};