//*******************************************************************************************************
//
//        File:				arrList2.h
//		  
//		  Student:			Minh Huynh
//
//		  Assignment:		Program #4
//
//		  Course Name:      Data Structures 1
//
//		  Course Number:    COSC 3050 - 01
//
//		  Due:		        Sept 23, 2016
//
//
//		  This program will dynamically allocate an array of a certain type and use member functions to
//		  interact with the array.
// 
//*******************************************************************************************************

#ifndef ARRLIST2_H
#define ARRLIST2_H

using namespace std;

//*******************************************************************************************************

template <typename TYPE>
class ArrList2
{
private:
	TYPE * list;
	int capacity;
	int numValues;
	bool _resize();
public:
	ArrList2(int = 5);
	~ArrList2();

	void display() const;
	bool insertBefore(const TYPE & dataIn, TYPE value);
	bool insertAfter(const TYPE & dataIn, TYPE value);
	bool insertBack(const TYPE & dataIn);
	bool insertFront(const TYPE & dataIn);
	bool insertAtIndex(const TYPE & dataIn, int index);

	bool retrieveAtIndex(TYPE & dataOut, int index);
	int getCapacity() const;
	int getNumValues() const;

	void shrinkToFit();
	void clearList();
	bool isEmpty() const;
	int find(const TYPE &dataOut);
};

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::_resize()
{
	bool success = false;
	int newCapacity;
	if(numValues == capacity)
	{
		newCapacity = (capacity + static_cast<int>(capacity * 0.5));	//increases capacity by 50%
		TYPE * newList = new TYPE[newCapacity];							//allocates new list as temp
		for(int i = 0; i < capacity; i++)								//moves values from old list to-
			newList[i] = list[i];										//new list
		delete list;													//deletes memory of old list
		list = newList;													//assigns ptr of new list to ptr-
		capacity = newCapacity;											//of old list
		success = true;
	}
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
ArrList2<TYPE>::ArrList2(int a)
{
	capacity = a;
	list = new TYPE[capacity];
	numValues = 0;
}

//*******************************************************************************************************

template <typename TYPE>
ArrList2<TYPE>::~ArrList2()
{
	delete list;
	capacity = 0;
	numValues = 0;
}

//*******************************************************************************************************

template <typename TYPE>
void ArrList2<TYPE>::display() const
{
	for(int i = 0; i < numValues; i++)
		cout << list[i] << " ";
	cout << endl;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::insertBefore(const TYPE &dataIn, TYPE value)
{
	bool success = false;								//return false if value cannot be found
	int index = find(value);							//returns index if value is found

	if(index > -1)
	{
		if(!success)									
		{
			if(index <= 0)								//if the index of the value is 0 or less
				success = false;						//return false
			else
			{
				if(numValues == capacity)				//check capacity vs numValues; increases capacity
					_resize();
				for(int j = numValues; j > index; j--)	//move values to the right
					list[j] = list[j - 1];							
				list[index] = dataIn;					//insert dataIn before the value
				numValues++;							//increase numValues
				success = true;							//return true
			}
		}
	}
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::insertAfter(const TYPE & dataIn, const TYPE value)
{
	bool success = false;
	int index = find(value);

	if(index > -1)
	{
		if(!success)									
		{
			if(index <= 0)
				success = false;
			else
			{
				if(numValues == capacity)
					_resize();
				for(int j = numValues; j > (index + 1); j--)	
					list[j] = list[j - 1];							
				list[index + 1] = dataIn;
				numValues++;
				success = true;
			}
		}
	}
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::insertBack(const TYPE & dataIn)
{
	bool success = true;
	if(numValues >= 0)
	{
		if(numValues == capacity)
			_resize();
		list[numValues] = dataIn;
		numValues++;
	}
	else
		list[0] = dataIn;
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::insertFront(const TYPE & dataIn)
{
	bool success = true;
	if(numValues >= 0)
	{
		if(numValues == capacity)
			_resize();
		for(int i = numValues; i > 0; i--)
			list[i] = list[i - 1];
		list[0] = dataIn;
		numValues++;
	}
	else
		list[0] = dataIn;
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::insertAtIndex(const TYPE & dataIn, int index)
{
	bool success = true;
	if(success)
	{
		if(numValues == capacity)
			_resize();
		for(int i = numValues; i > index; i--)
			list[i] = list[i - 1];
		list[index] = dataIn;
		numValues++;
	}
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::retrieveAtIndex(TYPE & dataOut, int index)
{
	bool success = false;
	if(index >= 0 && index < numValues)
	{
		dataOut = list[index];
		success = true;
	}
	return success;
}

//*******************************************************************************************************

template <typename TYPE>
int ArrList2<TYPE>::getCapacity() const
{
	return capacity;
}

//*******************************************************************************************************

template <typename TYPE>
int ArrList2<TYPE>::getNumValues() const
{
	return numValues;
}

//*******************************************************************************************************

template <typename TYPE>
void ArrList2<TYPE>::shrinkToFit()
{
	capacity = numValues;
}

//*******************************************************************************************************

template <typename TYPE>
void ArrList2<TYPE>::clearList()
{
	numValues = 0;
}

//*******************************************************************************************************

template <typename TYPE>
bool ArrList2<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*******************************************************************************************************

template <typename TYPE>
int ArrList2<TYPE>::find(const TYPE &dataOut)
{
	int index = -1;
	
	for(int i = 0; i < numValues; i++)
	{
		if(list[i] == dataOut)
			index = i;
	}
	return index;
}

//*******************************************************************************************************

#endif
