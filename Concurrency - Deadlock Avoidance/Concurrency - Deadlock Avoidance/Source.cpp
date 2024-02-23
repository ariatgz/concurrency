#include<iostream>
#include<thread>
#include<mutex>


using namespace std;
using namespace std::literals;

mutex mut1;
mutex mut2;


void func1() {

	cout << "Thread A trying to lock 1 and 2 ..." << endl;

	lock(mut1, mut2);
	// the lock function can lock both mutexes at the same time.
	

	cout << "Thread A has locked thread 1 and 2 ..." << endl;
	
	//when unique lock is passed the adopt_lock the unique lock gets the
	// ownership of the mutex so it unlocks it at the end.
	unique_lock<mutex> uniq_lock(mut1, adopt_lock);
	unique_lock<mutex> uniq_lock(mut2, adopt_lock);

	cout << "Thread A has adopted the locks ..." << endl;

	this_thread::sleep_for(50ms);

	cout << "Thread A releasing mutexes 1 and 2" << endl;


}

void func2() {

	cout << "Thread B trying to lock 2 and 1 ..." << endl;

	lock(mut2, mut1);

	cout << "Thread B has locked thread 2 and 1 ..." << endl;

	unique_lock<mutex> uniq_lock(mut2, adopt_lock);
	unique_lock<mutex> uniq_lock(mut1, adopt_lock);

	cout << "Thread B has adopted the locks ..." << endl;

	this_thread::sleep_for(50ms);

	cout << "Thread B releasing mutexes 2 and 1" << endl;


}


int main() {

	thread thr1(func1);
	thread thr2(func2);
	thr1.join();
	thr2.join();


}