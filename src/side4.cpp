#include <iostream>

class Base
{
public:
    Base()
    {
        print();
    }

    virtual ~Base()
    {
        print();
    }

    virtual void print() const
    {
        std::cout << "Base::print()" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        print();
    }

    ~Derived()
    {
        print();
    }

    // Невиртуальный метод print
    void print() const
    {
        std::cout << "Derived::print()" << std::endl;
    }
};

int main()
{
    // Выделение памяти на класс потомок по указателю на родительский класс
    Base *basePtr = new Derived();

    // Вызов метода принт
    basePtr->print(); // Вызовет Derived::print()

    delete basePtr; // Освобождение памяти

    return 0;
}
