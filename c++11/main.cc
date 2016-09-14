#include <iostream>
#include <memory>

using namespace std;

class X{
	public:
	~X() { std::cout << this << " delete..." << std::endl;}
	int a;
	int b;
};

int main() {
	shared_ptr<X> sp1(new X);
	// compare the following two conditions
	shared_ptr<int> sp2(sp1,&sp1->b); // this is the right useage
	//shared_ptr<X> sp2(sp1,new X);   // this 'new X' will not be deleted

	cout << "before sp1.reset()" << endl;
	cout << "sp1 use_count: " << sp1.use_count() << endl;
	cout << "sp2 use_count: " << sp2.use_count() << endl;

	cout << "sp1 get(): " << sp1.get() << endl;
	cout << "sp2 get(): " << sp2.get() << endl;
	
	cout << endl;
	sp1.reset();
	cout << "after sp1.reset()" << endl;

	cout << "sp1 use_count: " << sp1.use_count() << endl;
	cout << "sp2 use_count: " << sp2.use_count() << endl;

	cout << "sp1 get(): " << sp1.get() << endl;
	cout << "sp2 get(): " << sp2.get() << endl;
}
