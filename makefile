output: Main.o EndGame.o Character.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o
	g++ Main.o EndGame.o Character.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

EndGame.o: ./run/EndGame.cpp ./run/EndGame.hpp
	g++ -c ./run/EndGame.cpp

Character.o: ./characters/Character.cpp ./characters/Character.hpp
	g++ -c ./characters/Character.cpp

Hawkeye.o: ./characters/Hawkeye.cpp ./characters/Hawkeye.hpp
	g++ -c ./characters/Hawkeye.cpp

HULK.o: ./characters/HULK.cpp ./characters/HULK.hpp
	g++ -c ./characters/HULK.cpp

Ironman.o: ./characters/Ironman.cpp ./characters/Ironman.hpp
	g++ -c ./characters/Ironman.cpp

Spiderman.o: ./characters/Spiderman.cpp ./characters/Spiderman.hpp
	g++ -c ./characters/Spiderman.cpp

Thanos.o: ./characters/Thanos.cpp ./characters/Thanos.hpp
	g++ -c ./characters/Thanos.cpp

Thor.o: ./characters/Thor.cpp ./characters/Thor.hpp
	g++ -c ./characters/Thor.cpp

Space.o: ./board/Space.cpp ./board/Space.hpp
	g++ -c ./board/Space.cpp

clean:
	rm *.o output
