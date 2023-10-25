#include <bits/stdc++.h>

using namespace std;
int m,n;
void string_matching(string s, string p, int lps[]){
    int q = 0;
    cout<<"Pattern occurred at indexes : ";
    for(int i=1; i<=n; i++){
        while(q>0 && p[q] != s[i-1]){
            q = lps[q];
        }
        
        if(p[q] == s[i-1]){
            q++;
        }
        
        //cout<<q<<" ";
        
        if( q == m ){
            cout<<i-m<<" ";
            q = lps[q];
            
        }
    }
}


int main(){

    string s;
    cout<<"Enter the string : "<<endl;
    cin>>s;
     n = s.size();
    
    string pattern ;
    cout<<"Enter pattern : "<<endl;
    cin>>pattern;
     m = pattern.size();
    
    
    //preprocessing
    int p_table[m+1];
    p_table[1] = 0;
    int k=0;
    for(int q=2;q<=m;q++ ){
        while(k>0 && pattern[k]!= pattern[q-1])
           k = p_table[k];
           
        if(pattern[k] == pattern[q-1])
           k++;
           
        p_table[q] = k;
    }
    
    
    string_matching(s, pattern, p_table);
	

	return 0;
}
