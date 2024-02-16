#include<thread>
#include<iostream>

using namespace std;


void PrintHello() {
	cout << "Hello" << endl;
} 

int main() {

	thread thr(PrintHello);


	thr.join(); //the parent thread (main) will wait for the child to execute.
	//The child could become a zombie thread if the maimn thread closes first.


}