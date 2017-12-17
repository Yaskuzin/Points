#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <map>
#include "Point.h"

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

vector<Point> initial(vector<Point> vector,int size){

    for(int i=0;i<size;i++){
        Point *point = new Point(fRand(-100, 100), fRand(-100, 100), fRand(-100, 100));
//        cout<< point->getX()<<"      "<<point->getY()<<"       "<<point->getZ()<<endl;
        vector.push_back(*point);

    }
    return vector;
}

Point getMinRangePoint(vector<Point>& vector,int size){

    sort(vector.begin(),vector.end());

    return vector[0];
}

Point  getPointsMinToAngle(vector<Point> vector,int size,double x,int y,double z){
    Point point = vector[size-1];
    double min = pow(pow((x-point.getX()),2)+pow((y-point.getY()),2)+pow((z-point.getZ()),2),1/2.);
    for(int i=size-1;i>=0;i--){
        double range = pow(pow((x-abs(vector[i].getX())),2)+pow((y-abs(vector[i].getY())),2)+pow((z-abs(vector[i].getZ())),2),1/2.);
        if(range<min){
            min = range;
            point = vector[i];
        }
    }
    return point;
}

int main() {
    srand ( time(NULL));
    int size = 50;
    vector<Point> vector;
    vector = initial(vector, size);
    for (auto it : vector) {
        cout << it<< endl;
    }
    Point minPoint = getMinRangePoint(vector, size);

    cout << endl;
    cout << minPoint << endl;
    cout << endl;
    for (auto it : vector) {
        cout << it << endl;
    }
    map<int, Point> map1;
    for (int i = 0; i < size; i++) {
        map1.insert(pair<int, Point>(i, vector[i]));
    }
    getPointsMinToAngle(vector, size, 100, 100, 100);

    cout << "  " << endl;
    cout <<"(100, 100, 100):  "<<getPointsMinToAngle(vector, size, 100, 100, 100)<< endl;
    cout <<"(100, 100, 100):  "<<getPointsMinToAngle(vector, size, 100, 100, 100)<< endl;
    cout <<"(100, -100, 100):  "<<getPointsMinToAngle(vector, size, 100, -100, 100)<< endl;
    cout <<"(100, -100, -100):  "<<getPointsMinToAngle(vector, size, 100, -100, -100)<< endl;
    cout <<"(-100, 100, 100):  "<<getPointsMinToAngle(vector, size, -100, 100, 100)<< endl;
    cout <<"(-100, 100, -100):  "<<getPointsMinToAngle(vector, size, -100, 100, -100)<< endl;
    cout <<"(-100, -100, 10):  "<<getPointsMinToAngle(vector, size, -100, -100, 100)<< endl;
    cout <<"(-100, -100, -100):  "<<getPointsMinToAngle(vector, size, -100, -100, -100)<< endl;


    return 0;
}


