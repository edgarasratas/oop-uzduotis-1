cmake_minimum_required(VERSION 3.17)
project(main_vector)

set(CMAKE_CXX_STANDARD 14)

include_directories("C:/Users/Edgaras/source/repos/main_vector (1.0)/main_vector")

add_executable(${PROJECT_NAME}
		compareByLastName.cpp
		createDir.cpp
		nuskaitymasDeque.cpp
		nuskaitymasList.cpp
		nuskaitymasVector.cpp
		randomFileGenerator.cpp
		skaiciavimas.cpp
		sortLosersAndWinnersDeque
		sortLosersAndWinnersList
		sortLosersAndWinnersVector
		sortStudents
		strategyD
		strategyL
		strategyV
		main.cpp
		Funkcijos.h
		Header.h
		)