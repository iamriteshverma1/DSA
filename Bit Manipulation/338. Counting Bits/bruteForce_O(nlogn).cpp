class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        else if(n == 1){
            return {0, 1};
        }
        vector<int> ans = {0,1};
        int count = 0;
        for(int i = 2; i <= n; i++){
            int temp = i;
            while(temp > 0){
                if(temp % 2 == 1){
                    count++;
                    temp = (temp - 1)/2;
                }
                else
                    temp = temp/2;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};
