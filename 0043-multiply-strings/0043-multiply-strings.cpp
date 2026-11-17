
class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        string ans = "";
        string count = "";
        int carry = 0;

        for(int i = n - 1; i >= 0; i--) {

            int mul = (num1[i] - '0') * (num2[m - 1] - '0');
            mul += carry;

            ans += (mul % 10 + '0');
            carry = mul / 10;
        }

        if(carry != 0)
            ans += (carry + '0');

        for(int i = m - 2; i >= 0; i--) {

            count += '0';

            if(num2[i] == '0')
                continue;

            string temp = count;
            carry = 0;

            for(int j = n - 1; j >= 0; j--) {

                int mul = (num1[j] - '0') * (num2[i] - '0');
                mul += carry;

                temp += (mul % 10 + '0');
                carry = mul / 10;
            }

            if(carry != 0)
                temp += (carry + '0');

            // Add partial product to ans
            carry = 0;
            int j = 0;

            while(j < ans.size() && j < temp.size()) {

                int sum = (ans[j] - '0') +
                          (temp[j] - '0') + carry;

                ans[j] = (sum % 10) + '0';
                carry = sum / 10;

                j++;
            }

            while(j < temp.size()) {

                int sum = (temp[j] - '0') + carry;

                ans += (sum % 10) + '0';
                carry = sum / 10;

                j++;
            }

            while(carry != 0 && j < ans.size()) {

                int sum = (ans[j] - '0') + carry;

                ans[j] = (sum % 10) + '0';
                carry = sum / 10;

                j++;
            }

            if(carry != 0)
                ans += (carry + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
