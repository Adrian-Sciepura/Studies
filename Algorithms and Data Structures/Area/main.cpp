#include <iostream>
#include <cmath>

using std::cin, std::cout;

struct Vertex
{
    int x;
    int y;

    Vertex& operator=(const Vertex& vertex)
    {
        this->x = vertex.x;
        this->y = vertex.y;
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, Vertex& vertex)
    {
        cin >> vertex.x >> vertex.y;
        return in;
    }
};

double calculateArea(const Vertex& p1, const Vertex& p2, const Vertex& p3)
{
    return 0.5 * abs((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
}

int main()
{
    int number_of_polygons;
    int number_of_vertices;

    cin >> number_of_polygons;

    Vertex p1, p2, p3;

    for(int i = 0; i < number_of_polygons; i++)
    {
        cin >> number_of_vertices;

        if(number_of_vertices < 3)
        {
            cout << 0 << '\n';
            break;
        }

        double area = 0;
        cin >> p1;
        cin >> p2;
        cin >> p3;
    
        area += calculateArea(p1, p2, p3);

        for(int j = 3; j < number_of_vertices/2; j++)
        {
            p2 = p3;
            cin >> p3;
            area += calculateArea(p1, p2, p3);
        }

        cout << floor(area) << "\n";
    }

    return 0;
}