output.out: driver.o Continent.o Country.o
	g++ -Wall -o driver.exe driver.o Continent.o Country.o
driver.o: driver.cpp Continent.h Country.h
	g++ -Wall -c driver.cpp
Continent.o: Continent.cpp Continent.h
	g++ -Wall -c Continent.cpp
Country.o: Country.cpp Country.h
	g++ -Wall -c Country.cpp

clean:
	rm *.o
	rm driver.exe

run:
	./driver.exe