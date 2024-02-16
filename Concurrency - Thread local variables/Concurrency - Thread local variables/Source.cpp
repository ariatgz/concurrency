#include<thread>
#include<random>
#include<iostream>


using namespace std;

//when a variable is thread_local it means that each thread wll get their own 
// copy of the object.
thread_local mt19937 mt;

void task() {

	uniform_real_distribution<double> dist(0, 1);

	for (int i = 0;i < 10;++i) {
		cout << dist(mt) << endl;
	}


}

int main() {

	cout << "First thread generating \n";
	thread thr1(task);

	thr1.join();

	cout << "second thread generating \n";
	thread thr2(task);
	thr2.join();

}