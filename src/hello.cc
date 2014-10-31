#include <nan.h>
#include <iostream>
#include "engine.h"
// #include <fstream>

using namespace v8;
using namespace std;

NAN_METHOD(Method) {
	NanScope();
	// ifstream myReadFile;
	// myReadFile.open("foo.txt");
	// char output[100];
	// if (myReadFile.is_open()) {
	// 	while (!myReadFile.eof()) {
	// 		myReadFile >> output;
	// 		cout<<output;
	// 	}
	// }
	// myReadFile.close();
	// NanReturnValue(NanNew(output));
	NanReturnValue(NanNew("yooo"));
}

void Init(Handle<Object> exports) {
	exports->Set(NanNew("hello"), NanNew<FunctionTemplate>(Method)->GetFunction());
	Engine engine;
	cout << "sup boss\n";
}

NODE_MODULE(hello, Init)
