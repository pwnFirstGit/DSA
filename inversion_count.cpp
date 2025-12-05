class Solution {
  public:
  
        
      int merge( vector<int> &arr, int s, int e ){
          
          int ans = 0;
          int mid = s + (e-s) / 2;
          
          int len1 = mid - s + 1;
          int len2 = e - mid;
          
          int* a1 = new int[len1];
          int* a2 = new int[len2];
          
          int k = s;
          for( int i=0; i < len1; i++ ){
              a1[i] = arr[k++];
          }
          
          k = mid+1;
          for( int i=0; i < len2; i++ ){
          
            a2[i] = arr[k++];
              
          }
          
          int idx1 = 0;
          int idx2 = 0;
          
          k = s;
          while( idx1 < len1 && idx2 < len2 ){
              
              if( a1[idx1] > a2[idx2] ){
                  ans += ( len1 - idx1 );
                  arr[k++] = a2[idx2++];
              }
              else{
                  arr[k++] = a1[idx1++];
              }
              
          }
          
          while( idx1 < len1 ){
              arr[k++] = a1[idx1++]; 
          }
          
          while( idx2 < len2 ){
              arr[k++] = a2[idx2++];
          }
          
          return ans;
          
          
      }
  
      int count( vector<int> &arr, int s, int e ){
            
            if( s>=e ){
                return 0;
            }
            
            int mid = s + (e-s) / 2;
            
            int inv = count( arr, s, mid );
            inv += count( arr, mid+1, e );
            inv += merge( arr, s, e );
            return inv;
            
        }
  
    int inversionCount(vector<int> &arr) {
        
        return count( arr, 0, arr.size() - 1 );
        
    }
    
    
    
    
};
