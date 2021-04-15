#pragma once
#include<string>
template <typename k, typename v>
class Map
{
private:
	k* keys;
	v* values;
	int size;
	int Size_Iterator = 0;
public:
	Map(int size) {// creatinf the arrays
		keys = new k[size];
		values = new v[size];
		this->size = size;
	};


	void Insert(k key, v value) {//insert a new pair

		int iterator = 0;
		while (iterator < Size_Iterator)//checks for replication and return if true
		{
			if (keys[iterator] == key) {
				std::cout << "Key: "<< key << " already defined" << std::endl;
				return;

			}iterator++;
		}

		if (Size_Iterator == size) {// doubles the array size if full buy creating templed arrays and replacing old once



			int newSize = size * 2;

			k* temp_keys = new k[newSize];
			v* temp_values = new v[newSize];
			iterator = 0;
			while (iterator < size)
			{
				temp_keys[iterator] = keys[iterator];
				temp_values[iterator] = values[iterator];
				iterator++;
			}

			delete[] keys;
			keys = temp_keys;
			delete[] values;
			values = temp_values;
			size = newSize;
		}
		//sets values
		keys[Size_Iterator] = key;
		values[Size_Iterator] = value;
		Size_Iterator++;
	};


	v Get(k key) {//gets the value from key 
		int iterator = 0;
		while (iterator < Size_Iterator)
		{
			if (keys[iterator] == key) {
				return values[iterator];

			}iterator++;
		}
		std::cout << "key: " << key << " not found." << std::endl;
		return NULL;
	};


	void Replace(k key, k new_Key, v new_value) {// replaces the key
		int iterator = 0;
		while (iterator < Size_Iterator)
		{
			if (keys[iterator] == new_Key) {//key not found return
				std::cout << "Key: " << new_Key << " already defined" << std::endl;
				return;

			}iterator++;
		}

		 iterator = 0;
		while (iterator < Size_Iterator)
		{
			if (keys[iterator] == key) {

				values[iterator] = new_value;
				keys[iterator] = new_Key;
				return;

			}iterator++;
		}
		std::cout << "key: " << key << " not found." << std::endl;
		return;
	};


	v Replace_And_Return(k key, k new_Key, v new_value) {//replaces the key with the given key and print the value of the remoevd key
		int iterator = 0;
		while (iterator < Size_Iterator)//key not found returns null
		{
			if (keys[iterator] == new_Key) {
				std::cout << "Key: " << new_Key << " already defined" << std::endl;
				return NULL;

			}iterator++;
		}

		iterator = 0;
		v return_Value;
		while (iterator < Size_Iterator)
		{
			if (keys[iterator] == key) {
				return_Value = values[iterator];
				values[iterator] = new_value;
				keys[iterator] = new_Key;
				return return_Value;
			}iterator++;
		}
		std::cout << "key: " << key << " not found." << std::endl;
		return NULL;
	};


	void print() {//priting the arrays
		int iterator = 0;
		while (iterator < Size_Iterator)
		{
			std::cout << "Key: " << keys[iterator] << " Value: " << values[iterator] << std::endl;
			iterator++;
		}
	};

	void Clear() {//removes all the values form the array and reset the other values
		int newSize = 1;
		k* temp_keys = new k[newSize];
		v* temp_values = new v[newSize];

		delete[] keys;
		keys = temp_keys;
		delete[] values;
		values = temp_values;
		size = newSize;
		Size_Iterator = 0;
	};


	void Del(k key) {
		int iterator = 0;
		bool found = false;
		while (iterator < Size_Iterator)//check if the key is on the map
		{
			if (keys[iterator] == key) {
				found = true;
			}iterator++;
		}
		if (!found) {//if not found return
			std::cout << "Key: " << key << " not found" << std::endl;
			return;
		}

		//creatinf temporaty arays to replace the curent ones and roemoves the key and value given
		k* temp_keys = new k[size];
		v* temp_values = new v[size];

		iterator = 0;
		bool afterDel = false;
		while (iterator < size)
		{


			if (afterDel) {
				temp_keys[iterator - 1] = keys[iterator];
				temp_values[iterator - 1] = values[iterator];
				iterator++;

			}
			else {
				if (keys[iterator] == key) {
					afterDel = true;
				}
				else {
					temp_keys[iterator] = keys[iterator];
					temp_values[iterator] = values[iterator];

				}
				iterator++;
			}

		}

		delete[] keys;
		keys = temp_keys;
		delete[] values;
		values = temp_values;
		Size_Iterator = Size_Iterator - 1;
	};

	void Max_Size() {
		std::cout << size << std::endl;
	};

};