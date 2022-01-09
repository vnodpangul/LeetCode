class Solution {
public:
    string fractionToDecimal(int num, int denom) {
      
        map<int, int> mp;
        string res="";
        bool isAnsNeg = false;
        if(num==0) return "0";
        if((num<0 || denom<0) && !(num<0 && denom<0)) isAnsNeg = true;
        
        long rem = num;
        while(rem != 0) {
            
            res += to_string(abs(rem/denom));
            rem = rem%denom;
            
            if(mp.find(rem) != mp.end()) {
                res.insert(mp[rem], "(");
                res +=")";
                break;
            }
            if(rem && res.find(".")== res.npos)
                res +=".";
            
            mp[rem] = res.size();
            rem *= 10;
        }
        
        return isAnsNeg ? "-"+res : res;
         
    }
};