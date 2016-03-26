#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <time.h>
#include <thread>
#include <mutex>
#include <random>
//Threads
using namespace std;

int NN = 8;
mutex mtx;
int cont = 0;

void gen_vec_rand(int *vec, int n){
    for(int i = 0; i < n ; i++){
        vec[i] = rand()% NN;
    }
}
int RandomNumbers_n(int n){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 100);
    return dist(mt);
}
int intRand(const int & min, const int & max) {
    static thread_local std::mt19937 generator;
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
bool is_sorted(int *a, int n){
    while ( --n >= 1 ) {
        if ( a[n] < a[n-1] ) return false;
    }
    return true;
}

void mezclar(int *a,int n_start , int n_part, int * vrand){

    for(int i=n_start; i <n_part ; i++){

        swap(a[i],a[vrand[i]]);
/*
        cout << "n_start = " << n_start << endl;
        cout << "n_part = " << n_part << endl;
        cout << "a[i] = " << a[i] << endl;
        cout << "a[rand_r(cont)%n] " << a[rand_r(n_part)%n] << endl;
        cout << "\n rand_r(n_part) " << intRand(1+n_part,1000+n_start) << " \n";
        cout << "\n rand() = " << rand() << " \n";
*/
    }
}

void launch_threads(int *vec, int n, int *vrand){
    int n_cores = thread::hardware_concurrency();
    int n_part = n / n_cores;
    thread th[n_cores];
    for(int i=0; i< n_cores; i++){
        th[i] = thread(mezclar , vec,i*n_part, n_part, &vrand[0]);
    }
    for(int i=0; i<n_cores; i++){
        th[i].join();
    }
}

void stupidsort(int *a, int n)
{
    srand(time(NULL));

    vector<int> vrand(NN);
    
  	while ( !is_sorted(a, n) ){
		gen_vec_rand(&vrand[0], NN);
		for(int i=0; i <vrand.size(); i++){
			cout << vrand[i] << " ";		
		}
		cout << endl;
	        launch_threads(a, n, &vrand[0]);
	}
}

int RandomNumbers(){
    return rand()%100;
}


int main()
{
    srand(time(0));
    vector<int> vec(8);
    generate(vec.begin(),vec.end(),RandomNumbers);
    ostream_iterator<int> oit(cout, " ");
    copy(vec.begin(), vec.end(), oit);

    stupidsort(&vec[0], 8);

    copy(vec.begin(), vec.end(), oit);
    cout << endl << "_______________________" << endl;
    /*for(int j=0; j < 5; j++){
        for(int i=0; i < 10; i++){
            cout << rand_r(0) % 100 << " ";
        }
        cout << endl;
    }
    */
}
