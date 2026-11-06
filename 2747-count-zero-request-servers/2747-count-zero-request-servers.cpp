class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    //     vector<int>arr(queries.size(),0);
    //        vector<int> server(n,0);
    //     for(int i = 0;i<queries.size();i++){
    //         for(int j = 0;j<logs.size();j++){
    //                 if((logs[j][1] >= queries[i] - x)&&(logs[j][1]<=queries[i])){
    //                  server[logs[j][0] - 1] += 1;
    //                 }
    //         }
    //         for(int k = 0;k<n;k++){
    //             if(server[k] == 0){
    //                 arr[i]++;
    //             }else{
    //                 server[k] = 0;
    //             }
    //         }

    //     }
    //     return arr;
        
    // }
    sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        // Store queries along with their original indices
        vector<vector<int>> qs(m);
        for (int i = 0; i < m; ++i) {
            qs[i] = {queries[i], i};
        }
        
        // 2. Sort queries by time
        sort(qs.begin(), qs.end());

        unordered_map<int, int> active_servers;
        vector<int> ans(m);
        int left = 0, right = 0;

        // 3. Process each query using a sliding window
        for (auto& q : qs) {
            int r = q[0];
            int idx = q[1];
            int l = r - x;

            // Expand window to include logs with time <= r
            while (right < logs.size() && logs[right][1] <= r) {
                active_servers[logs[right][0]]++;
                right++;
            }

            // Shrink window to exclude logs with time < l
            while (left < logs.size() && logs[left][1] < l) {
                active_servers[logs[left][0]]--;
                if (active_servers[logs[left][0]] == 0) {
                    active_servers.erase(logs[left][0]);
                }
                left++;
            }

            // Total servers minus servers that received at least one request
            ans[idx] = n - active_servers.size();
        }

        return ans;
    }
};