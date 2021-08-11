// Problem: C - Bear and Game
// Link: https://codeforces.com/problemset/problem/546/A
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100];
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    int t =0;
    bool flag = true;
    int pos = 0;
    if(arr[0] > 15){
        cout << "15" << endl;
        return 0;
    } 
    else{
        for(int i =1; i< n; i++){
            if(arr[i] - arr[i-1] > 15){
                flag = false;
                pos = i-1;
                break;
            }
        }
        if(flag == false){
            t = arr[pos] + 15;
        }
        else t = arr[n -1] + 15;
    }
    if(t > 90) cout << 90 << endl;
    else cout << t << endl;
    
    return 0;
}