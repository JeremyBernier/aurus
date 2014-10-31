cmd_Release/obj.target/hello/engine.o := g++ '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/jeremy/.nw-gyp/0.11.0-rc1/src -I/home/jeremy/.nw-gyp/0.11.0-rc1/deps/uv/include -I/home/jeremy/.nw-gyp/0.11.0-rc1/deps/v8/include -I../node_modules/nan  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -ffunction-sections -fdata-sections -fno-tree-vrp -fno-tree-sink -fno-omit-frame-pointer -fno-rtti -fno-exceptions -MMD -MF ./Release/.deps/Release/obj.target/hello/engine.o.d.raw   -c -o Release/obj.target/hello/engine.o ../engine.cc
Release/obj.target/hello/engine.o: ../engine.cc ../engine.h
../engine.cc:
../engine.h:
