cmake_minimum_required(VERSION 4.0)
project(smp_tp9_david_riana)

set(CMAKE_CXX_STANDARD 20)

add_executable(smp_tp9_david_riana main.cpp)
add_executable(exercice1 exercice1.cpp)
add_executable(exercice3 exercice3.cpp)
add_executable(exercice2 exercice2.cpp)
add_executable(exercice4 exercice4.cpp)
add_executable(calendar Calendrier.cpp Calendrier.h exercice5.cpp)
