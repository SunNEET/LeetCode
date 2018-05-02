class Solution {
    // 題目的直覺作法應該是把0~n的總和加出來, 再去扣掉nums的總和, 這樣就能得出少掉的val
    // 有個很屌的作法是把0~n都XOR一遍, 然後nums自己也全部XOR一遍, 再拿兩個結果互相XOR, 就能得到少的val
    // 這是基於XOR的一個性質 A XOR B XOR B = A, 即對給定的數A, 用同樣的運算因子 B 作兩次異或運算後仍得到A本身。
    // ex: D = A XOR B XOR C, E = A XOR C, D XOR E = (A XOR B XOR C) XOR (A XOR C) = B 
    // A和C因為做了兩次XOR運算所以抵銷了 
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        // 0~n total
        for(int i=0;i<=nums.size();i++)
            x^=i;
        // nums
        for(int i=0;i<nums.size();i++)
            x^=nums[i];
        return x;
    }
};
