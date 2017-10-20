#include <iostream>
#include "ListLinear.h"

using namespace std;

void Test_ListLinear();
void DisplayInt(int x) {
	cout << x << '\n';
}
void DisplayChar(char x) {
	cout << x << '\n';
}

int main()
{
	cout << "Hello, world!" << "\n\n";
	Test_ListLinear();
	return 0;
}

void Test_ListLinear() {
	ListLinear< int > mylist1;
	for (int i=1; i<=10; i++) {
		mylist1.insert(i - 1, i);
	}
	mylist1.traverse(DisplayInt);
	int x = 0;
	mylist1.remove(6, x);
	mylist1.traverse(DisplayInt);
	cout << x << "\n\n";
	
	ListLinear< char > mylist2;
	string y = "ELECTRON";
	for (unsigned i=0; i<y.length(); i++) {
		mylist2.insert(i, y[i]);
	}
	mylist2.traverse(DisplayChar);
	cout << endl;
	mylist2.replace(6, 'I');
	mylist2.replace(7, 'C');
	mylist2.traverse(DisplayChar);
}
