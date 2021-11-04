hepsi: nesneler derle calistir

nesneler:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	
derle:
	g++ -I ./include/ -o ./bin/Test ./lib/Liste.o ./lib/Dugum.o ./src/Test.cpp
	
calistir:
	./bin/Test