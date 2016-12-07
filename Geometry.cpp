/** b. Подсчитывает общее количество вершин всех фигур,
 содержащихся в векторе (так, треугольник добавляет к общему числу 3, квадрат 4 и т.д.)

 c. Подсчитывает количество треугольников, квадратов и прямоугольников в векторе

 d. Удаляет все пятиугольники

 e. На основании этого вектора создает vector<Point>, который содержит
 координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент
 этого вектора содержит координаты одной из вершин первой фигуры,
 второй элемент этого вектора содержит координаты одной из вершину
 второй фигуры и т.д.

 f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом
 все квадраты, а потом прямоугольники.

 g. Распечатывает вектор после каждого этапа работы

*/

/**
 a. Заполняет вектор геометрическими фигурами.
 Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пятиугольником.
*/
#include "Geometry.h"
#include <cstdlib>

Geometry::Geometry(int size) {
    for(int i = 0; i < size; i++) {
        Shape shape = Shape();
        shape.vertex_num = rand() % 3 + 3;
        for(int j = 0; j < shape.vertex_num; j++) {
            Point point = Point();
            point.x = rand() % 10 + 1;
            point.y = rand() % 10 + 1;
            shape.vertexes.push_back(point);
        }
        shapes.push_back(shape);
    }
}

/**
 * Print Shapes with iterator
 */
void Geometry::printShapes() {
    ShapeVector::iterator i;
    int count = 1;
    for (i = shapes.begin(); i < shapes.end(); i++) {
        Shape shape = *i;
        string shapeName = "";
        switch(shape.vertex_num) {
            case 3: shapeName = "Triangle"; break;
            case 4: shapeName = "Square"; break;
            case 5: shapeName = "Pentagon"; break;
            default: shapeName = "Wrong shape"; break;
        }
        cout << count++ << "\t" << shapeName;
        vector<Point>::iterator it = shape.vertexes.begin();
        while (it != shape.vertexes.end()) {
            cout << " {" << (*it).x << "," << (*it).y << "}";
            it++;
        }
        cout << endl;
    }
}

/**
 * Print all shapes count
 */
void Geometry::countShapes() {
    ShapeVector::iterator i;
    int sum = 0;
    int triangles = 0;
    int squares = 0;
    int pentagons = 0;
    for (i = shapes.begin(); i < shapes.end(); i++) {
        sum += (*i).vertex_num;
        switch((*i).vertex_num) {
            case 3: triangles++; break;
            case 4: squares++; break;
            case 5: pentagons++; break;
        }
    }
    cout << "The total sum of points is " << sum << endl;
    cout << "Numbers of triangles: " << triangles << endl;
    cout << "Numbers of squares: " << squares << endl;
    cout << "Numbers of pentagons: " << pentagons << endl;
}

/**
 * Sorting: begining with triangles, then squares, and pentagones
 */
void Geometry::sortShapes() {
    ShapeVector::iterator i;
    ShapeVector triangles;
    ShapeVector squares;
    ShapeVector pentagons;
    for (i = shapes.begin(); i < shapes.end(); i++) {
        Shape shape = *i;
        switch(shape.vertex_num) {
            case 3: triangles.push_back(shape); break;
            case 4: squares.push_back(shape); break;
            case 5: pentagons.push_back(shape); break;
        }
    }
    shapes.clear();
    i = shapes.begin();
    if (triangles.size() != 0) {
        shapes.insert(i, triangles.begin(), triangles.end());
        i += triangles.size();
    }
    if (squares.size() != 0) {
        shapes.insert(i, squares.begin(), squares.end());
        i += squares.size();
    }
    if (pentagons.size() != 0) {
        shapes.insert(i, pentagons.begin(), pentagons.end());
        i += pentagons.size();
    }
    cout << "Shapes are sorted." << endl;
}

/**
 * Delete all shapes that are pentagones
 */
void Geometry::removeAllPentagons() {
    ShapeVector::iterator i = shapes.begin();
    while (i != shapes.end()) {
        if((*i).vertex_num == 5) {
            i = shapes.erase(i);
        } else {
            i++;
        }
    }
    cout << "All pentagons are removed." << endl;
}

/**
 * Creting vector with points
 */
void Geometry::createPointsVector() {
    vector<Point> points;
    ShapeVector::iterator i;
    int count = 0;
    cout << "List of one random point from each shape: " << endl;
    for (i = shapes.begin(); i < shapes.end(); i++) {
        Shape shape = *i;
        int random = rand() % shape.vertex_num;
        points.push_back((Point &&) shape.vertexes.at(random));
        cout << count+1 << "\t {" << points.at(count).x << "," << points.at(count).y << "}" << endl;
        count++;
    }
}
