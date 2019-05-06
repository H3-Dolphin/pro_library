#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int inf = 1<<29;
int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    int dp[n];
    for(int i = 0;i < n;i++) dp[i] = inf;
    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);
    for(int i = 1;i < n;i++){
        dp[i+1] = min(dp[i]+abs(a[i+1]-a[i]),dp[i-1]+abs(a[i+1]-a[i-1]));
    }
    cout << dp[n-1]<< endl;
    return 0;
}
