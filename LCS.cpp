#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void){
    string s,t;
    cin >> s >> t;
    int dp[1010][1010];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0;i < s.size();i++){
        for(int j = 0;j < t.size();j++){
            if(s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}
