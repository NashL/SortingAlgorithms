#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <time.h>

using namespace std;

bool is_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}

void mezclar(int *a, int n)
{
    for(int i=0; i < n; i++)
        swap(a[i],a[rand()% n]);
}

void stupidsort(int *a, int n)
{
  while ( !is_sorted(a, n) )    mezclar(a, n);
}

int RandomNumbers(){
    return rand()%100;
}

int main()
{
    srand(time(NULL));
    vector<int> vec(10);
    generate(vec.begin(),vec.end(),RandomNumbers);

    stupidsort(&vec[0], 10);

    ostream_iterator<int> oit(cout, " ");
    copy(vec.begin(), vec.end(), oit);

}
