class Solution {
    /*
        2 pointer，水題
    */
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) return vector<int>({left+1, right+1});
            else if(sum > target) right--;
            else if(sum < target) left++;
        }
        return {};
    }
};

class Solution {
    /*  
        二分搜
    */
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++) {
            int idx = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i])
                        - numbers.begin();
            if(idx < numbers.size() && numbers[idx] == target-numbers[i]) 
                return {i+1,idx+1};
        }
        return {};
    }
};