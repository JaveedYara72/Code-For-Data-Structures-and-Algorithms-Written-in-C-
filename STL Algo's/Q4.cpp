#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
};
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}
float distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float smalldist(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);
        }
    }
    return min;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {
            if (dist(strip[i],strip[j]) < min)
                min = distance(strip[i], strip[j]);
        }
    }
    return min;
}

float closestUtil(Point Px[], Point Py[], int n)
{
    if (n <= 3)
        return smalldist(Px, n);
    int mid = n / 2;
    Point midPoint = Px[mid];
    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
    }
    return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closestUtil(Px, Py, n);
}

int main()
{
    int n;
    cout<<"Enter no of points"<<"\n";
    cin>>n;
       Point P[n];
    for(int i=0;i<n;i++)
    {
        cin>>P[i].x;
        cin>>P[i].y;
    }
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}
