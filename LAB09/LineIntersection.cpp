#include <bits/stdc++.h>

using namespace std;
struct point{
	double x;
	double y;
};

//Check the direction of p1p3 with respect to p1p2
double direction(struct point p1, struct point p2, struct point p3){
	double a = p3.x - p1.x ;
	double b = p3.y - p1.y ;
	double c = p2.x - p1.x ;
	double d = p2.y - p1.y ;
    
	return (a*d)-(b*c) ;
}

//check whether p3 is on segment p1p2 or not
bool onSegment (struct point p1,struct point p2, struct point p3){
	if(min(p1.x,p2.x)<= p3.x && p3.x<=max(p1.x,p2.x) && min(p1.y,p2.y)<=p3.y && p3.y<=max(p1.y,p2.y))
    	return true;
    
	else
   	return false;
}

bool intersect(struct point p1, struct point p2, struct point p3, struct point p4){
	double d1 = direction(p1, p2, p3);
	double d2 = direction(p1, p2, p4);
	double d3 = direction(p3, p4, p1);
	double d4 = direction(p3, p4, p2);
    
	if((d1*d2)<0 && (d3*d4)<0)
   	return true;
  	 
	else if(d1==0 && onSegment(p1, p2, p3) == true)
   	return true;
    
	else if(d2==0 && onSegment(p1, p2, p4) == true)
   	return true;
    
	else if(d3==0 && onSegment(p3, p4, p1) == true)
   	return true;
    
	else if(d4==0 && onSegment(p3, p4, p2) == true)
   	return true;
    
	else
  	return false;
}

int main()
{
	struct point p1,p2,p3,p4;
	cout<<"Enter p1 p2 p3 and p4 : "<<endl;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    
	if(intersect(p1, p2, p3, p4))
	cout<<"P1P2 and P3P4 intersect.";
    
	else
	cout<<"P1P2 and P3P4 do not intersect";

	return 0;
}
