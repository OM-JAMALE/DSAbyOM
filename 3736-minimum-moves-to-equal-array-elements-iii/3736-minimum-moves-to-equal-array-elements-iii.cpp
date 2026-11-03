
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = nums[0];
        for (int i : nums){
            if(max < i){ max = i;}
        }
        int diff = 0;
        for(int i: nums){
           diff = diff + max - i;
        }
        return diff;
    }
};