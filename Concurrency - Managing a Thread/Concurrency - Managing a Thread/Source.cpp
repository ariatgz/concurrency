#include<thread>
#include<iostream>
//The .detach() function makes the thread completely independent of the main thread.
using namespace std;

class thread_gaurd {

	thread thr;

public:

	explicit thread_gaurd(thread&& thr) : thr(move(thr)) {

	}

	~thread_gaurd() {

		if (thr.joinable()) { // joinable checks if the thread has already been joined or detached.
			thr.join();
		}

	}

	thread_gaurd(const thread_gaurd&) = delete;
	thread_gaurd& operator=(const thread_gaurd&) = delete;



};

void Hello() {

	cout << "Hello Thread!!" << endl;

}


int main() {

	try {

		
		thread thr(Hello);
		//thread gaurd class makes sure the join will be called on the thread 
		// before it's terminated. The deconstructor of the class will do that.
		thread_gaurd tgaurd{ move(thr) };

		throw exception();


	}
	catch(exception& e){

		cout << "Exception caught: " << e.what() << endl;
	}




}