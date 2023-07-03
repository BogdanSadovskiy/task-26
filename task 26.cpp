using namespace std;
#include <iostream>
enum specs { KN, Informatic, ME, PI, TN };
struct students {
	string st_name;
	int st_year;
	specs spec;
	string spec_name;
	int math;
	int physic;
	string name_of_third;
	int third;


};
void viewstudents(students* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\n------------------- " << i + 1 << " --------------------\n";
		cout << "Name: " << arr[i].st_name << ";" << endl;
		cout << "Course: " << arr[i].st_year << ";" << endl;
		cout << "Specialization: " << arr[i].spec_name << ";" << endl;
		cout << "Marks:\n";
		cout << "Math - " << arr[i].math << "; ";
		cout << "Physic - " << arr[i].physic << "; ";
		cout << arr[i].name_of_third << " - " << arr[i].third << ";";
		cout << "\n------------------------------------------\n";
	}
	cout << endl;
}
void averforst(students* arr, int n) {
	cout << "\n--------------------------------------\n";
	cout << "Average mark for each student:\n";
	for (int i = 0; i < n; i++) {
		int mark = 0;
		mark = (arr[i].math + arr[i].physic + arr[i].third) / 3;
		cout << arr[i].st_name << " - " << mark << endl;
	}
	cout << "--------------------------------------\n";
}
void exmarkst(students* arr, int n) {
	cout << "\n--------------------------------------\n";
	cout << "Students with excellent marks\n";
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].math == 5 && arr[i].physic == 5 && arr[i].third == 5) {
			cout << arr[i].st_name << endl;
		}
	}
	cout << "--------------------------------------\n";
}
void percgoodex(students* arr, int n) {
	cout << "\n--------------------------------------\n";
	cout << "The percent of student with good and excellent marks - ";
	int st = 0;
	for (int i = 0; i < n; i++) {
		if ((arr[i].math == 5 || arr[i].math == 4) && (arr[i].physic == 5 || arr[i].physic == 4) && (arr[i].third == 5 || arr[i].third)) {
			st++;
		}
	}
	st = st * 100 / n;
	cout <<st << "%\n";
	cout << "--------------------------------------\n";
}
void physicst(students* arr, int n) {
	students* arr2 = new students[n];
	for (int i = 0; i < n; i++) {
		arr2[i].st_name = arr[i].st_name;
		arr2[i].physic = arr[i].physic;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr2[i].physic < arr2[j].physic) {
				int m = 0;
				string n;
				n = arr2[i].st_name;
				m = arr2[i].physic;
				arr2[i].st_name = arr2[j].st_name;
				arr2[i].physic = arr2[j].physic;
				arr2[j].st_name = n;
				arr2[j].physic = m;
				i--;
				break;
			}
		}
	}
	cout << "\n--------------------------------------\n";
	cout << "Physic best students:\n";
	for (int i = 0; i < n; i++) {
		cout << arr2[i].st_name << " - " << arr2[i].physic;
		if (i < n - 1) {
			cout << ";\n";
		}
		else {
			cout << ".\n";
		}
	}
	cout << "--------------------------------------\n";
}
void subavmark(students* arr, int n) {
	int math = 0;
	int physic = 0;
	int programm = 0, p = 0;
	int nummet = 0, num = 0;
	int Pedagogic = 0, ped = 0;
	for (int i = 0; i < n; i++) {
		math = math + arr[i].math;
		physic = physic + arr[i].physic;
		if (arr[i].name_of_third == "Programming") {
			programm += arr[i].third;
			p++;
		}
		if (arr[i].name_of_third == "Numbering methods") {
			nummet += arr[i].third;
			num++;
		}
		if (arr[i].name_of_third == "Pedagogic") {
			Pedagogic += arr[i].third;
			ped++;
		}
	}
	cout << "\n--------------------------------------\n";
	cout << "Each subject average mark:\n";
	cout << "Math - " << math / n << ";\n";
	cout << "Physic - " << physic / n << ";\n";
	cout << "Programming - ";
	if (p == 0) {
		cout << "non marks;\n";
	}
	else {
		cout << programm / p << ";\n";
	}

	cout << "Numbering methods - ";
	if (num == 0) {
		cout << "non marks;\n";
	}
	else {
		cout << nummet / num << ";\n";
	}
	cout << "Pedagogic - ";
	if (ped == 0) {
		cout << "non marks.\n";
	}
	else {
		cout << Pedagogic / ped << ".\n";
	}
	cout << "--------------------------------------\n";
}
void subexnum(students* arr, int n) {
	cout << "\n--------------------------------------\n";
	cout << "Number of excellent marks fo each subject:\n";
	int math = 0;
	int physic = 0;
	int programm = 0;
	int nummet = 0;
	int Pedagogic = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].math == 5) {
			math++;
		}
		if (arr[i].physic == 5) {
			physic++;
		}
		if (arr[i].name_of_third == "Programming") {
			if (arr[i].third == 5) {
				programm++;
			}
		}
		if (arr[i].name_of_third == "Numbering methods") {
			if (arr[i].third == 5) {
				nummet++;
			}
		}
		if (arr[i].name_of_third == "Pedagogic") {
			if (arr[i].third == 5) {
				Pedagogic++;
			}
		}
	}
	cout << "Math - " << math << ";\n";
	cout << "Physic - " << physic << ";\n";
	cout << "Programming - " << programm << ";\n";
	cout << "Numbering methods - " << nummet << ";\n";
	cout << "Pedagogic - " << Pedagogic << ".\n";
	cout << "--------------------------------------\n";
}
int main()
{
	int n;
	cout << "Input number of students  ";
	cin >> n;
	students* arr = new students[n];
	for (int i = 0; i < n; i++) {
		cout << "Input " << i+1 << " students name ";
		cin >> arr[i].st_name;
		year:
		cout << "Input number of study year (1 - 5) ";
		cin >> arr[i].st_year;
		if (arr[i].st_year < 1 || arr[i].st_year > 5) {
			cout << "Wrong inputting\n";
			goto year;
		}
		spec:
		cout << "Input specification (1 - KN, 2- Informatic, 3 - ME, 4 - PI, 5 - TN\n";
		int s; cin >> s;
		if (s < 1 || s>5) {
			cout << "Wrong inputting\n";
			goto spec;
		}
		arr[i].spec = (specs)s;
		if (arr[i].spec == 1) {
			arr[i].name_of_third = "Programming";
			arr[i].spec_name = "KN";
		}
		else if (arr[i].spec == 2) {
			arr[i].name_of_third = "Numbering methods";
			arr[i].spec_name = "Informatic";
		}
		else {
			arr[i].name_of_third = "Pedagogic";
			if (arr[i].spec == 3) {
				arr[i].spec_name = "ME";
			}
			else if (arr[i].spec == 4) {
				arr[i].spec_name = "PI";
			}
			else if (arr[i].spec == 5) {
				arr[i].spec_name = "TN";
			}
		}
		math:
		cout << "Math mark (1 - 5) - ";
		cin >> arr[i].math;
		if (arr[i].math < 1 || arr[i].math>5) {
			cout << "Wrong inputting\n";
			goto math;
		}
		physic:
		cout << "Physic mark (1 - 5) - ";
		cin >> arr[i].physic;
		if (arr[i].physic < 1 || arr[i].physic>5) {
			cout << "Wrong inputting\n";
			goto physic;
		}
		third:
		cout << arr[i].name_of_third << " mark (1 - 5) - ";
		cin >> arr[i].third;
		if (arr[i].third < 1 || arr[i].third>5) {
			cout << "Wrong inputting\n";
			goto third;
		}
		cout << "----------------------------------------------------------\n";
	}
	viewstudents(arr, n);
start:
	cout << "\nAverage mark for each student ------------------------ 1\n";
	cout << "Students with excellent marks ------------------------ 2\n";
	cout << "The percent of student with good and excellent marks - 3\n";
	cout << "Physic best students --------------------------------- 4\n";
	cout << "Each subject average mark ---------------------------- 5\n";
	cout << "Each subject number of excellent marks --------------- 6\n";
	cout << "Exit ------------------------------------------------- 0\n\n";
	char q; cin >> q;
	if (q == '1') {
		averforst(arr, n);
		goto start;
	}
	else if (q == '2') {
		exmarkst(arr, n);
		goto start;
	}
	else if (q == '3') {
		percgoodex(arr, n);
		goto start;
	}
	else if (q == '4') {
		physicst(arr, n);
		goto start;
	}
	else if (q == '5') {
		subavmark(arr, n);
		goto start;
	}
	else if (q == '6') {
		subexnum(arr, n);
		goto start;
	}
	else if (q == '0') {
		cout << "Goodbye\n";
		return 0;
	}
	else {
		cout << "Wrong inputting\n";
		goto start;
	}


}