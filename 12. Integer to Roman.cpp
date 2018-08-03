class Solution {
public:
    string intToRoman(int num) {
        const string THOUS[]= {"","M","MM","MMM"};
        const string HUNDS[]= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        const string TENS[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        const string ONES[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        return THOUS[(num%10000)/1000]+HUNDS[(num%1000)/100]+TENS[(num%100)/10]+ONES[num%10];
    }
};