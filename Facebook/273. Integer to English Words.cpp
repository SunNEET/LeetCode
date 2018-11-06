class Solution {
private:
    const string LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", 
                                     "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                                    "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen","Nineteen"};
    const string TENS[10] = {"", "Ten", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    const string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
public:
    // 為了減少判斷上的困難，我們統一在每個"單位"和"數字"後面才加空白，前面就不理他。
    string numberToWords(int num) {
        // 特判 0 
        if(num == 0) return "Zero";
        int i=0;
        string ans="";
        while(num > 0) {
            // 用來避免現在是 1000 的倍數而 mod 出 0 的情況
            // 雖然說 helper 不會有數字回傳，但因為我們會在這裡加 thousand 的單位跟空白
            // 0跑進來的話就會多出, 就會多出額外的單位(和空白)
            // e.g. 1000000 => One Million Thousand
            if(num % 1000 !=0) 
                ans = helper(num%1000)+THOUSANDS[i]+ " " + ans;
            num /= 1000;
            i++;
        }
        size_t first = ans.find_first_not_of(' ');
        size_t last = ans.find_last_not_of(' ');
        return ans.substr(first,(last-first)+1);
    }
    
    string helper(int num) {
        if(num == 0)
            return "";
        else if(num < 20)
            return LESS_THAN_20[num] + " ";
        else if(num < 100)
            return TENS[num/10]+" "+helper(num%10);
        else
            return LESS_THAN_20[num/100] + " Hundred " + helper(num%100);
    }
};

// 自己寫的版本
class Solution {
    // 有很多需要細心處理的地方，首先將 1~20 歸成一類，10 的倍數到 90 歸成一類，千的倍數規成一類
    // 每一輪都取三個位數，丟到 helper 裡去算是 多少"Hundred" + ""
    // 並且將依照輪數再結果後面加上 thousand
private:
    const string LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", 
                                     "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                                    "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen","Nineteen"};
    const string TENS[10] = {"", "Ten", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    const string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
    
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        int i=0;
        string ans="";
        while(num > 0) {
            if(num%1000!=0) // prevent the multiple of one thousand pass into the helper function.
                ans = i ? helper(num%1000) + " " + THOUSANDS[i] + " " + ans : helper(num%1000) ;
            num /= 1000;
            i++;
        }
        while(ans.back()==' ') ans.pop_back();
        return ans;
    }
    
    string helper(int num) {
        string res = "";
        // 先處理百位數，如果有的話
        if(num > 99) 
            res = LESS_THAN_20[num/100] + " Hundred";
        // 再來處裡十位跟個位，這邊分成兩種情況
        // 小於20的話就直接用 LESS_THAN_20
        // 另一種就要湊TENS跟LESS_THAN_20
        // 並且都要判斷有沒有需要在前面加空白
        if(num%100<20){ // e.g. 112, 102, *100
            res += num > 99 && num%100 ? " ":"";
            res += LESS_THAN_20[num%100];
        } else {
            res += num > 99 ? " ":"";
            res += TENS[(num%100)/10];
            res += num%10 ? " " + LESS_THAN_20[num%10]:"";
        }
        return res;
    }
};