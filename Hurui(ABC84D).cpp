#include <iostream>
using namespace std;
bool f[100010];
int ruiseki[100010];
int main(void){
    int n,l,r;
    cin >> n;
    for(int i = 2;i <= 100000;i++){
        if(!f[i]){
            for(int j = i+i;j <= 100000;j+=i) f[j] = true;
        }
    }
    for(int i = 3;i <= 100000;i+=2) if(!f[i] && !f[(i+1)/2]) ruiseki[i] = 1;
    for(int i = 3;i <= 100000;i++) ruiseki[i] += ruiseki[i-1];
    
    while(n > 0){
        cin >> l >> r;
        cout << ruiseki[r] - ruiseki[l-1] << endl;
        n--;
        if(n == 0) break;
    }
    return 0;
}
