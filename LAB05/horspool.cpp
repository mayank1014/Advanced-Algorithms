
#include<bits/stdc++.h>
using namespace std;


int main(){
    
	//shift table
	string str,pattern;
	cout<<"Enter the string : "<<endl;
	cin >> str;
	cout<<"Enter the pattern that you want to find : "<<endl;
	cin >> pattern;
   
  	int n = str.size();
  	int m = pattern.size();
  	int arr[26];
  	for(int i=0;i<26;i++){
      	arr[i] = m;
  	}
  	for(int i=0;i<=m-2;i++){
    	 
      	arr[pattern[i]-'a'] = m-i-1;
  	}
 	 
 	 
  	int j = 0;
  	cout<<"Pattern occurred at indexes : ";
  	while(j+m<=n){
      	if(str[j+m-1] == pattern[m-1]){
          	int i = m-2;
          	while(i>=0 && pattern[i]==str[j+i]){
              	i--;
          	}
          	if(i==-1){
              	cout<<j<<" ";
             	 
          	}
      	}
      	if(str[j+m-1]=='_'||str[j+m-1]=='.'){
          	j+=m;
      	}
      	else{
      	j = j+arr[str[j+m-1]-'a'];}
  	}
 	 
	return 0;
}
