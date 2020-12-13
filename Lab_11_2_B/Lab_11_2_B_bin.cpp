#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialty { ��, ��, ��, ��, �� };

string specialtyStr[] = { "��", "��", "��", "��", "��" };

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
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� �� ��������� ����� " << endl;
		cout << " [2] - ������������ �� ��������� �����" << endl;
		cout << " [3] - ���� ���������� ���������� ����" << endl;
		cout << " [4] - ���� ������� 4 � ������� ��������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> ch;
		cout << endl << endl << endl;
		switch (ch)
		{
		case '0':
			break;
			break;
		case '1':
			cin.get();
			cin.sync();
			cout << "������ ��'� �����: "; cin.getline(fname, 61);
			EnterSave(fname);
			break;
		case '2':
			cin.get();
			cin.sync();
			cout << "������ ��'� �����: "; cin.getline(fname, 61);
			LoadPrint(fname);
			break;
		case '3':
			MinAverage(fname, MinAve);
			cout << "̳������� ������� ���: " << setprecision(2) << fixed << MinAve << endl;
			break;
			break;
		case '4':
			CountMarks(fname, countphysics, countmathematics, countprogramming, countNumericMethods, countpedagogy);
			cout << "ʳ������ 4 � ������: " << countphysics << endl;
			cout << "ʳ������ 4 � ����������: " << countmathematics << endl;
			cout << "ʳ������ 4 � �������������: " << countprogramming << endl;
			cout << "ʳ������ 4 � ��������� ������: " << countNumericMethods << endl;
			cout << "ʳ������ 4 � ���������: " << countpedagogy << endl;
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
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
		cerr << "������� ���������� ����� '" << fname << "'" << endl;
		return;
	}

	Student student;

	int specialty;
	char ch;
	int i = 0;
	do
	{
		cout << endl;
		cout << "������� � " << i + 1 << ":" << endl;
		++i;
		cout << "�������: ";
		cin >> student.prizv;
		cout << "����: "; cin >> student.kurs;
		cout << "������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - ��): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << "������ � ������: "; cin >> student.physics;
		cout << "������ � ����������: "; cin >> student.mathematics;
		switch (student.specialty)
		{
		case ��:
			cout << "������ � ������������� : "; cin >> student.programming;
			break;
		case ��:
			cout << "������ � ��������� ������: "; cin >> student.NumericMethods;
			break;
		case ��:
			cout << "������ � ���������: "; cin >> student.pedagogy;
			break;
		case ��:
			cout << "������ � ���������: "; cin >> student.pedagogy;
			break;
		case ��:
			cout << "������ � ���������: "; cin >> student.pedagogy;
			break;
		}
		cout << endl;
		if (!f.write((char*)&student, sizeof(Student)))
		{
			cerr << "������� ������ �����" << endl;
		}
		cout << "����������? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}

void LoadPrint(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "������� ���������� ����� '" << fname << "'" << endl;
		return;
	}

	Student student;
	cout << "============================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |"
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
			case ��:
				cout << "| " << setw(13) << left
					 << student.programming << " |" << setw(18) << right << "|" << setw(13) << right << "|" << endl;
				break;
			case ��:
				cout << "| " << setw(16) << right
					 << "| " << setw(16) << left << student.NumericMethods << "|" << setw(13) << right << "|" << endl;
				break;
			case ��:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << student.pedagogy << "|" << endl;
				break;
			case ��:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << student.pedagogy << "|" << endl;
				break;
			case ��:
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
		case ��:
			if (student.programming == 4)
				countprogramming++;
			break;
		case ��:
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
		cerr << "������� ���������� ����� '" << fname << "'" << endl;
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