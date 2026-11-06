class Solution {
public:
   int B_search(vector<int> & arr,int n){
    int L = 0;
    int U = arr.size() - 1;
    while(L <= U){
        int mid = L + (U-L)/2;
        if(arr[mid] == n){
            mid--;
            while((mid >= 0 )&&(arr[mid]==n)){
                mid--;
            }
            return mid;
        }
        if(arr[mid]>n){
            U = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    if(arr[L] < n){
        return L;
    }else{return L - 1;}
        
    
   }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr(nums);
        sort(arr.begin(),arr.end());
        vector<int> arr2;
        for(int i : nums){
            arr2.push_back(B_search(arr,i)+1);
        }
        return arr2;
    }
};