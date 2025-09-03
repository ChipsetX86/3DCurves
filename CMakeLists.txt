cmake_minimum_required(VERSION 3.16)

project(3DCurves LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(3DCurves
  main.cpp
  curve.h curve.cpp
  circle.h circle.cpp
  ellipse.h ellipse.cpp
  helixe.h helixe.cpp
  utils.h

)

include(GNUInstallDirs)
install(TARGETS 3DCurves
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
