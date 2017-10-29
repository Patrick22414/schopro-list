#ifndef LIST_LINEAR_H
#define LIST_LINEAR_H

const int MAX_LIST_LINEAR = 100;
enum ErrListLinear { LIST_LINEAR_SUCCESS, LIST_LINEAR_OVERFLOW, LIST_LINEAR_UNDERFLOW, LIST_LINEAR_OUTOFRANGE };

template< typename List_T >
class ListLinear
{
public:
	ListLinear();
	int size() const;
	bool isempty() const;
	bool isfull() const;
	void clear();
	void traverse(void (*fun)(List_T));
	void display();
	ErrListLinear retrive(int pos, List_T& xdata) const;
	ErrListLinear replace(int pos, const List_T& xdata);
	ErrListLinear remove(int pos, List_T& xdata);
	ErrListLinear insert(int pos, const List_T& xdata);
private:
	int count;
	List_T data[MAX_LIST_LINEAR];
};

template< typename List_T >
ListLinear< List_T >::ListLinear()
{
	 count = 0;
}

template< typename List_T >
int ListLinear< List_T >::size() const
{
	return count;
}

template< typename List_T >
bool ListLinear< List_T >::isempty() const
{
	return (count == 0);
}

template< typename List_T >
bool ListLinear< List_T >::isfull() const
{
	return (count == MAX_LIST_LINEAR);
}

template< typename List_T >
void ListLinear< List_T >::clear()
{
	count = 0;
}

template< typename List_T >
void ListLinear< List_T >::traverse(void (*fun)(List_T))
{
	for (int i=0; i<count; i++) {
		(*fun)(data[i]);
	}
}

template< typename List_T >
ErrListLinear ListLinear< List_T >::retrive(int pos, List_T& xdata) const
{
	if (pos < 0 || pos > (count - 1)) {
		return LIST_LINEAR_OUTOFRANGE;
	}else {
		xdata = data[pos];
	}
	return LIST_LINEAR_SUCCESS;
}

template< typename List_T >
ErrListLinear ListLinear< List_T >::replace(int pos, const List_T& xdata)
{
	if (pos < 0 || pos > (count - 1)) {
		return LIST_LINEAR_OUTOFRANGE;
	}else {
		data[pos] = xdata;
	}
	return LIST_LINEAR_SUCCESS;
}

template< typename List_T >
ErrListLinear ListLinear< List_T >::remove(int pos, List_T& xdata)
{
	if (count == 0) {
		return LIST_LINEAR_UNDERFLOW;
	}else if (pos < 0 || pos > (count - 1)) {
		return LIST_LINEAR_OUTOFRANGE;
	}else {
		xdata = data[pos];
		for (int i=pos; i<count; i++){
			data[i] = data[i + 1];
		}
		count --;
	}
	return LIST_LINEAR_SUCCESS;
}

template< typename List_T >
ErrListLinear ListLinear< List_T >::insert(int pos, const List_T& xdata)
{
	//std::cout << xdata << '\n';
	if (count == MAX_LIST_LINEAR) {
		return LIST_LINEAR_OVERFLOW;
	}else if (pos < 0 || pos > count){
		return LIST_LINEAR_OUTOFRANGE;
	}else {
		for (int i=count; i>pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = xdata;
		count ++;
	}
	return LIST_LINEAR_SUCCESS;
}

template< typename List_T >
void ListLinear< List_T >::display()
{
	for (int i=0; i<count; i++) {
		std::cout << data[i] << '\t';
	}
	std::cout << '\n';
}

#endif // LIST_LINEAR_H
