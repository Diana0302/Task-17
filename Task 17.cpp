#include <iostream>
#include <stdexcept>
class Shape {
public:
    virtual double Surface() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double a;

public:
    Circle(double r) {
            a = r;
            if (r <= 0) {
                throw std::invalid_argument("The radius can't be positive");
            }
        }
    double Surface()  override {
        return 3.14 * a * a;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
        if (l <= 0 || w <= 0) {
            throw std::invalid_argument("The sides of Rectangle can't be positive");
        }
    }

    double Surface()  override {
        return length * width;
    }
};

void print(Shape* ptr) {
    std::cout << "Area: " << ptr->Surface() << std::endl;
}

int main()
{
    int a;
    int b;
    int c;
    std::cout << "Enter the radius of Circle: ";
    std::cin >> a;
    std::cout << "Enter the Lenght of Rectangle: ";
    std::cin >> b;
    std::cout << "Enter the Wedth of Rectangle: ";
    std::cin >> c;
    try {
        Circle ob1(a);
        Rectangle ob2(b, c);
        Shape* ptr1 = &ob1;
        Shape* ptr2 = &ob2;
        print(ptr1);
        print(ptr2);
    }
    catch (std::exception& j) {

        std::cerr << "Exeption error" << j.what() << std::endl;
    }
    return 0;
}