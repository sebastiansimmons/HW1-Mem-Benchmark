//mem_benchmark.cc - Author: Sebastian Simmons
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <math.h>
#include <thread>
#include <cstring>
#include <sstream>

void test_buffer(int size){
	char * buffer = new char [size];
	//std::iostream stream (buffer,);
	std::istringstream input(buffer);
	auto start = std::chrono::high_resolution_clock::now(); 

	input.readsome(nullptr, size);
    
	auto stop = std::chrono::high_resolution_clock::now();
	auto t = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
	std::cout << size << "	" << t.count() << std::endl;
	return;
}


int main(int argc, char *argv[]){
	std::cout << "# Bytes    time" << std::endl;
	//test_buffer(1024);

	for(int i =10; i <= 26; i++){
		test_buffer(pow(2,i));
	}
	return 0;
}