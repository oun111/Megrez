/* =====================================================================
Copyright 2017 The Megrez Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
========================================================================*/

#include "./IDLs/benchmark.pb.h"
#include <iostream>
#include <chrono>

using namespace benchmark;
using namespace std;
using namespace chrono;

void serialize() {
	Person person;
	person.set_id(123456);
	person.set_name("NAME");
	person.set_age(100);
	person.set_gender(MALE);
}

int main() {
	cout << "Megrez Benchmark" << endl;
	auto start = system_clock::now();
	for (int i=1; i<=10000; i++)
		serialize();
	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "Serialization time: " 
		 << double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den 
		 << "(nanoseconds).\n";

	cin.get();
	cin.get();
	return 0;
}