#include <bits/stdc++.h> 

void binary( vector<int> &bin, long long N ){

    if( N == 0)  
         return ;
    int digit = N % 2;
    
    N = N / 2;
    binary( bin, N );

    bin.push_back( digit );

}

bool check( vector<int> &bin, int s, int e ){

    if( s>e || s==e )
      return true;
    if( bin[s] == bin[e] ){
        s++;
        e--;
    }
    else{
        return false;
    }
    check( bin, s, e );


}

bool checkPalindrome(long long N)
{
    vector<int> bin ;
    binary( bin, N );

    int s = 0;
    int e = bin.size() - 1;
    if(check( bin, s, e ))
     return true;
    else
     return false;

    
}
