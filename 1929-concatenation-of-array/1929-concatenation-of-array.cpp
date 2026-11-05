class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int n = nums.size(),i=0;
      vector<int>arr(2*n);
       while(i<n){
        arr[i] = nums[i];
        arr[n+i] = nums[i];
        i++;
       }
       return arr;
     }
};