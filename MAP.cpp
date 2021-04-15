// MAP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Map.h"
template <typename T>
class TestClass //template class for testing

{

public:
	TestClass() {};



	friend std:: ostream& operator << (std::ostream& cout, const TestClass& class_value)//creting operator to achive printing

	{

		cout << class_value.value;

		return cout;

	}
	TestClass(T value) {
		this->value = value;
	};

	bool operator ==(const TestClass<T>check){ // creaeting operator to achive equality checks
		return value == check.value;
	}
private:
	T value;
};
template <typename k, typename v>
void Test(k keys[], v values[]) {//exicutes code of the map
	int size = 5;
	Map<k, v> map = Map<k, v>(2);
	std::cout << "Adding first 2 elements" << std::endl;
	for (int i = 0; i < 2; i++) {
		map.Insert(keys[i], values[i]);
	}
	std::cout << "Printing the original map." << std::endl;
	map.print();
	std::cout<<std::endl;

	std::cout << "Add extra values and expand + same key alocation check" << std::endl;
	for (int i = 0; i < size; i++) {
		map.Insert(keys[i], values[i]);
	}
	map.print();
	std::cout << std::endl;

	std::cout << "Deleding data at iterator 3" << std::endl;
	map.Del(keys[3]);
	map.print();
	std::cout << std::endl;

	std::cout << "Replacing the value of key in iterator 2 " << std::endl;
	map.Replace(keys[2], keys[3], values[3]);
	map.print();
	std::cout << std::endl;

	std::cout << "Trying to replace an invalid key" << std::endl;
	map.Replace(keys[2], keys[2],values[2]);
	std::cout << std::endl;

	std::cout << "Replacing and returning the original value: " << map.Replace_And_Return(keys[3], keys[2], values[2]) << std::endl;
	std::cout << std::endl;

	std::cout << "printing the curent max size of the array: " ;
	map.Max_Size();
	std::cout << std::endl;
	
	std::cout << "Clearing and trying to print the array (shows nothing)" << std::endl;
	map.Clear();
	map.print();
	std::cout << std::endl;
	std::cout <<"repopulating the map from nothing" <<std::endl;
	for (int i = 0; i < size; i++) {
		map.Insert(keys[i], values[i]);
	}
	map.print();
	std::cout << std::endl;

	std ::cout << map.Get(keys[0]);

	system("pause");
	system("CLS");



}

void Run_Test(){
	//set some values for testing
	int valuesInt[5]{ 0,1,2,3,4 };
	char valuesChar[5]{ 'a','b','c','d','e' };
	std::string valuesString[5]{ "hi","lol","stef","NIK","dude" };
	float valuesFloat[5]{ 0.0f,0.1f,0.2f,0.3f,0.4f };
	bool valuesBool[5]{ true,false,true,false,true };
	double valuesDouble[5]{ 0.0,0.1,0.2,0.3,0.4 };
	TestClass<char> valuesClass[5]{ 'a','2',',','b','c' };

	//[int][all]
	Test(valuesInt, valuesInt);
	Test(valuesInt, valuesChar);
	Test(valuesInt, valuesString);
	Test(valuesInt, valuesFloat);
	Test(valuesInt, valuesBool);
	Test(valuesInt, valuesDouble);
	Test(valuesInt, valuesClass);
	
	//[char][all]
	Test(valuesChar, valuesInt);
	Test(valuesChar, valuesChar);
	Test(valuesChar, valuesString);
	Test(valuesChar, valuesFloat);
	Test(valuesChar, valuesBool);
	Test(valuesChar, valuesDouble);
	Test(valuesChar, valuesClass);
	
	//[String][all]
	Test(valuesString, valuesInt);
	Test(valuesString, valuesChar);
	Test(valuesString, valuesString);
	Test(valuesString, valuesFloat);
	Test(valuesString, valuesBool);
	Test(valuesString, valuesDouble);
	Test(valuesString, valuesClass);

	//[float][all]
	Test(valuesFloat, valuesInt);
	Test(valuesFloat, valuesChar);
	Test(valuesFloat, valuesString);
	Test(valuesFloat, valuesFloat);
	Test(valuesFloat, valuesBool);
	Test(valuesFloat, valuesDouble);
	Test(valuesFloat, valuesClass);
	
	//[Bool][all]
	Test(valuesBool, valuesInt);
	Test(valuesBool, valuesChar);
	Test(valuesBool, valuesString);
	Test(valuesBool, valuesFloat);
	Test(valuesBool, valuesBool);
	Test(valuesBool, valuesDouble);
	Test(valuesBool, valuesClass);

	//[Double] [all]
	Test(valuesDouble, valuesInt);
	Test(valuesDouble, valuesChar);
	Test(valuesDouble, valuesString);
	Test(valuesDouble, valuesFloat);
	Test(valuesDouble, valuesBool);
	Test(valuesDouble, valuesDouble);
	Test(valuesDouble, valuesClass);
	
	//[class][all]
	Test(valuesClass, valuesInt);
	Test(valuesClass, valuesChar);
	Test(valuesClass, valuesString);
	Test(valuesClass, valuesFloat);
	Test(valuesClass, valuesBool);
	Test(valuesClass, valuesDouble);
	Test(valuesClass, valuesClass);

}

int main()
{
	Run_Test();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file









