class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0,t = 0;
        for(int i : nums){
            if(i==1){
                t++;
            }else if(t != 0){
                if(t>max){
                    max = t;
                }
                t = 0;
            }
        }
         if(t>max){
                    max = t;
                }
         return max  ;     
    }
};