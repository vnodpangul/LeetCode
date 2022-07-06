class Solution {
public:
    int shortestWay(string source, string target) {
        
        int noOfSubSequence = 0;
        string rem = target;
        
        while(rem.size()>0)
        {
            int i=0;
            int j= 0;
            string subSeq = "";
            while(i<source.size() && j<rem.size())
            {
                if(source[i] == rem[j]) {
                    subSeq += rem[j];
                    j++;
                        
                }
                i++;
            }
            if(subSeq.size()==0) return -1;
            noOfSubSequence++;
            rem = rem.substr(subSeq.size());
        }
        
        return noOfSubSequence;
    }
};
