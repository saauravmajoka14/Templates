#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Seg{
	const T ID = 0;
	vector<T> v;
	int n;
	T fun(int x, int y){ return x+y; } 

	void init(int _n){
		n = _n;
		v.assign(2*n, ID);
	}

	void update(int i, int x){
		v[i += n] = x;
		for(i /= 2; i; i /= 2) v[i] = fun(v[2*i], v[2*i + 1]);
	}

	T sum(int l, int r){
		l += n; r += n;
		T sum = ID;
		while(l <= r){
			if(l&1) sum = fun(sum, v[l++]);
			if(!(r&1)) sum = fun(sum, v[r--]);
			l /= 2; r /= 2; 
		}

		return sum;
	}

};


int main(){

}