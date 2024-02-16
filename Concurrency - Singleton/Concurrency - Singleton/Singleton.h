#ifndef SIGNLTON_H
#define SIGNLTON_H
#include<iostream>
class Singleton {

public:
	Singleton(Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;


	Singleton() { std::cout << "Creating the singletn instance" << std::endl; }




};

Singleton& get_singleton();


#endif
