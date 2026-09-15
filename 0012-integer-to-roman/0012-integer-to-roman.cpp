class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";

        if(num / 1000 >= 1) {
            ans += string(num/1000, 'M');
            num = num % 1000;
        }

        if(num / 900 == 1) {
            ans += "CM";
            num = num % 900;
        }

        if( num / 500 == 1) {
            ans += 'D';
            num %= 500;
        }

        if( num / 400 == 1) {
            ans += "CD";
            num %= 400;
        }

        if( num / 100 >= 1) {
            ans += string(num/100, 'C');
            num %= 100;
        }

        if( num / 90 == 1) {
            ans += "XC";
            num %= 90;
        }
            
        if( num / 50 == 1) {
            ans += 'L';
            num %= 50;
        }

        if( num / 40 == 1) {
            ans += "XL";
            num %= 40;
        }

        if( num / 10 >= 1) {
            ans += string(num/10,'X');
            num %= 10;
        }
            
        if(num / 9 == 1) {
            ans += "IX";
            num %= 9;
        }

        if(num / 5 == 1) {
            ans += 'V';
            num %= 5;
        }
        if(num / 4 == 1) {
            ans += "IV";
            num %= 4;
        }
        if(num >= 1) {
            ans += string(num, 'I');
            num = 0;
        }

        return ans;
    }
};