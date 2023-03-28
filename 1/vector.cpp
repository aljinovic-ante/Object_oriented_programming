#include "vector.hpp"

void MyVector::vector_new (size_t sz)
{
	capacity = sz;
	size = 0;
	arr = new int[sz];

}
void MyVector::vector_delete()
{
	delete[] arr;
	arr = NULL;

}
void MyVector::vector_push_back(int n)
{
	if (size == 0 && capacity == 0)
	{
		size = 1;
		capacity = 1;

		arr = new int[capacity];

		arr[0] = n;
		std::cout << "prvi element: " << arr[0] << std::endl;


		return;
	}


	if (size != capacity)
	{
		size++;
		arr[size - 1] = n;
		//ovo je visak, ako zelite ispisat za provjeru, pozivajte gotovu funkciju
		for (int i = 0; i < size; i++) {
			std::cout << i + 1 << " element niza je: " << arr[i] << std::endl;
		}
		return;
	}

	int * new_arr = new int[capacity * 2];
	capacity = capacity * 2;

	for (int i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}

	size++;
	new_arr[size - 1] = n;

	//referenca od array sad pokazuje na new_arr
	//arr = new_arr;
	for (int i = 0; i < size; i++)
	{
		arr[i] = new_arr[i];
	}

	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << " element niza je: " << arr[i] << std::endl;
	}

	delete[] new_arr;
	new_arr = NULL;
}
void MyVector::vector_pop_back()
{
	if (size == 0)
	{
		return;
	}
	arr[size - 1] = 0;
	size--;
	
	if (capacity / size != 2)
	{
		
		return;
	}



	capacity = capacity / 2;
	int * new_arr = new int[capacity];
	for (int i = 0; i < size; i++) {
			new_arr[i] = arr[i];
	}

	//arr = new_arr;

	for (int i = 0; i < size; i++)
	{
		arr[i] =new_arr[i];
	}
	delete[] new_arr;
	new_arr = NULL;

	
	

}
int& MyVector::vector_front()
{
	return arr[0];
}
int& MyVector::vector_back()
{
	return arr[size - 1];
}
size_t MyVector::vector_size() 
{
	return size;
}


void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}