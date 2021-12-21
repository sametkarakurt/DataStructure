hepsi: derle calistir 

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp 
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp 
	g++ -I ./include/ -o ./lib/Nokta.o -c ./src/Nokta.cpp 
	g++ -I ./include/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./include/ -o ./lib/AVLNode.o -c ./src/AVLNode.cpp 
	g++ -I ./include/ -o ./bin/main ./lib/Node.o ./lib/DogruKuyrugu.o ./lib/Nokta.o ./lib/AVLNode.o ./lib/AVLTree.o ./src/main.cpp
	
bagla:
	g++ ./lib/main.o -o ./bin/main
calistir:
	./bin/main