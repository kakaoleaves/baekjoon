#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int sz = (int) triangle.size();
    
    vector<vector<int>> dp(sz);
    
    for (int i = 0; i < sz; i++) {
        dp[i].resize(i + 1);
    }
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];                
            else 
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    } 
    
    answer = *max_element(dp[sz - 1].begin(), dp[sz - 1].end());
    
    return answer;
}