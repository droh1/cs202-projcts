CXX = g++
CXXFLAGS = -Wall

proj4: Garden.o Plant.o Flower.o Vegetable.o Tree.o Fruit.o driver.o  
	$(CXX) $(CXXFLAGS) Garden.o Plant.o Flower.o Vegetable.o Tree.o Fruit.o driver.o  -o proj4

Garden.o: Garden.cpp Garden.h Vegetable.o Plant.o Tree.o Flower.o
	$(CXX) $(CXXFLAGS) -c Garden.cpp 

driver.o: driver.cpp driver.h Garden.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

Vegetable.o: Vegetable.cpp Vegetable.h Plant.o
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Flower.o: Flower.cpp Flower.h Plant.o
	$(CXX) $(CXXFLAGS) -c Flower.cpp

Plant.o: Plant.cpp Plant.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

Tree.o: Tree.cpp Tree.h Plant.o
	$(CXX) $(CXXFLAGS) -c Tree.cpp 

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

clean:
	rm *.o
	rm *~

run:
	./proj4
