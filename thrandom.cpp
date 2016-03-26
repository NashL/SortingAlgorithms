#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <sstream>
using namespace std;

mutex mtx;
long thread_id_to_long(const thread::id& tid) {
  long out;
  stringstream ss;
  ss << tid;
  ss >> l;
  return out;
}

void show_random(){
	mtx.lock();	
	//size_t random =this_thread::get_id().hash() 
	long n = thread_id_to_long(this_thread::get_id());
unsigned int nn = n;	
	cout << rand_r(&nn)%20 << endl;

	

	mtx.unlock();
}

int main(){

	thread th[4];
	
	for(int i=0; i<4; i++){
		th[i] = thread(show_random);
	}
	
	
	for(int i=0; i<4; i++){
		th[i].join();
	}
	
return 0;
}
