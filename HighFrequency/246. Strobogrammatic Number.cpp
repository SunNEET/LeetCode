class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> hash;
        hash['0']='0';
        hash['1']='1';
        hash['6']='9';
        hash['8']='8';
        hash['9']='6';
        int len = num.length();
        for(int i=0;i<(len+1)/2;i++) {
            char c = num[i];
            if(hash.count(c)) {
                if(hash[c]!=num[len-1-i])
                    return false;
            } else
                return false;
        }
        return true;
    }
};