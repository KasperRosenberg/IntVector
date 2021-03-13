//Kasper Rosenberg - karo5568
#include <iostream>
class IntVector {
public:
	//Kontrusktor
	IntVector();
	IntVector(const IntVector& otherVector);
	IntVector(const std::initializer_list<int>& list);
	IntVector(IntVector&& otherVector);

	//Destruktor
	~IntVector();

	//Metoder
	void push_back(int value);
	int size() const;
	int getCapacity() const;

	//
	int operator[](const int index) const;
	int& operator[](int index);
	IntVector& operator=(const IntVector& otherVector);

	friend std::ostream& operator <<(std::ostream& ostr, const IntVector& otherVector);

private:
	int numberOfItems;
	int capacity;
	int* array;
};
