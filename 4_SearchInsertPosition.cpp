#include<bits/stdc++.h>
using namespace std;
// arr : [1,4,9,10],   X = 7
// arr : [1,4,7,9,10], ans = 2
// it is just lowerbound of X
int searchInsert(vector<int>& arr, int X){
	int low = 0, high = arr.size()-1;
	int ans = high + 1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(arr[mid] >= X){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
// TC - O(log2N)