#include<iostream>
#include<thread>


using namespace std;

void func(thread&& thr) {

	cout << "Recieved a thread with id of " << thr.get_id() << endl;
	thr.join();

}

void printHello() {

	this_thread::sleep_for(3s);

	cout << "Hello World!" << endl;
}

void exceptionFunc() {
	//Erors should be caught in the same thread.

	try
	{
		throw exception();

	}
	catch (const std::exception& e)
	{

		cout << "Caught error " << e.what() << endl;

	}


}

//Thread is a move-only class.

int main() {

	thread thr(printHello);
	thread thr2(exceptionFunc);


	cout << "Hello thread has id of " << thr.get_id() << endl;

	thr2.join();
	func(move(thr));




}