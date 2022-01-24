output: Main.o EndGame.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o
	g++ Main.o EndGame.o Hawkeye.o HULK.o Ironman.o Space.o Spiderman.o Thanos.o Thor.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

EndGame.o: EndGame.cpp EndGame.hpp
	g++ -c EndGame.cpp

Hawkeye.o: Hawkeye.cpp Hawkeye.hpp
	g++ -c Hawkeye.cpp

HULK.o: HULK.cpp HULK.hpp
	g++ -c HULK.cpp

Ironman.o: Ironman.cpp Ironman.hpp
	g++ -c Ironman.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

Spiderman.o: Spiderman.cpp Spiderman.hpp
	g++ -c Spiderman.cpp

Thanos.o: Thanos.cpp Thanos.hpp
	g++ -c Thanos.cpp

Thor.o: Thor.cpp Thor.hpp
	g++ -c Thor.cpp

clean:
		rm *.o output
