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
	// 정렬 기준은 '점수가 작은 순서'
	bool operator <(Student &student) {
		return this-> score < student.score;
	}
};

bool compare(int a, int b) {
	return a < b;
}

int main_STL_Sort(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("허재원", 100),
		Student("제신희", 99)
	};
	sort(students, students + 3);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}





// main 안에 넣으면 됨!
//int a[10] = { 9, 3, 5, 4, 1, 10, 8 ,6 ,7 ,2, };
//sort(a, a + 10, compare);
//for (int i = 0; i < 10; i++) {
//	cout << a[i] << ' ';
//}