#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;
using namespace std::literals;

//You can call .lock() on recursive mutex multiple times without any error.
//Avoid using recursive mutex as much as possible.
recursive_mutex rmutex;

timed_mutex the_mutex;
// timed_mutex has two key functions: try_lock_for() or try_lock_until()
//These two functions will try to lock the mutex in the specified time.

mutex mut;

int bad_factorial(int n) {

	if (n <= 1) {

		cout << "Returning " << 1 << endl;
		return 1;
	}


	rmutex.lock();

	int retval = n * bad_factorial(n - 1);
	cout << "Returning " << retval << endl;

	rmutex.unlock();

	return retval;

}

void task1() {

	cout << "Task1 locking the mutex" << endl;
	unique_lock<timed_mutex> timedunqGaurd(the_mutex);
	cout << "Task1 locked the mutex" << endl;
	this_thread::sleep_for(6s);
	cout << "Task1 released the mutex" << endl;

}

void task2() {

	this_thread::sleep_for(500ms);
	cout << "Task2 trying to lock the mutex" << endl;

	unique_lock<timed_mutex> unique_mut(the_mutex, defer_lock);
	//defer lock will tell the unique mutex constructor to not to lock the
	// mutex right off the bat.

	while (!unique_mut.try_lock_for(1s)) {
		cout << "Task2 couldn't lock" << endl;
	}

	cout << "Task2 locked the mutex now" << endl;

	unique_mut.unlock();


}

int main() {

	/*thread factorialThread1(bad_factorial, 10);
	thread factorialThread2(bad_factorial, 11);

	factorialThread1.join();
	factorialThread2.join();*/

	thread thr1(task1);
	thread thr2(task2);

	thr1.join();
	thr2.join();



}