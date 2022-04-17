cd ..

rm ../webapp/src/WASM/ConnectFourBinder.js
rm ../webapp/src/WASM/ConnectFourBinder.wasm


emcc -c ConnectFour.cpp -o ConnectFour.o
emcc -c TranspositionTable.cpp -o TranspositionTable.o
emcc -c MiniMax.cpp -o MiniMax.o
emcc -c ConnectFourBinder.cpp -o ConnectFourBinder.o

emcc -lembind ConnectFour.o TranspositionTable.o ConnectFourBinder.o ConnectFourBinder.o -o ConnectFourBinder.js -s WASM=1 -s MODULARIZE=1 

rm ConnectFour.o
rm ConnectFourBinder.o

rm -r build
mkdir build 

cp ConnectFourBinder.js build
cp ConnectFourBinder.wasm build

mv ConnectFourBinder.js ../webapp/src/WASM/
mv ConnectFourBinder.wasm ../webapp/src/WASM/

