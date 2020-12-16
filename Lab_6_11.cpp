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
	void outFilm() { cout << "Название фильма: " << name << endl; }
};


class Animation : virtual public Film //вирутальное наследование 
{
protected:
	char* studio; // студия
	int sesion; // количество сезонов
public:
	Animation(char* NAME, char* STUDIO, int SESION) : Film(NAME), sesion(SESION)
	{
		studio = new char[strlen(STUDIO) + 1];
		strcpy_s(studio, strlen(STUDIO) + 1, STUDIO);
		cout << "Конструктор - Animation(D1)" << endl;
	}
	~Animation()
	{
		delete[] studio; ;
		cout << "Деструктор D1" << endl;
	}
	void outFilm()
	{
		//Cartoon::cartoon_prnt();
		cout << "Студия, выпустившая фильм: " << studio << endl; 
		cout << "Количество сезонов фильма: " << sesion << endl;
	}
};


class Nazv : virtual public Film //вирутальное наследование 
{
protected:
	int year; // год выпуска
	double count; // количество серий
public:
	Nazv(char* NAME, int YEAR, double COUNT) : Film(NAME), year(YEAR), count(COUNT)
	{
		cout << "Конструктор - Name(D2)" << endl;
	};
	~Nazv() { cout << "Деструктор D2" << endl; }

	void outFilm()
	{
		//Cartoon::cartoon_prnt();
		cout << "Год выпуска: " << year << endl;
		cout << "Количество серий: " << count << endl;
	}
};


class Art : public Animation, public Nazv
{
	char* art; // жанр
public: Art(char* NAZV, char* STUDIO, int SESION, int YEAR, double COUNT, char* ART) :
	Animation(NAZV, STUDIO, SESION), Nazv(NAZV, YEAR, COUNT), Film(NAZV)
{
	art = new char[strlen(ART) + 1];
	strcpy_s (art, strlen(ART) + 1, ART);
	cout << "Конструктор - Art(D12)" << endl;
}
	  ~Art()
	  {
		  delete[] art;
		  cout << "Деструктор D12" << endl;
	  }
};


int main()
{
	setlocale(LC_ALL, "Russian");
	char* nazv = new char[20];
	cout << "Введите название фильма " << endl;
	cin.getline(nazv, 50);

	char* col = new char[20];
	cout << "Введите студию" << endl;
	cin.getline(col, 50);

	char* art = new char[20];
	cout << "Введите жанр фильма: " << endl;
	cin.getline(art, 50);

	int seson = 0;
	cout << "Введите кол-во сезонов: " << endl;
	while (!(cin >> seson))
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


	Art cart(nazv, col, seson, god, coun, art); // объект класса Art
	Art* ptr = &cart; // указатель на созданный объект. Далее можно использовать для вызова методов либо сам объект cart, либо указатель на него pt
	cart.Film::outFilm();//вызов из базового класса
	cart.Animation::outFilm();//вызов из анимации
	cart.Nazv::outFilm();//вызов из названия
	system("pause"); //задержка выполнения
	return 0;
}