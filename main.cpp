#include <iostream>
#include "ListLinear.h"
#include "ListLinked.h"

using namespace std;

void Test_ListLinear();
void Test_ListLinked();
void DisplayInt(int x) {
	cout << x << '\t';
}
void DisplayChar(char x) {
	cout << x << '\t';
}

int main()
{
	cout << "Hello, world!" << "\n\n";
	Test_ListLinear();
	Test_ListLinked();
	return 0;
}

void Test_ListLinear() {
	ListLinear< int > mylist1;
	for (int i=1; i<=10; i++) {
		mylist1.insert(i - 1, i);
	}
	mylist1.traverse(DisplayInt);
	cout << '\n';
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
	cout << '\n';
	mylist2.replace(6, 'I');
	mylist2.replace(7, 'C');
	mylist2.traverse(DisplayChar);
	cout << "\n\n";
}

void Test_ListLinked() {
	ListLinked< int > mylist1;
	for (int i=1; i<=10; i++) {
		mylist1.append(i);
	}
	mylist1.traverse(DisplayInt);
	cout << '\n';
	int tmp1 = 0;
	mylist1.remove(6, tmp1);
	mylist1.traverse(DisplayInt);
	cout << tmp1 << "\n\n";

	ListLinked< char > mylist2;
	string str = "ELECTRON";
	for (unsigned i=0; i<str.length(); i++) {
		mylist2.append(str[i]);
	}
	mylist2.traverse(DisplayChar);
	cout << '\n';
	char tmp2 = '\0';
	mylist2.remove(6, tmp2);
	mylist2.replace(6, 'C');
	mylist2.insert(6, 'I');
	mylist2.traverse(DisplayChar);
	cout << tmp2 << "\n\n";
}
