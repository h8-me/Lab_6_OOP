
#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>

using namespace std;

class Movie
{
    char* name; //название фильма
public:
    Movie (char* NAME)
    {
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);
        cout << "Конструктор - Movie" << endl;
    }
    ~Movie()
    {
        delete[] name;
        cout << "Деструктор класса А" << endl;
    }
    virtual void movie_prnt() { cout << "Название фильма: " << name << endl; }
};


class Discription : virtual public Movie
{
protected:
    char* studio; // название фильма студии
    int  sesion; // количество сезонов
public:
    Discription(char* NAME, char* STUDIO, int SESION) : Movie (NAME), sesion(SESION)
    {
        studio = new char[strlen(STUDIO) + 1];
        strcpy_s(studio, strlen(STUDIO) + 1, STUDIO);
        cout << "Конструктор - Discription(D1)" << endl;
    }
    ~Discription()
    {
        delete[] studio; ;
        cout << "деструктор класса D1" << endl;
    }
    void desc_prnt()
    {
        cout << "Производитель фильма (киностудия): " << studio << endl;
        cout << "Cезоны фильма: " << sesion << endl;
    }
};


class Name : virtual public Movie
{
protected:
    int year; // год выпуска
    double  count; // кол-во серий
public:
    Name(char* NAME, int YEAR, double COUNT) : Movie (NAME), year(YEAR), count(COUNT)
    {
        cout << "Конструктор - Name(D2)" << endl;
    };
    ~Name() { cout << "деструктор класса D2" << endl; }
    void name_prnt()
    {
        cout << "Год создания фильма: " << year << endl;
        cout << "Количество серий: " << count << endl;
    }
};


class Genre : public Discription, public Name
{
    char* genre; // название жанра
public: Genre(char* NAME, char* STUDIO, int SESION, int YEAR, double COUNT, char* GENRE) :
    Discription(NAME, STUDIO, SESION), Name(NAME, YEAR, COUNT), Movie (NAME)
{
    genre = new char[strlen(GENRE) + 1];
    strcpy_s(genre, strlen(GENRE) + 1, GENRE);
    cout << "Конструктор - Genre(D12)" << endl;
}
      ~Genre()
      {
          delete[] genre;
          cout << "деструктор класса D12" << endl;
      }
      void genre_prnt()
      {
          cout << "Жанр фильма " << genre << endl;
      }
};
int main()
{
    setlocale(0, "");
    char* name = new char[20];
    cout << "Введите название фильма: " << endl;
    cin.getline(name, 50);

    char* col = new char[20];
    cout << "Введите производителя (киностудию): " << endl;
    cin.getline(col, 50);


    char* nm = new char[20];
    cout << "Введите жанр фильма: " << endl;
    cin.getline(nm, 50);

    int ses = 0;
    cout << "Введите количествово сезонов фильма: " << endl;
    while (!(cin >> ses))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }

    int god = 0;
    cout << "Введите год создания фильма: " << endl;
    while (!(cin >> god))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }

    int coun = 0;
    cout << "Введите количество серий: " << endl;
    while (!(cin >> coun))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }

    Genre cart(name, col, ses, god, coun, nm); // объект класса Genre
    Genre* pt = &cart; // указатель на созданный объект. Далее можно использовать для вызова методов либо сам объект cart, либо указатель на него pt 
    pt->movie_prnt();
    pt->name_prnt();
    pt->desc_prnt();
    pt->genre_prnt();
    system("pause");
    return 0;
}
