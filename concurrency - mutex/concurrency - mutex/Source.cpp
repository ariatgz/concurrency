#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

//The mutex will lock and task2 won't be able to lock it until task1 unlocks it.
//The two functions are called from different threads.

using namespace std;
using namespace std::literals;

mutex the_mutex;

void task1() {

	cout << "Task1 will attempt to lock the mutex" << endl;
	the_mutex.lock();
	cout << "Task1 locked the mutex." << endl;
	this_thread::sleep_for(2s);
	cout << "Task1 is unlocking the thread." << endl;
	the_mutex.unlock();


}

void task2() {

	this_thread::sleep_for(1s);
	cout << "Task2 trying to lock the mutex" << endl;
	while (!the_mutex.try_lock()) {

		cout << "Task2 could not lock the mutex." << endl;
		this_thread::sleep_for(500ms);
	}

	cout << "Task2 locked the mutex now." << endl;
	the_mutex.unlock();
}

int main() {

	thread thr1(task1);
	thread thr2(task2);

	thr1.join();
	thr2.join();


}