#include<atomic>
#include<iostream>
#include<thread>
#include<chrono>
#include<vector>

using namespace std;
using namespace std::literals;


//this line creates the atomic bool and sets it to false;
//ATOMIC_FLAG_INIT makes the variable equal to false.
atomic_flag lock_out = ATOMIC_FLAG_INIT;

void task(int n) {

	//The test_set() function return the last value of atomic_flag
	// and sets it to true. So this loop acts as a mutex.
	// if the previous value false, we set it to true and then exceute the code
	// after the loop. meanwhile, no thread can execute the critical section
	// because the returned value will be true and loop will iterate until
	// a thread reassign the atomic bool to false.

	while (lock_out.test_and_set()) {};

	this_thread::sleep_for(500ms);
	cout << "Task manager #" << n << endl;
	// .clear() sets the bool to false, so the while loop can now be skipped.
	lock_out.clear();

	



}




int main() {


	vector<thread> threads;

	for (int i = 0;i < 10;i++) {

		threads.push_back(thread(task, i));

	}

	for (auto& i : threads) {
		i.join();
	}


}

