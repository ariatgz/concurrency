#include<thread>
#include<iostream>

using namespace std;

void movefunc(string&& str) {

	cout << "The ownership of " << str << " has been moved to the thread" << endl;

}

void refFunc(string& str) {

	str = "rbz";
}


int main() {

	string Hell = "Hello world!";
	string str1 = "Reference";

	thread thr1(movefunc, std::move(Hell) );

	thread thr2(refFunc, std::ref(str1));

	thr1.join();
	thr2.join();

	cout << " str1 is now " << str1 << endl;
	cout << "Is the first string empty?" << (Hell.empty() ? "yes" : "No") << endl;


}