class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
      vector<int> time;
    
    for (auto it : timePoints) {
        int num = 0, temp = 0;
        for (char c : it) {
            if (c == ':') { 
                temp = num * 60;
                num = 0;
                continue;
            }
            num = num * 10 + (c - '0');
        }
        time.push_back(temp + num); 
    }
    sort(time.begin(), time.end()); 

    
    int ans = 1440 + time[0] - time.back();
    for (int i = 1; i < time.size(); i++) {
        int diff = time[i] - time[i - 1];
        ans = min(ans, diff); 
    }
    return ans;
    }
};