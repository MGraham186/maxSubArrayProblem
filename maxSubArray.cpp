
#include <iostream>
#include <cmath>
struct Locations;
int findMaxSubArray(int x[], int l, int m, int h);
void displayArray(int x[], int n);
int maxSubArray(int x[], int l, int h);
int max(int a, int b);
int max(int a, int b, int c);
using namespace std;

int main() {

	//int gaps[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	//int gaps[] = {1,3,5};
	int gaps[] = {5,2,3};
	int lengthGaps = sizeof(gaps)/sizeof(gaps[0]);
	cout<<maxSubArray(gaps,0,lengthGaps-1);
}


int findMaxSubArray(int x[], int l,int m, int h){

	int sum = 0;
	int left_sum = INT_MIN;
	for(int i = m; i>=l; i--){

		sum = sum + x[i];
		if(sum>left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = INT_MIN;
	for(int j = m+1; j<=h; j++){

		sum = sum + x[j];
		if(sum>right_sum){
			right_sum = sum;
		}

	}

	return(right_sum+left_sum);


}
int maxSubArray(int x[], int l, int h){
	if(l==h){return x[l];}

	else{
		int mid = (l+h)/2;
		return max(maxSubArray(x, l, mid),
				maxSubArray(x, mid+1, h),
				findMaxSubArray(x, l, mid, h));



	}

}
int max(int a, int b) { return (a > b)? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
void displayArray(int x[], int n){
	for(int i = 0; i<n ; i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
