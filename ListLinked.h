#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "ListNode.h"

enum ErrListLinked { LIST_LINKED_SUCCESS, LIST_LINKED_OVERFLOW, LIST_LINKED_UNDERFLOW, LIST_LINKED_OUTOFRANGE };

template< typename List_T >
class ListLinked
{
public:
	ListLinked();
	~ListLinked();
	void operator= (const ListLinked< List_T >& copy);
	int size() const;
	bool isempty() const;
	void clear();
	void clear(int lastpos);
	void traverse(void (*fun)(List_T));
	ErrListLinked retrive(int pos, List_T& xdata) const;
	ErrListLinked replace(int pos, const List_T& xdata);
	ErrListLinked remove(int pos, List_T& xdata);
	ErrListLinked append(const List_T& xdata);
	ErrListLinked insert(int pos, const List_T& xdata);
private:
	int count;
	ListNode< List_T >* head;
	ListNode< List_T >* tail;
	ListNode< List_T >* setPosition(int pos) const {
		ListNode< List_T >* ptr = head;
		for (int i=0; i<pos; i++) {
			ptr = ptr->next;
		}
		return ptr;
	}
};

template< typename List_T >
ListLinked< List_T >::ListLinked() {
	count = 0;
	head = tail = NULL;
}

template< typename List_T >
ListLinked< List_T >::~ListLinked() {
	this->clear();
}

template< typename List_T >
void ListLinked< List_T >::operator= (const ListLinked< List_T >& copy) {
	if (copy.size() >= count) {
		List_T copydata;
		for (int i=0; i<count; i++) {
			copy.retrive(i, copydata);
			this->replace(i, copydata);
		}
		for (int j=count; j<copy.size(); j++) {
			copy.retrive(j, copydata);
			this->append(copydata);
		}
	}else {
		List_T copydata;
		for (int i=0; i<copy.size(); i++) {
			copy.retrive(i, copydata);
			this->replace(i, copydata);
		}
		this->clear(copy.size() - 1);
	}
}

template< typename List_T >
int ListLinked< List_T >::size() const {
	return count;
}

template< typename List_T >
bool ListLinked< List_T >::isempty() const {
	return (count == 0);
}

template< typename List_T >
void ListLinked< List_T >::clear()
{
	ListNode< List_T >* moveptr = head;
	ListNode< List_T >* deleteptr = head;
	while (moveptr != NULL) {
		moveptr = moveptr->next;
		delete deleteptr;
		deleteptr = moveptr;
	}
	count = 0;
	head = tail = NULL;
}

template< typename List_T >
void ListLinked< List_T >::clear(int lastpos)
{
	if (lastpos < 0) {
		this->clear();
	}else if (lastpos < count) {
		tail = setPosition(lastpos);
		ListNode< List_T >* moveptr = tail->next;
		ListNode< List_T >* deleteptr = moveptr;
		while (moveptr != NULL) {
			moveptr = moveptr->next;
			delete deleteptr;
			deleteptr = moveptr;
		}
		count = lastpos + 1;
	}
}

template< typename List_T >
void ListLinked< List_T >::traverse(void (*fun)(List_T)) {
	ListNode< List_T >* ptr = head;
	while (ptr != NULL) {
		(*fun)(ptr->data);
		ptr = ptr->next;
	}
}

template< typename List_T >
ErrListLinked ListLinked< List_T >::retrive(int pos, List_T& xdata) const {
	if (pos < 0 || pos >= count) {
		return LIST_LINKED_OUTOFRANGE;
	}else {
		ListNode< List_T >* entryptr = setPosition(pos);
		xdata = entryptr->data;
	}
	return LIST_LINKED_SUCCESS;
}

template< typename List_T >
ErrListLinked ListLinked< List_T >::replace(int pos, const List_T& xdata) {
	if (pos < 0 || pos >= count) {
		return LIST_LINKED_OUTOFRANGE;
	}else {
		ListNode< List_T >* entryptr = setPosition(pos);
		entryptr->data = xdata;
	}
	return LIST_LINKED_SUCCESS;
}

template< typename List_T >
ErrListLinked ListLinked< List_T >::remove(int pos, List_T& xdata) {
	if (count == 0) {
		return LIST_LINKED_UNDERFLOW;
	}else if (pos < 0 || pos >= count) {
		return LIST_LINKED_OUTOFRANGE;
	}

	if (count == 1) {
		xdata = head->data;
		delete head;
		head = tail = NULL;
	}else if (pos == 0) {
		xdata = head->data;
		ListNode< List_T >* entryptr = head;
		head = head->next;
		delete entryptr;
	}else {
		ListNode< List_T >* previousptr = setPosition(pos - 1);
		ListNode< List_T >* entryptr = previousptr->next;
		xdata = entryptr->data;
		if (pos == (count - 1)) {
			tail = previousptr;
		}
		previousptr->next = entryptr->next;
		delete entryptr;
	}
	count --;
	return LIST_LINKED_SUCCESS;
}


template< typename List_T >
ErrListLinked ListLinked< List_T >::append(const List_T& xdata) {
	ListNode< List_T >* new_tail = new ListNode< List_T >(xdata);
	if (new_tail == NULL) {
		return LIST_LINKED_OVERFLOW;
	}else	if (count == 0) {
		tail = new_tail;
		head = new_tail;
	}else {
		tail->next = new_tail;
		tail = new_tail;
	}
	count ++;
	return LIST_LINKED_SUCCESS;
}

template< typename List_T >
ErrListLinked ListLinked< List_T >::insert(int pos, const List_T& xdata) {
	if (pos < 0 || pos > count) {
		return LIST_LINKED_OUTOFRANGE;
	}else if (pos == count) {
		return this->append(xdata);
	}else {
		ListNode< List_T >* entryptr = new ListNode< List_T >(xdata);
		if (pos == 0) {
			entryptr->next = head;
			head = entryptr;
		}else {
			ListNode< List_T >* previousptr = setPosition(pos - 1);
			entryptr->next = previousptr->next;
			previousptr->next = entryptr;
		}
		count ++;
	}
	return LIST_LINKED_SUCCESS;
}

#endif // LISTLINKED_H
