#include"Header.hpp"

int main()
{
    MyString first("Vombat");
    MyString second("Pawuk");

    for (size_t i = 0; i < second.Size(); i++)
    {
        std::cout << second[i];
    }
    second[2] = 't';
    for (size_t i = 0; i < second.Size(); i++)
    {
        std::cout << second[i];
    }
    MyString result = first + second;


    //MyString result2 = first + "Spyder";
    //MyString result3 = "Pez" + second;
    //std::cout << res

    /*
    1 - реализовать Собственную реализацию динамического или статического массива
    
    2 - реализовать класс выше в виде шаблона класса
    
    3 - Реализовать класс Точка(2д геометрия) создать класс-коллекцию Линия, которая состоит из серии точек
    */
}

