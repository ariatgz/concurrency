#include<mutex>
#include<iostream>
#include<thread>
#include<string>
#include<chrono>

using namespace std;
using namespace std::literals;


mutex print_mutex;

void task(string s) {
	for (int i = 0;i < 5;++i) {
		try {
			lock_guard<mutex> lck(print_mutex);
			//the lock gaurd destructor will unlock the mutex.

			cout << s[0] << s[1] << s[2] << endl;

			throw exception();






		

	
	}
	catch (exception& e) {

		cout << e.what() << endl;

	}
}
}


int main() {

	thread thr1(task,"abc");
	thread thr3(task,"def");
	thread thr2(task,"xyz");

	thr1.join();
	thr2.join();
	thr3.join();


}