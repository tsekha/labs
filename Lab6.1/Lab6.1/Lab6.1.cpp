#include <iostream>
#include <string>

using namespace std;

struct Students {
	char FIO[100];
	int Age;
	int Kurs;
	char Pol[100];
	double Usp;
};

void vvodmass(int n, Students Obj[]) {
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cout << "ФИО: ";
		cin.getline(Obj[i].FIO, 100);
		cout << "Возраст: ";
		cin >> Obj[i].Age;
		cout << "Курс: ";
		cin >> Obj[i].Kurs;
		cout << "Пол: ";
		cin.ignore();
		cin.getline(Obj[i].Pol, 100);
		cout << "Успеваемость: ";
		cin >> Obj[i].Usp;
		cout << '\n';
	}
}

void vivodmass(int n, Students Obj[]) {
	system("cls");
	cout << "№\t" << "FIO\t" << "Age\t" << "Kurs\t" << "Pol\t" << "Uspevaemost'\t\t" << '\n';
	cout << "==================================================================" << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\t' << Obj[i].FIO << '\t' << Obj[i].Age
			<< '\t' << Obj[i].Kurs << '\t' << Obj[i].Pol << '\t'
			<< Obj[i].Usp << '\n';
	}
}

void FindStud(int n, int k, Students Obj[]) {
	double sr = 0;
	int kol = 0, kol1 = 0;
	for (int i = 0; i < n; i++) {
		if (Obj[i].Kurs == k) {
			sr = sr + Obj[i].Usp;
			kol1 += 1;
		}
	}
	if (kol1 != 0) {
		sr = sr / kol1;
	}
	for (int i = 0; i < n; i++) {
		if (Obj[i].Kurs == k && Obj[i].Usp > sr) {
			kol += 1;
		}
	}
	if (kol > 0) {
		cout << "Количество студентов с баллом выше чем средний балл по их курсу: " << kol << '\n';
	}
	else
	{
		cout << "Либо такого курса нет, либо я не знаю в чём прикол \n";
	}
}

int main() {

	setlocale(LC_ALL, "Ru");

	int n, kurs;

	cout << "Введите количество студентов: \n";
	cin >> n;

	Students* Student = new Students[n];

	vvodmass(n, Student);

	vivodmass(n, Student);

	cout << "Введите курс: \n";
	cin >> kurs;

	FindStud(n, kurs, Student);
	return 0;
}
