#src/ui/CMakeLists.txt
project( ui )
cmake_minimum_required( VERSION 2.8.11 )

find_package( Qt5Charts )
find_package( Qt5Widgets )
include_directories( ${RamerDouglasPeucker_SOURCE_DIR} )


set( ${PROJECT_NAME}_SRCS
  main.C
  PlotWindow.C
)


add_executable( ${CMAKE_PROJECT_NAME} ${${PROJECT_NAME}_SRCS} )
target_link_libraries( ${CMAKE_PROJECT_NAME} data Qt5::Charts Qt5::Widgets )

install( TARGETS ${CMAKE_PROJECT_NAME}
         RUNTIME
         DESTINATION bin
         COMPONENT executables
)


# Add tests
