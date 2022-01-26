output: Main.o EndGame.o Character.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o
	g++ -g Main.o EndGame.o Character.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o -o output

Main.o: Main.cpp
	g++ -c -g Main.cpp

EndGame.o: ./run/EndGame.cpp ./run/EndGame.hpp
	g++ -c -g ./run/EndGame.cpp

Character.o: ./characters/Character.cpp ./characters/Character.hpp
	g++ -c -g ./characters/Character.cpp

Hawkeye.o: ./characters/Hawkeye.cpp ./characters/Hawkeye.hpp
	g++ -c -g ./characters/Hawkeye.cpp

HULK.o: ./characters/HULK.cpp ./characters/HULK.hpp
	g++ -c -g ./characters/HULK.cpp

Ironman.o: ./characters/Ironman.cpp ./characters/Ironman.hpp
	g++ -c -g ./characters/Ironman.cpp

Spiderman.o: ./characters/Spiderman.cpp ./characters/Spiderman.hpp
	g++ -c -g ./characters/Spiderman.cpp

Thanos.o: ./characters/Thanos.cpp ./characters/Thanos.hpp
	g++ -c -g ./characters/Thanos.cpp

Thor.o: ./characters/Thor.cpp ./characters/Thor.hpp
	g++ -c -g ./characters/Thor.cpp

Space.o: ./board/Space.cpp ./board/Space.hpp
	g++ -c -g ./board/Space.cpp

clean:
	rm *.o output
