#include"Singleton.h"

using namespace std;

Singleton& get_singleton() {

	static Singleton single;
	return single;

}