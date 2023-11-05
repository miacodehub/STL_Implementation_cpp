#include <iostream>
#include <cassert> 

using namespace std;

template <typename T>
class Vect {
private:
	size_t mysize; 
	size_t mycapacity;
	T* mydata;
public:
	Vect() {
		mydata = nullptr;
		mysize = 0;
		mycapacity = 0;
	}
	Vect(size_t InitialCapacity) {
		mydata = new T[InitialCapacity];
		mysize = 0;
		mycapacity = InitialCapacity;
	}

	~Vect() {
		delete[] mydata;
	}

	int size() {
		return mysize;
	}

	int capacity() {
		return mycapacity;
	}
	int operator[](size_t index){ 
		if (index < 0 || index >= mysize) {
			return -1;
		}
		return mydata[index];
		
	}
	bool empty() {
		return mysize == 0;
	}

	void push_back(T value) {
		 if (mysize == mycapacity) {
        mycapacity = mycapacity == 0 ? 1 : mycapacity * 2;
        T* newdata = new T[mycapacity];
        for (int i = 0; i < mysize; i++) {
            newdata[i] = mydata[i];
        }
        delete[] mydata; // Deallocate old data
        mydata = newdata;
    }
    mydata[mysize] = value;
    mysize++;
	}


};



int main() {
	
	Vect<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back(i);
	}
	std::cout << nums.size() << std::endl; 
	for (int i = 0; i < 10; i++) {
		std::cout << nums[i] << std::endl;
	}
	return 0;
}


