#include<bits/stdc++.h>
using namespace std;

int firstPosition(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1;
    int pos = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            pos = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return pos;
}

int lastPosition(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1, pos = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            pos = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return pos;
}

int count(vector<int>& arr, int n, int x) {
    int first = firstPosition(arr, n, x);
    if(first == -1) // x not present
        return 0;
    int last = lastPosition(arr, n, x);
    return last - first + 1;   // no of element between the range [first, last]
}
