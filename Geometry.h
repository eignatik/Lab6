#include <vector>
#include <iostream>

#ifndef LAB6_GEOMETRY_H
#define LAB6_GEOMETRY_H

using namespace std;

typedef struct {
    int x,y;
} Point;

typedef struct {
    int vertex_num;
    vector<Point> vertexes;
} Shape;

typedef vector<Shape> ShapeVector;

class Geometry {
private:
    ShapeVector shapes;
public:
    Geometry(int size);
    void printShapes();
    void countShapes();
    void removeAllPentagons();
    void createPointsVector();
    void sortShapes();
};


#endif //LAB6_GEOMETRY_H
