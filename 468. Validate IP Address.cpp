class Solution {
  /*
    字串處理，沒有算法成分
    可以看前4個字元有沒有 '.' 來判斷他會不會是IPv4的字串, 有的話就讓他做 IPv4 的檢查判斷
    不是的話就看前5個有沒有 ':', 判斷會不會是IPv6, 然後對他做IPv6的檢查
    都不是的話就直接回傳 Neither

    IPv4: To check IPv4, we have to first check 
    (1) if the size of the splitted block is greater than 0 and less than equal to 3
        otherwise, it is not valid.
    (2) is there any non digit character or leading zero. If it has, then return false;
    (3) add up the value, check if it is less than equal to 255

    IPv6: To check IPv6, we have to check the size of the splitted block either.
    and then, just check if the character is a valid IPv6 character.

    善用 stringstream 和 getline(ss,string,'.')來切割字串, 
    用 ss.eof() 來判斷字串是不是太短或太長(提早讀完或還沒讀完)
  */
private:
    bool isValidIPv4Block(string& block) {
        int num = 0;
        if (block.size() > 0 && block.size() <= 3) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                // special case: if c is a leading zero and there are characters left
                if (!isdigit(c) || (i == 0 && c == '0' && block.size() > 1))
                  return false;
                else {
                      num *= 10;
                      num += c - '0';
                }
            }
            return num <= 255;
        }
        return false;
    }
    
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    
    bool isValidIPv6Block(string& block) {
        if (block.size() > 0 && block.size() <= 4) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                if (validIPv6Chars.find(c) == string::npos)
                  return false;
            }
            return true;
        }
        return false;
    }
    
public:
    string validIPAddress(string IP) {
        string ans[3] = {"IPv4", "IPv6", "Neither"};
        stringstream ss(IP);
    	string block;
        // ipv4 candidate
    	if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; i++) {
                if (!getline(ss, block, '.') || !isValidIPv4Block(block))
                    return ans[2];
            }
            return ss.eof() ? ans[0] : ans[2];
    	} else if (IP.substr(0, 5).find(':') != string::npos) { // ipv6 candidate
    	      for (int i = 0; i < 8; i++) {
                if (!getline(ss, block, ':') || !isValidIPv6Block(block))
                    return ans[2];
            }
            return ss.eof() ? ans[1] : ans[2];
    	}
        return ans[2];
    }
};