#include<bits/stdc++.h>
using namespace std;
// Floor : largest No. in array <= x
// Ceil  : Smallest No. in array >= x : lowerbound
// arr : [10,20,30,40,50], x = 25
// floor = 20, ceil = 30
int lowerBound(int arr[], int n, int x) {
	int low = 0, high = n-1, ans = -1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(arr[mid] >= x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;		
}
int find_floor(int arr[], int n, int x){
    int low = 0, high = n - 1, floor = -1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= x){
            floor = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return floor;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n);
    int ceil = lowerBound(arr, n, x);
    int floor = find_floor(arr, n, x);
    return {floor == -1 ? -1 : arr[floor],
		   	ceil == -1 ? -1 : arr[ceil]};
}
// - 1 represents that the index is out of the array.
// TC - O(log N)