#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a 2D point
struct point {
    double x;
    double y;
};

// Function to calculate the direction of three points
// It calculates the cross product to determine direction
double direction(struct point p1, struct point p2, struct point p3) {
    double a = p3.x - p1.x;
    double b = p3.y - p1.y;
    double c = p2.x - p1.x;
    double d = p2.y - p1.y;
    
    return (a * d) - (b * c);
}

// Function to check if a point is on a line segment
bool onSegment(struct point p1, struct point p2, struct point p3) {
    if (min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y))
        return true;
    else
        return false;
}

// Function to check if two line segments intersect
bool intersect(struct point p1, struct point p2, struct point p3, struct point p4) {
    double d1 = direction(p1, p2, p3);
    double d2 = direction(p1, p2, p4);
    double d3 = direction(p3, p4, p1);
    double d4 = direction(p3, p4, p2);
    
    // Check for intersection based on relative directions
    // if the product of d1 and d2 is negative, it means P3 and P4 are on different sides of the line
    if ((d1 * d2) < 0 && (d3 * d4) < 0)
        return true;
    
    // Check if any of the points lie on the other segment
    if (d1 == 0 && onSegment(p1, p2, p3))
        return true;
    if (d2 == 0 && onSegment(p1, p2, p4))
        return true;
    if (d3 == 0 && onSegment(p3, p4, p1))
        return true;
    if (d4 == 0 && onSegment(p3, p4, p2))
        return true;
    
    return false;
}

int main() {
    struct point p1, p2, p3, p4;
    cout << "Enter p1 p2 p3 and p4 coordinates: " << endl;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    
    if (intersect(p1, p2, p3, p4))
        cout << "P1P2 and P3P4 intersect." << endl;
    else
        cout << "P1P2 and P3P4 do not intersect." << endl;

    return 0;
}
