#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <string.h>


class Solution {
private:
    using LL = long long;

public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        
        // 前缀和
        vector<LL> sum(n);
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + candiesCount[i];
        }
        
		vector<bool> ans;
        for (const auto& q: queries) {
            int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];
            
            LL x1 = favoriteDay + 1;
            LL y1 = (LL)(favoriteDay + 1) * dailyCap;
            LL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
            LL y2 = sum[favoriteType];
            
            ans.push_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};

bool* canEat(int* candiesCount, int candiesCountSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = candiesCountSize;

    // 前缀和
    long sum[n];
    sum[0] = candiesCount[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + candiesCount[i];
    }
    bool* ans = malloc(sizeof(bool) * queriesSize);
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        int* q = queries[i];
        int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];

        long x1 = favoriteDay + 1;
        long y1 = (long)(favoriteDay + 1) * dailyCap;
        long x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
        long y2 = sum[favoriteType];

        ans[i] = !(x1 > y2 || y1 < x2);
    }
    return ans;
}


int main(void)
{
	
}



