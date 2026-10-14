/*
class Solution {
public:
    long long bestScr = -1;
    string best = "";
    
    void backtrack(int pos, int remaining, string &cur, long long score, int num) {

        if(pos == num) {
            if(remaining == 0) {
                if(score > bestScr || (score == bestScr && cur > best)) {
                    bestScr = score;
                    best = cur;
                }
            }
            return;
        }

        int slots = num - pos - 1;

        if(remaining < 0 || remaining > 9 * (slots + 1)) {
            return;
        }

        int start = (pos == 0) ? 1 : 0;

        for(int digit = 9; digit >= start; digit--) {

            if(digit > remaining)
                continue;
            
            int nextRemain = remaining - digit;

            if(nextRemain > 9 * slots) {
                continue;
            }

            cur.push_back(char('0' + digit));

            backtrack(pos + 1, nextRemain, cur, score + 1LL * digit * digit, num);

            cur.pop_back();
        }

    }

    string maxSumOfSquares(int num, int sum) {
        bestScr = -1;
        best = "";

        if(sum < 1 || sum > 9 * num) {
            return "";
        }

        string cur = "";

        backtrack(0, sum , cur, 0, num);

        return best;
    }
};

*/


class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num)
            return "";

        string ans;

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            ans.push_back('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};
