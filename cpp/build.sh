rm Sample.js
rm Sample.wasm
emcc --bind SampleBindings.cpp Sample.cpp -s WASM=1 -s MODULARIZE=1 -o Sample.js
rm -r build
mkdir build 
mv Sample.js build
mv Sample.wasm build