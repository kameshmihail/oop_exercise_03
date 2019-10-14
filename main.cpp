/*
Камеш М.А. группа М80-207Б - 18
Вариант 9 - Треугольник, Квадрат, прямоугольник
Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
1.   	Вычисление геометрического центра фигуры;
2.   	Вывод в стандартный поток вывода std::cout координат вершин фигуры; 3. Вычисление площади фигуры;

Создать программу, которая позволяет:
•       Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
•       Сохранять созданные фигуры в динамический массив std::vector<Figure*>
•   	Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
•       Необходимо уметь вычислять общую площадь фигур в массиве.
•       Удалять из массива фигуру по индексу;
*/
#include <bits/stdc++.h>
using namespace std;

class Figure
{
public:
    vector<double> Figure;
    double coordinate;
    double area(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2);
    }
    double area(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    {
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }
    vector<double> centroid(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        vector<double> myvector;
        myvector.push_back((x1 + x2 + x3) / 2);
        myvector.push_back((y1 + y2 + y3) / 2);
        return myvector;
    }
    vector<double> centroid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    {
        vector<double> myvector;
        myvector.push_back((x1 + x2 + x3 + x4) / 2);
        myvector.push_back((y1 + y2 + y3 + y4) / 2);
        return myvector;
    }
};

class Triangle : public Figure
{
public :
    double TriangleArea = 0;
};

class Square : public Figure
{
public :
    double SquareArea = 0;
};

class Rectangle : public Figure
{
public :
    double RectangleArea = 0;
};

int main()
{
    Triangle tri;
    Square sqr;
    Rectangle rec;
    int k = 1;
    while (k)
    {
        printf("===================================="
               "\n||              MENU              ||"
               "\n||--------------------------------||"
               "\n|| 0 - exit                       ||"
               "\n|| 1 - Add a triangle             ||"
               "\n|| 2 - Add a square               ||"
               "\n|| 3 - Add a rectangle            ||"
               "\n|| 4 - Delete a triangle          ||"
               "\n|| 5 - Delete a square            ||"
               "\n|| 6 - Delete a rectangle         ||"
               "\n|| 7 - Compute total area         ||"
               "\n===================================="
               "\n ==>");
        scanf("%d", &k);
        if (k == 1)
        {
            cout << "Enter three <x, y> coordinates for new triangle : " << endl;
            for (int i = 0; i < 6; i++)
            {
                cin >> tri.coordinate;
                tri.Figure.push_back(tri.coordinate);
            }
            vector<double> coord;
            cout << "Triangle area is : ";
            cout << tri.area(tri.Figure[tri.Figure.size()-6], tri.Figure[tri.Figure.size()-5],tri.Figure[tri.Figure.size()-4],tri.Figure[tri.Figure.size()-3],tri.Figure[tri.Figure.size()-2],tri.Figure[tri.Figure.size()-1]);
            tri.TriangleArea+=tri.area(tri.Figure[tri.Figure.size()-6], tri.Figure[tri.Figure.size()-5],tri.Figure[tri.Figure.size()-4],tri.Figure[tri.Figure.size()-3],tri.Figure[tri.Figure.size()-2],tri.Figure[tri.Figure.size()-1]);
            cout << endl;
            cout << "Triangle centrod is : ";
            coord = tri.centroid(tri.Figure[tri.Figure.size()-6], tri.Figure[tri.Figure.size()-5],tri.Figure[tri.Figure.size()-4],tri.Figure[tri.Figure.size()-3],tri.Figure[tri.Figure.size()-2],tri.Figure[tri.Figure.size()-1]);
            for (auto it = coord.begin(); it != coord.end(); it++)
                cout << *it << " ";
            cout << endl;
            cout << "<x1, y1> = " << tri.Figure[tri.Figure.size()-6] << "  " << tri.Figure[tri.Figure.size()- 5] << endl;
            cout << "<x2, y2> = " << tri.Figure[tri.Figure.size()-4] << "  " << tri.Figure[tri.Figure.size()- 3] << endl;
            cout << "<x3, y3> = " << tri.Figure[tri.Figure.size()-2] << "  " << tri.Figure[tri.Figure.size()- 1] << endl;
        }
        if (k == 2)
        {
            cout << "Enter four <x, y> coordinates for new square : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cin >> sqr.coordinate;
                sqr.Figure.push_back(sqr.coordinate);
            }
            vector<double> coord;
            cout << "Square area is : ";
            cout << sqr.area(sqr.Figure[sqr.Figure.size()-8], sqr.Figure[sqr.Figure.size()-7],sqr.Figure[sqr.Figure.size()-6],sqr.Figure[sqr.Figure.size()-5],sqr.Figure[sqr.Figure.size()-4],sqr.Figure[sqr.Figure.size()-3], sqr.Figure[sqr.Figure.size()-2], sqr.Figure[sqr.Figure.size()-1]);
            sqr.SquareArea+=sqr.area(sqr.Figure[sqr.Figure.size()-8], sqr.Figure[sqr.Figure.size()-7],sqr.Figure[sqr.Figure.size()-6],sqr.Figure[sqr.Figure.size()-5],sqr.Figure[sqr.Figure.size()-4],sqr.Figure[sqr.Figure.size()-3], sqr.Figure[sqr.Figure.size()-2], sqr.Figure[sqr.Figure.size()-1]);
            cout << endl;
            cout << "Square centroid is :";
            coord = sqr.centroid(sqr.Figure[sqr.Figure.size()-8], sqr.Figure[sqr.Figure.size()-7],sqr.Figure[sqr.Figure.size()-6],sqr.Figure[sqr.Figure.size()-5],sqr.Figure[sqr.Figure.size()-4],sqr.Figure[sqr.Figure.size()-3], sqr.Figure[sqr.Figure.size()-2], sqr.Figure[sqr.Figure.size()-1]);
            for (auto it = coord.begin(); it != coord.end(); it++)
                cout << *it << " ";
            cout << endl;
            cout << "<x1, y1> = " << sqr.Figure[sqr.Figure.size()-8] << "  " << sqr.Figure[sqr.Figure.size()- 7] << endl;
            cout << "<x2, y2> = " << sqr.Figure[sqr.Figure.size()-6] << "  " << sqr.Figure[sqr.Figure.size()- 5] << endl;
            cout << "<x3, y3> = " << sqr.Figure[sqr.Figure.size()-4] << "  " << sqr.Figure[sqr.Figure.size()- 3] << endl;
            cout << "<x4, y4> = " << sqr.Figure[sqr.Figure.size()-2] << "  " << sqr.Figure[sqr.Figure.size()- 1] << endl;
        }
        if (k == 3)
        {
            cout << "Enter four <x, y> coordinates for new rectangle : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cin >> rec.coordinate;
                rec.Figure.push_back(rec.coordinate);
            }
            vector<double> coord;
            cout << "Rectangle area is : ";
            cout << rec.area(rec.Figure[rec.Figure.size()-8], rec.Figure[rec.Figure.size()-7],rec.Figure[rec.Figure.size()-6],rec.Figure[rec.Figure.size()-5],rec.Figure[rec.Figure.size()-4],rec.Figure[rec.Figure.size()-3], rec.Figure[rec.Figure.size()-2], rec.Figure[rec.Figure.size()-1]);
            rec.RectangleArea+=rec.area(rec.Figure[rec.Figure.size()-8], rec.Figure[rec.Figure.size()-7],rec.Figure[rec.Figure.size()-6],rec.Figure[rec.Figure.size()-5],rec.Figure[rec.Figure.size()-4],rec.Figure[rec.Figure.size()-3], rec.Figure[rec.Figure.size()-2], rec.Figure[rec.Figure.size()-1]);
            cout << endl;
            cout << "Rectangle centroid is :";
            coord = rec.centroid(rec.Figure[rec.Figure.size()-8], rec.Figure[rec.Figure.size()-7],rec.Figure[rec.Figure.size()-6],rec.Figure[rec.Figure.size()-5],rec.Figure[rec.Figure.size()-4],rec.Figure[rec.Figure.size()-3], rec.Figure[rec.Figure.size()-2], rec.Figure[rec.Figure.size()-1]);
            for (auto it = coord.begin(); it != coord.end(); it++)
                cout << *it << " ";
            cout << endl;
            cout << "<x1, y1> = " << rec.Figure[rec.Figure.size()-8] << "  " << rec.Figure[rec.Figure.size()- 7] << endl;
            cout << "<x2, y2> = " << rec.Figure[rec.Figure.size()-6] << "  " << rec.Figure[rec.Figure.size()- 5] << endl;
            cout << "<x3, y3> = " << rec.Figure[rec.Figure.size()-4] << "  " << rec.Figure[rec.Figure.size()- 3] << endl;
            cout << "<x4, y4> = " << rec.Figure[rec.Figure.size()-2] << "  " << rec.Figure[rec.Figure.size()- 1] << endl;
        }
        if (k == 4)
        {
            int n;
            cout << "Enter the number of triangle you want to delete :";
            cin >> n;

            tri.TriangleArea-=tri.area(tri.Figure[6 * (n - 1)], tri.Figure[6 * (n - 1) + 1],tri.Figure[6 * (n - 1) + 2],tri.Figure[6 * (n - 1) + 3],tri.Figure[6 * (n - 1) + 4],tri.Figure[6 * (n - 1) + 5]);
            for (int i = 0; i < 6; i++)
            {
                tri.Figure.erase(tri.Figure.begin()+6*(n-1));
            }
            cout << "Triangle deleted, number of triangles left in vector :" << tri.Figure.size()/6 << endl;
        }
        if (k == 5)
        {
            int n;
            cout << "Enter the number of square you want to delete :";
            cin >> n;
            cout << sqr.Figure[8 * (n - 1)];
            cout << sqr.Figure[8 * (n - 1) + 1];
            cout << sqr.Figure[8 * (n - 1) + 2];
            sqr.SquareArea-=sqr.area(sqr.Figure[8 * (n - 1)], sqr.Figure[8 * (n - 1) + 1],sqr.Figure[8 * (n - 1) + 2],sqr.Figure[8 * (n - 1) + 3],sqr.Figure[8 * (n - 1) + 4],sqr.Figure[8 * (n - 1) + 5],sqr.Figure[8 * (n - 1) + 6],sqr.Figure[8 * (n - 1) + 7]);
            for (int i = 0; i < 8; i++)
            {
                sqr.Figure.erase(sqr.Figure.begin()+8*(n-1));
            }
            cout << "Square deleted, number of squares left in vector :" << sqr.Figure.size()/8 << endl;
        }
        if (k == 6)
        {
            int n;
            cout << "Enter the number of rectangle you want to delete :";
            cin >> n;
            rec.RectangleArea-=rec.area(rec.Figure[8 * (n - 1)], rec.Figure[8 * (n - 1) + 1],rec.Figure[8 * (n - 1) + 2],rec.Figure[8 * (n - 1) + 3],rec.Figure[8 * (n - 1) + 4],rec.Figure[8 * (n - 1) + 5],rec.Figure[8 * (n - 1) + 6],rec.Figure[8 * (n - 1) + 7]);
            for (int i = 0; i < 8; i++)
            {
                rec.Figure.erase(rec.Figure.begin()+8*(n-1));
            }
            cout << "Rectangle deleted, number of rectangles left in vector :" << rec.Figure.size()/8 << endl;
        }
        if (k == 7)
        {
            cout << "Total area is equal to : " << tri.TriangleArea + sqr.SquareArea + rec.RectangleArea << endl;
            cout << "Total area of triangles is : " << tri.TriangleArea << endl;
            cout << "Total area of squares is : " << sqr.SquareArea << endl;
            cout << "Total area of rectangles is : " << rec.RectangleArea << endl;
        }
        if (k == 0)
        {
            return 0;
        }
    }
    return 0;
}
