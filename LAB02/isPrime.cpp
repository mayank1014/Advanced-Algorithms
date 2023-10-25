#include <bits/stdc++.h>
using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
    
	while(b!=0){
    	unsigned long long int r =a%b;
    	a=b;
    	b=r;
	}
    	return a;
}

unsigned long long int power(unsigned long long int a,unsigned long long int x, unsigned long long int n){
	unsigned long long int res = 1;
	a = a%n;
	while(x>0){
    	if(x%2 ==1)
      	res= (res*a)%n;
     	 
    	x=x/2;
   	 
    	a=(a*a)%n;
	}
	return res;
}

float find_liars(unsigned long long int n){
	int count = 0;
    
	for(int a=2;a<=n-2;a++){
    	if(power(a,n-1,n)==1)
      	count++;
	}
    
	return count/float(n-3);
}
bool is_Prime(unsigned long long int n){
    
	int k = 100;
	if(n<=1 || n==4)
  	return false;
 	 
 	if( n<=3 )
   	return true;
 	 
	while(k>0){
   	 
    	srand(time(0));
    	unsigned long long int a = 2 + rand()%(n-4);
   	 
    	if(gcd(n,a) != 1)
       	return false;
      	 
    	if(power(a,n-1,n) != 1)
       	return false;
      	 
    	k--;
	}
    
    
	return true;
}

int main()
{
   unsigned long long int n;
   cout<<"Enter a number : "<<endl;
   cin>>n;
   
   bool ans = is_Prime(n);
   
   if(ans == true)
   cout<<n<<" is a prime number"<<endl;
   
   else
   cout<<n<<" is not a prime number"<<endl;
   
   float probability = find_liars(n);
   
	cout<<"Probability of f_liars is : "<<probability<<endl;
   
	return 0;
}
