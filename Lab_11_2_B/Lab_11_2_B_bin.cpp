#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialty { КН, ІН, МЕ, ФН, ТН };

string specialtyStr[] = { "КН", "ІН", "МЕ", "ФН", "ТН" };

struct Student
{
	char prizv[64];
	int kurs;
	Specialty specialty;
	int physics;
	int mathematics;
	union
	{
		short unsigned programming;
		short unsigned NumericMethods;
		short unsigned pedagogy;
	};
};

void EnterSave(char* fname);
void LoadPrint(char* fname);
void CountMarks(char* fname, int& countPhysics, int& countMathematics, int& countprogramming, int& countNumericMethods, int& countpedagogy);
void MinAverage(char* fname, double& MinAve);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[61];
	char ch;
	double MinAve = 0.0;
	int countphysics = 0;
	int countmathematics = 0;
	int countprogramming = 0;
	int countNumericMethods = 0;
	int countpedagogy = 0;
	do
	{
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення та зберігання даних " << endl;
		cout << " [2] - завантаження та виведення даних" << endl;
		cout << " [3] - вивід найменшого середьного балу" << endl;
		cout << " [4] - вивід кількості 4 з кожного предмету" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> ch;
		cout << endl << endl << endl;
		switch (ch)
		{
		case '0':
			break;
			break;
		case '1':
			cin.get();
			cin.sync();
			cout << "Введіть ім'я файлу: "; cin.getline(fname, 61);
			EnterSave(fname);
			break;
		case '2':
			cin.get();
			cin.sync();
			cout << "Введіть ім'я файлу: "; cin.getline(fname, 61);
			LoadPrint(fname);
			break;
		case '3':
			MinAverage(fname, MinAve);
			cout << "Мінімальне середній бал: " << setprecision(2) << fixed << MinAve << endl;
			break;
			break;
		case '4':
			CountMarks(fname, countphysics, countmathematics, countprogramming, countNumericMethods, countpedagogy);
			cout << "Кількість 4 з фізики: " << countphysics << endl;
			cout << "Кількість 4 з математики: " << countmathematics << endl;
			cout << "Кількість 4 з програмування: " << countprogramming << endl;
			cout << "Кількість 4 з чисельних методів: " << countNumericMethods << endl;
			cout << "Кількість 4 з педагогіки: " << countpedagogy << endl;
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (ch != '0');

	system("pause");
	return 0;
}

void EnterSave(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Помилка зчитування файлу '" << fname << "'" << endl;
		return;
	}

	Student student;

	int specialty;
	char ch;
	int i = 0;
	do
	{
		cout << endl;
		cout << "Студент № " << i + 1 << ":" << endl;
		++i;
		cout << "Прізвище: ";
		cin >> student.prizv;
		cout << "Курс: "; cin >> student.kurs;
		cout << "Спеціальність (0 - КН, 1 - ІН, 2 - МЕ, 3 - ФН, 4 - ТН): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> student.physics;
		cout << "Оцінка з математики: "; cin >> student.mathematics;
		switch (student.specialty)
		{
		case КН:
			cout << "Оцінка з програмування : "; cin >> student.programming;
			break;
		case ІН:
			cout << "Оцінка з чисельних методів: "; cin >> student.NumericMethods;
			break;
		case МЕ:
			cout << "Оцінка з педагогіки: "; cin >> student.pedagogy;
			break;
		case ФН:
			cout << "Оцінка з педагогіки: "; cin >> student.pedagogy;
			break;
		case ТН:
			cout << "Оцінка з педагогіки: "; cin >> student.pedagogy;
			break;
		}
		cout << endl;
		if (!f.write((char*)&student, sizeof(Student)))
		{
			cerr << "Помилка запису файлу" << endl;
		}
		cout << "Продовжити? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}

void LoadPrint(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Помилка зчитування файлу '" << fname << "'" << endl;
		return;
	}

	Student student;
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;

	while (f.read((char*)&student, sizeof(Student)))
	{
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(9) << left << student.prizv
				 << "| " << setw(4) << left << student.kurs << " "
				 << "| " << setw(14) << left << specialtyStr[student.specialty]
				 << "| " << setw(6) << left << student.physics << " "
				 << "| " << setw(10) << left << student.mathematics << " ";
			switch (student.specialty)
			{
			case КН:
				cout << "| " << setw(13) << left
					 << student.programming << " |" << setw(18) << right << "|" << setw(13) << right << "|" << endl;
				break;
			case ІН:
				cout << "| " << setw(16) << right
					 << "| " << setw(16) << left << student.NumericMethods << "|" << setw(13) << right << "|" << endl;
				break;
			case МЕ:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << student.pedagogy << "|" << endl;
				break;
			case ФН:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << student.pedagogy << "|" << endl;
				break;
			case ТН:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << student.pedagogy << "|" << endl;
				break;
			}
			cout << "------------------------------------------------------------------------------------------------------------"
				<< endl;
			++i;
	}
}

void CountMarks(char* fname, int& countPhysics, int& countMathematics, int& countprogramming, int& countNumericMethods, int& countpedagogy)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Student student;

	countPhysics = 0;
	countMathematics = 0;
	countprogramming = 0;
	countNumericMethods = 0;
	countpedagogy = 0;

	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.physics == 4)
			countPhysics++;
		if (student.mathematics == 4)
			countMathematics++;
		switch (student.specialty)
		{
		case КН:
			if (student.programming == 4)
				countprogramming++;
			break;
		case ІН:
			if (student.NumericMethods == 4)
				countNumericMethods++;
			break;
		default:
			if (student.pedagogy == 4)
				countpedagogy++;
			break;
		}
	}
}

void MinAverage(char* fname, double& MinAve)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Помилка зчитування файлу '" << fname << "'" << endl;
		return;
	}

	Student student;

	while (f.read((char*)&student, sizeof(Student)))
	{
		double average = (student.physics + student.mathematics + student.programming) / 3.;
		MinAve = average;
		if (MinAve > average)
			MinAve = average;
	}
}