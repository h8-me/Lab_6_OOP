#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>
using namespace std;

class Film
{
	char* name; // название фильма
public:
	Film(char* NAME)
	{
		name = new char[strlen(NAME) + 1];
		strcpy_s(name, strlen(NAME) + 1, NAME);
		cout << "Конструктор - Film" << endl;
	}
	~Film()
	{
		delete[] name;
		cout << "Деструктор А" << endl;
	}
	void outFilm() { cout << "Название: " << name << endl; }
};


class Discription : virtual public Film
{
protected:
	char* studio; // студия
	int sesion; // количество сезонов
public:
	Discription(char* NAME, char* STUDIO, int SESION) : Film(NAME), sesion(SESION)
	{
		studio = new char[strlen(STUDIO) + 1];
		strcpy_s(studio, strlen(STUDIO) + 1, STUDIO);
		cout << "Конструктор - Discription(D1)" << endl;
	}
	~Discription()
	{
		delete[] studio; ;
		cout << "Деструктор D1" << endl;
	}
	void outFilm()
	{
		//Cartoon::cartoon_prnt();
		cout << "Студия, выпустившая фильм: " << studio << " Количество сезонов фильма: " << sesion << endl;
	}
};


class Name : virtual public Film
{
protected:
	int year; // год выпуска
	double count; // количество серий
public:
	Name(char* NAME, int YEAR, double COUNT) : Film(NAME), year(YEAR), count(COUNT)
	{
		cout << "Конструктор - Name(D2)" << endl;
	};
	~Name() { cout << "Деструктор D2" << endl; }

	void outFilm()
	{
		//Cartoon::cartoon_prnt();
		cout << "Год выхода:  " << year << "Количество серий: " << count << endl;
	}
};


class Genre : public Discription, public Name
{
	char* genre; // жанр
public: Genre(char* NAME, char* STUDIO, int SESION, int YEAR, double COUNT, char* GENRE) :
	Discription(NAME, STUDIO, SESION), Name(NAME, YEAR, COUNT), Film(NAME)
{
	genre = new char[strlen(GENRE) + 1];
	strcpy_s(genre, strlen(GENRE) + 1, GENRE);
	cout << "Конструктор - Genre(D12)" << endl;
}
	  ~Genre()
	  {
		  delete[] genre;
		  cout << "Деструктор D12" << endl;
	  }
};


int main()
{
	setlocale(LC_ALL, "Russian");
	char* name = new char[20];
	cout << "Введите название " << endl;
	cin >> name;

	char* col = new char[20];
	cout << "Введите студию" << endl;
	cin >> col;


	char* nm = new char[20];
	cout << "Введите жанр фильма: " << endl;
	cin >> nm;

	int ses = 0;
	cout << "Введите кол-во сезонов: " << endl;
	while (!(cin >> ses))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}

	int god = 0;
	cout << "Введите год выпуска: " << endl;
	while (!(cin >> god))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}

	int coun = 0;
	cout << "Введите кол-во серий: " << endl;
	while (!(cin >> coun))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}


	Genre cart(name, col, ses, god, coun, nm); // объект класса Genre
	Genre* ptr = &cart; // указатель на созданный объект. Далее можно использовать для вызова методов либо сам объект cart, либо указатель на него pt
	cart.Film::outFilm();//выклік з базавай клясы
	cart.Discription::outFilm();//вызов из дескрипции 
	cart.Name::outFilm();//вызов из названия
	system("pause");
	return 0;
}