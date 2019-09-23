#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance();

	void setValue(int val) { value_ = val; }
	int  getValue() { return(value_); }

protected:
	int value_;

private:
	static Singleton* inst_; //single instance 
	Singleton() : value_(0) {}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
};

Singleton* Singleton::inst_ = NULL;// Define the static Singleton pointer


Singleton* Singleton::getInstance() {
	if (inst_ == NULL) {
		inst_ = new Singleton();
	}
	return(inst_);
}

int main() {

	Singleton* pointer1 = Singleton::getInstance();

	pointer1->setValue(10);

	cout << "Value of pointer 1 = " << pointer1->getValue() << '\n';

	Singleton* pointer2 = Singleton::getInstance();

	cout << "Value of pointer 2 = " << pointer2->getValue() << '\n';

	system("pause");
}