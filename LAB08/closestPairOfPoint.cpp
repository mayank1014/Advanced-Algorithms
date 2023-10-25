#include <bits/stdc++.h>

using namespace std;

struct point{
    int x;
    int y;
};

void find_closest_pair_of_points(struct point p[], int n){
    int d_min = INT_MAX, ans_i, ans_j;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1 = p[i].x;
            int x2 = p[j].x;
            int y1 = p[i].y;
            int y2 = p[j].y;
            
            int a = (x1-x2)*(x1-x2);
            int b = (y1-y2)*(y1-y2);
            
           int d = sqrt(a+b);
            
            if(d<d_min){
                d_min = d;
                ans_i = i+1;
                ans_j = j+1;
            }
        }
    }
    
    cout<<"Point"<<ans_i<<" and"<<"Point"<<ans_j<<" are the closest pair of points with Distance:"<<d_min;
}


int main(){
   int n;
   cout<<"Enter number of points you have : "<<endl;
   cin>>n;
   
   struct point p[n];
   cout<<"Enter points in form of p(x) and p(y) : "<<endl;
   for(int i=0;i<n;i++){
       cin >> p[i].x;
       cin>> p[i].y;
   }
   
   find_closest_pair_of_points(p,n);

	return 0;
}

// case1:
// 3
// 1 2
// 1 3
// 2 3

// o/p:
// closest pair of points are : 
// p1(1,2)
// p2(1,3)
// Distance : 1
