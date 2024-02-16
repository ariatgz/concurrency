#include<iostream>
#include<thread>

using namespace std;

void sleepingFunc() {

	this_thread::sleep_for(3s);
	cout << "Hello after a 3 seconds pause." << endl;
	

}

void idThread() {

	auto id = this_thread::get_id();

	cout << "Thread id from inside the thread is " << id << endl;

}


int main() {

	thread thr1(sleepingFunc);
	thread thr2(idThread);

	cout << "The id is " << thr2.get_id() << endl;

	thr1.join();
	thr2.join();

	cout << "The id after executing is " << thr2.get_id() << endl;



}