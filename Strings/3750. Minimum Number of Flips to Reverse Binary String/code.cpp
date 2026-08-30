class Solution {
public:

    string s;
    void binary(int x){
        if(x == 1)
            s = "1";
        else if(x % 2 == 0){
            binary(x/2);
            s += "0";
        }
        else{
            binary((x - 1)/ 2);
            s += "1";
        }
    }

    int minimumFlips(int n) {
        if( n == 0)
            return 0;
        s = "";
        binary(n);
        string r = s;
        reverse(r.begin(), r.end());
        int count = 0;
        for(int i = 0 ; i < r.length(); i++){
            if(r[i] != s[i])
                count++;
        }

        return count;
    }
};
