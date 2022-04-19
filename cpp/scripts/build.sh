cd ..

rm ../webapp/src/WASM/ConnectFourBinder.js
rm ../webapp/src/WASM/ConnectFourBinder.wasm

emcc -c ConnectFour.cpp -o ConnectFour.o
emcc -c TransTable.cpp -o TransTable.o
emcc -c MiniMax.cpp -o MiniMax.o
emcc -c ConnectFourBinder.cpp -o ConnectFourBinder.o

emcc -lembind ConnectFour.o TransTable.o MiniMax.o ConnectFourBinder.o -o ConnectFourBinder.js -s WASM=1 -s MODULARIZE=1 -s ALLOW_MEMORY_GROWTH=1

rm ConnectFour.o
rm ConnectFourBinder.o
rm MiniMax.o
rm TransTable.o

rm -r build
mkdir build 

cp ConnectFourBinder.js build
cp ConnectFourBinder.wasm build

mv ConnectFourBinder.js ../webapp/src/WASM/
mv ConnectFourBinder.wasm ../webapp/src/WASM/

