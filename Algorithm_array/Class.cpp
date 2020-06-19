#include <stdio.h>
#include <string>


class Co {
public:
	int node;
	int distance[2];
	Co(int a, int b, int c) {
		node = a;
		distance[0] = b;
		distance[1] = c;
	}
};

struct Book 
{
	int number1;
	int number2;
	char title[100];
};

int main_class_g(void) {
	struct Book* p;
	p = (struct Book*)malloc(2 * sizeof(struct Book));
	p->number1 = 1;
	(p+1)->number1 = 2;
	strcpy_s(p->title, "gege");

	int array[3][5] = { { 1, 2, 3, 4, 5 }, // row 0 
		{ 6, 7, 8 }, // row 1 
		{ 11, 12, 13, 14, 15 } // row 2 };
	};
	Co Class_1[] = {
		Co(1, 2, 3),
		Co(2, 1, 3),
		Co(2, 3, 7),
		Co(3, 1, 6),
		Co(1, 3, 5)
	};
	for (int i = 0; i < sizeof(Class_1)/sizeof(*Class_1); i++) {
		if (Class_1[i].node == 1) {
			printf("%d \n", Class_1[i].distance[0]);
		};
	}
	//printf("%d \n", Class_1[1].distance[0]);
	//printf("%d", array[1][2]);
	
	return 0;
}