#include <iostream>
#include "ListLinear.h"
#include "ListLinked.h"

using namespace std;

void Test();
void DisplayInt(int x) {
	cout << x << '\t';
}
void DisplayChar(char x) {
	cout << x << '\t';
}

int main()
{
	cout << "Hello, world!" << "\n\n";
	Test();
	return 0;
}

void Test() {
	char kind = '\0';
	char type = '\0';
	char action = '\0';
	do {
		std::cout << "Creating List------------" << '\n';
		std::cout << "(linear: l; linked: k; exit: 0)?:";
		std::cin >> kind;
		if (kind != '0') {
			std::cout << "(int: i; double: d; char: c; string: s)?:";
			std::cin >> type;
		}
		switch (kind) {
			case 'l': {
				switch (type) {
					case 'i': {
						ListLinear< int > mylist;
						int entry = 0;
						int pos = 0;
						ErrListLinear errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINEAR_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINEAR_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 'd': {
						ListLinear< double > mylist;
						double entry = 0.0;
						int pos = 0;
						ErrListLinear errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINEAR_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINEAR_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 'c': {
						ListLinear< char > mylist;
						char entry = '\0';
						int pos = 0;
						ErrListLinear errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINEAR_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINEAR_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 's': {
						ListLinear< string > mylist;
						string entry = "";
						int pos = 0;
						ErrListLinear errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINEAR_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINEAR_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINEAR_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
				}
				break;
			}
			case 'k': {
				switch (type) {
					case 'i': {
						ListLinked< int > mylist;
						int entry = 0;
						int pos = 0;
						ErrListLinked errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINKED_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINKED_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									mylist.clear();
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 'd': {
						ListLinked< double > mylist;
						double entry = 0.0;
						int pos = 0;
						ErrListLinked errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINKED_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINKED_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									mylist.clear();
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 'c': {
						ListLinked< char > mylist;
						char entry = '\0';
						int pos = 0;
						ErrListLinked errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINKED_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINKED_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									mylist.clear();
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
					case 's': {
						ListLinked< string > mylist;
						string entry = "";
						int pos = 0;
						ErrListLinked errorcode;
						do {
							std::cout << "(insert: t; remove: r; display: d; clear: c; exit: 0)?:";
							std::cin >> action;
							switch (action) {
								case 't': {
									std::cout << " Insert position?:";
									std::cin >> pos;
									std::cout << " Insert data?:";
									std::cin >> entry;
									errorcode = mylist.insert(pos, entry);
									if (errorcode == LIST_LINKED_OVERFLOW) {
										std::cerr << " Data not inserted: OVERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not inserted: OUTOFRANGE" << '\n';
									}
									break;
								}
								case 'r': {
									std::cout << " Remove position?:";
									std::cin >> pos;
									errorcode = mylist.remove(pos, entry);
									if (errorcode == LIST_LINKED_UNDERFLOW) {
										std::cerr << " Data not removed: UNDERFLOW" << '\n';
									}else if (errorcode == LIST_LINKED_OUTOFRANGE) {
										std::cerr << " Data not removed: OUTOFRANGE" << '\n';
									}else {
										std::cout << " Removed data:" << entry << '\n';
									}
									break;
								}
								case 'd': {
									mylist.display();
									std::cout << " List displayed." << '\n';
									break;
								}
								case 'c': {
									mylist.clear();
									std::cout << " List cleared." << '\n';
									break;
								}
								case '0': {
									mylist.clear();
									std::cout << " Exited." << "\n\n";
									break;
								}
							}
						} while(action != '0');
						break;
					}
				}
			}
		}
	}while (kind != '0');
}
