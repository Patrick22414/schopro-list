#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "ListNode.h"

enum ErrListLinked { LIST_LINKED_SUCCESS, LIST_LINKED_OVERFLOW, LIST_LINKED_UNDERFLOW, LIST_LINKED_OUTOFRANGE };

template< List_T >
class ListLinked
{
public:
	ListLinked();
	~ListLinked();
	void operator= (const ListLinked< List_T >& copy);
	int size() const;
	bool isempty() const;
	bool isfull() const;
	void clear();
	void traverse(void (*fun)(List_T));
	void display();
	ErrListLinked retrive(int pos, List_T& xdata) const;
	ErrListLinked replace(int pos, const List_T& xdata);
	ErrListLinked remove(int pos, List_T& xdata);
	ErrListLinked insert(int pos, const List_T& xdata);
private:
	int count;
	ListNode< List_T >* head;
	ListNode< List_T >* setPosition(int pos) const {
		ListNode< List_T >* ptr = head;
		for (int i=0; i<pos; i++) {
			ptr = ptr->next;
		}
		return ptr;
	}
};

#endif // LISTLINKED_H
