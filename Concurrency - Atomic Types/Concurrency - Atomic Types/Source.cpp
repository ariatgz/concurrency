#include<atomic>
#include<iostream>
#include<thread>
#include<vector>


using namespace std;

//making this variable atomic makes the core wait for its oprations to finish 
//without any interruption. So it can be used without a mutex.
atomic<int> counter = 0;

void task() {


	for (int i = 0;i < 100'000;++i) {
		++counter;
	}


}

int main() {

	vector<thread> tasks;

	for (int i = 0;i < 10;++i) {
		
		tasks.push_back(thread(task));
	}

	for (auto& i : tasks) {
		i.join();
	}

	cout << counter << endl;

}