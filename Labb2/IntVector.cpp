//Kasper Rosenberg - karo5568
#include "IntVector.h"
#include <iostream>
using namespace std;

//Tom konstruktor
IntVector::IntVector()
	: numberOfItems(),
	capacity(1),
	array(new int[capacity])
{

}

//Konstruktor f�r kopiering
IntVector::IntVector(const IntVector& otherVector)
	: numberOfItems(otherVector.numberOfItems),
	capacity(otherVector.capacity),
	array(new int[capacity])
{
	for (int i = 0; i < otherVector.size(); ++i) {
		array[i] = otherVector.array[i];
	}
}

//Konstrukor med lista av intar
IntVector::IntVector(const std::initializer_list<int>& list)
	: numberOfItems(0),
	capacity(list.size() + 5),
	array(new int[capacity])
{
	for (int i : list) {
		push_back(i);
	}
}

//Konstruktor f�r move
IntVector::IntVector(IntVector&& otherVector)
{
	numberOfItems = otherVector.numberOfItems;
	capacity = otherVector.capacity;
	array = otherVector.array;
	otherVector.numberOfItems = 0;
	otherVector.capacity = 0;
	otherVector.array = nullptr;
}


//Destruktor
IntVector::~IntVector() {
	delete[] array;
}


//Metod f�r att stoppa in (typ add i java)
void IntVector::push_back(int value) {
	if (numberOfItems < capacity) {
		array[numberOfItems] = value;
		++numberOfItems;
	}
	else {
		++capacity;
		int* tempArray = new int[capacity];
		for (int i = 0; i < numberOfItems; ++i) {
			tempArray[i] = array[i];
		}
		tempArray[numberOfItems] = value;
		++numberOfItems;
		delete[] array;
		array = tempArray;
	}
}

//Returnerar v�rdet p� ett visst index
int IntVector::operator[](const int index) const {
	if (index < 0 || index >= numberOfItems) {
		throw out_of_range("Index out of bounds");
	}
	return array[index];
}
//Returnerar v�rdet p� ett visst index
int& IntVector::operator[](int index)
{
	if (index < 0 || index >= numberOfItems) {
		throw out_of_range("Index out of bounds");
	}
	return array[index];
}

//Metod f�r att f� hur mycket som ligger i vectorn
int IntVector::size() const
{
	return numberOfItems;
}

//Metod f�r att f� vectorns kapactitet
int IntVector::getCapacity() const
{
	return capacity;
}

//Overloaded assignment operator
IntVector& IntVector::operator=(const IntVector& otherVector)
{
	//Kollar om dom tv� vectorerna �r samma
	if (this == &otherVector) {
		return *this;
	}
	//Kollar om othervector �r st�rre �n intvector och om den beh�ver g�ras st�rre
	if (otherVector.numberOfItems > numberOfItems) {
		delete[] array;
		capacity = otherVector.capacity;
		array = new int[capacity];
	}
	for (int i = 0; i < otherVector.size(); ++i) {
		array[i] = otherVector.array[i];
	}
	numberOfItems = otherVector.numberOfItems;
	return *this;

}

std::ostream& operator<<(std::ostream& ostr, const IntVector& otherVector)
{
	for (int i = 0; i < otherVector.numberOfItems; ++i) {
		ostr << otherVector.array[i] << " ";
	}
	ostr << std::endl;
	return ostr;
}
