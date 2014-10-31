#include <nan.h>
#include <iostream>
#include "engine.h"

//nw-gyp rebuild --target=0.11.0-rc1

using namespace v8;
using namespace std;

Engine engine;

NAN_METHOD(SayHi) {
	NanScope();
	engine.setPlayMode(args[0]->BooleanValue());
	NanReturnValue(NanNew("yooo"));
}

void Init(Handle<Object> exports) {
	exports->Set(NanNew("hello"), NanNew<FunctionTemplate>(SayHi)->GetFunction());
	cout << "sup boss\n";
}

NODE_MODULE(hello, Init)
