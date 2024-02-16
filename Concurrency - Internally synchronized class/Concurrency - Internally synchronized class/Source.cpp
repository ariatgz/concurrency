#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

using namespace std;

class Vector {

	vector<int> vec;
	mutex the_mutex;

public:

	void push_back(const int& i) {

		the_mutex.lock();

		vec.push_back(i);

		the_mutex.unlock();


	}

	void print() {

		the_mutex.lock();

		for (auto i : vec) {
			cout << i << " , ";
		}

		the_mutex.unlock();

	}



};

void func(Vector& v) {

	for (int i = 0;i < 5;++i) {
		v.push_back(i);
		this_thread::sleep_for(50ms);
		v.print();
		

	}

}


int main() {

	Vector vec;

	 thread thr1(func, ref(vec));
	thread thr2(func, ref(vec));
	thread thr3(func, ref(vec));

	thr1.join();
	thr2.join();
	thr3.join();


}