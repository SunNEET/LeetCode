class Solution {
    /*
        用 stack + hashmap 維護 num2 中的 next greater integer
        key: 假設有個 stack [9, 8, 7, 3, 2, 1]
                           ^bottom         ^top
        如果此時的 num 是 6，則比他小的 1,2,3 都依序pop出來，
        並且用 map 紀錄 1,2,3 的 next greater int 就是 6
        因為 num1 是 num2 的 subset，所以直接查這個map就可以了
        Time:  O(N)
        Space: O(1)
    */
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size());
        unordered_map<int,int> next_greater_element;
        stack<int> st;
        for(int num : nums) {
            while(!st.empty() && st.top() < num) {
                next_greater_element[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for(int i=0; i<findNums.size(); i++)
            if(next_greater_element.count(findNums[i]))
                res[i] = next_greater_element[findNums[i]];
            else
                res[i] = -1;
        return res;
    }
};