#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// ���� ������ '������ ���� ����'
	bool operator <(Student &student) {
		return this-> score < student.score;
	}
};

bool compare(int a, int b) {
	return a < b;
}

int main_STL_Sort(void) {
	Student students[] = {
		Student("������", 90),
		Student("�����", 100),
		Student("������", 99)
	};
	sort(students, students + 3);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}





// main �ȿ� ������ ��!
//int a[10] = { 9, 3, 5, 4, 1, 10, 8 ,6 ,7 ,2, };
//sort(a, a + 10, compare);
//for (int i = 0; i < 10; i++) {
//	cout << a[i] << ' ';
//}