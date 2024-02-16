#include<iostream>
#include<thread>
#include"Singleton.h"
#include<vector>

using namespace std;

void task1() {

	Singleton& single = get_singleton();
	cout << &single << endl;


}

int main() {

	vector<thread> threads;

	for (int i = 0;i < 10;++i) {
		threads.push_back(thread(task1));
	}

	for (auto& t : threads) {
		t.join();
	}


}