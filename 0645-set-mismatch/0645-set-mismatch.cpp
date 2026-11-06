class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        vector<int> arr2(2,0);
        for(int i : nums){
            arr[i-1]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(arr[i]==2){
               arr2[0] = i+1;
            }
            if(arr[i]==0){
                arr2[1] = i+1;
            }
            if((arr2[0] != 0)&&(arr2[1] != 0)){
                break;
            }
        }
        return arr2;
    }
};