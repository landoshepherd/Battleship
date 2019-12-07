battleship: BS_Controller.o Game_Components.o BS_Utilities.o Vessel.o Player.o
	g++ -std=c++11 BS_Controller.o Game_Components.o BS_Utilities.o Vessel.o Player.o -o battleship

BS_Controller.o: BS_Controller.cpp
	g++ -c -std=c++11 BS_Controller.cpp

BS_Utilities.o: BS_Utilities.cpp BS_Utilities.hpp
	g++ -c -std=c++11 BS_Utilities.cpp

Vessel.o: Vessel.hpp
    g++ -c -std=c++11 Vessel.hpp

Game_Components.o: Game_Components.cpp Game_Components.hpp
    g++ -c -std=c++11 Game_Components.cpp

Player.o: Player.cpp Player.hpp
    g++ -c -std=c++11 Player.cpp

clean:
	rm *.o battleship
