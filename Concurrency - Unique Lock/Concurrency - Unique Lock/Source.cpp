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
			unique_lock<mutex> unqLck(print_mutex);
			//the unique lock can be unlocked by us or by its destructor
			// and it won't be unlocked twice.

			cout << s[0] << s[1] << s[2] << endl;

			unqLck.unlock();









		}
		catch (exception& e) {

			cout << e.what() << endl;

		}
	}
}


int main() {

	thread thr1(task, "abc");
	thread thr3(task, "def");
	thread thr2(task, "xyz");

	thr1.join();
	thr2.join();
	thr3.join();


}