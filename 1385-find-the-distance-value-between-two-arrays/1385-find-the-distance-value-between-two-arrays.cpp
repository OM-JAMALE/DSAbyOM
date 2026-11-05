class Solution {
public:
    // first index with arr[idx] >= val, or arr.size() if none
    int lower_b(vector<int>& arr, int val) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < val) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        int count = 0;

        for (int x : arr1) {
            int idx = lower_b(arr2, x - d);
            // no arr2 value in [x-d, x+d]
            if (idx == n || arr2[idx] > x + d) {
                count++;
            }
        }
        return count;
    }
};