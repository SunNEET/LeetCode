class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 雖然説是左下角跟右上角，但題目並沒有說到x1, y1, x2, y2之間的相對關係，也就是有沒有可能出現 y2<y1, x2<x1 這種情況
        // 不過看LC標程的輸出是當作他們不會有這種情況發生
        // 所以(x1,y1)肯定在(x2,y2)的左下方, 那這樣就很好判斷了
        // 只要下列任一個條件滿足就表示不重疊
        return !( (rec1[2] <= rec2[0]) || (rec1[3] <= rec2[1])
            || (rec1[0] >= rec2[2]) || (rec1[1] >= rec2[3]));
    }
};