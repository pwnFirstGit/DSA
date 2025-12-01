#include<bits/stdc++.h>
using namespace std;

    void BubbleSort(vector<int>&arr, int n ){
        
            for(int i=0; i<n; i++){
                
                for(int j=0; j<n-i-1; j++){
                        if( arr[j] > arr[j+1] ){
                            swap( arr[j], arr[j+1] );
                        }
                }
            }
    }

int main(){
    vector<int>arr = {0,1,0,1,0,1,0,1,0,1,0};
    int n = 11;
    BubbleSort( arr, n );
    cout<<"sorted array :"<<endl;
    for(int i= 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
