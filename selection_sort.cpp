#include<bits/stdc++.h>
using namespace std;

    void SelectionSort(vector<int>&arr, int n ){
        
            for(int i=0; i<n-1; i++){
                int min_idx = i;
                for(int j=i+1; j<n; j++){
                        if( arr[j] < arr[min_idx] ){
                            min_idx = j;
                        }
                }
                swap( arr[i], arr[min_idx] );
            }
        
    }

int main(){
    vector<int>arr = {2,4,78,4,36,1};
    int n = 6;
    SelectionSort( arr, n );
    cout<<"sorted array :"<<endl;
    for(int i= 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
