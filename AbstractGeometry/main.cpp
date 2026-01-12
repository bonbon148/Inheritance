#include<iostream>
using namespace std;

//Enumeration - enum
enum Color
{
	Red     = 0x000000FF,     //0x - Hexadecimal
	//bRED = 0000 0000    0000 0000   0000 0000   1111 1111
	Green   = 0x0000FF00,
	Blue    = 0x00FF0000,
	Yellow  = 0x0000FFFF,
	Purple  = 0x00800080
};

class Shape
{
	Color color;  //Цвет фигуры
public:
	Shape(Color color) :color(color) {}
	virtual ~Shape() {}
	virtual double get_area() const = 0;  //Pure virtual function
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;
	virtual void info() const
	{
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Плоащдь фигуры: " << get_perimeter() << endl;
		draw();
	}
};
class Square :public Shape
{
	double side;
public:
	Square(double side, Color color):Shape(color)
	{
		this->side = side; 
	}
	~Square() {}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_side()const
	{
		return side;
	}
    double get_area() const override
	{
		return side * side;
	}
	double get_perimeter() const override
	{
		return side * 4;
	}
	void draw() const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int i = 0; i < side; i++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	void info() const override
	{
		cout << typeid(*this).name() + 6 << endl;
		cout << "Длина стороны: " << get_side() << endl;;
		Shape::info();
	}
};


void main()
{
	setlocale(LC_ALL, "");
	//Shape shape = Color::Red;
	Square square(5, Color::Red);
	/*cout << "Сторона квадрата: " << square.get_side() << endl;
	cout << "Площадь фигурны: " << square.get_area() << endl;
	cout << "Периметр фигуры: " << square.get_perimeter() << endl;*/
	square.info();
}