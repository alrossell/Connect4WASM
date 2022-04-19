cd .. 
cd ./tests
g++ ConnectFourTests.cpp ../ConnectFour.cpp -o test.exe && ./test.exe
rm test.exe

g++ TransTableTests.cpp ../ConnectFour.cpp ../TransTable.cpp -o test.exe && ./test.exe
rm test.exe