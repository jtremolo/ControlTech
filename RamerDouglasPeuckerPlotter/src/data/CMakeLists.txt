#src/data/CMakeLists.txt
project( data )
cmake_minimum_required( VERSION 2.8.11 )

find_package( Qt5Core )


set( ${PROJECT_NAME}_SRCS
  PlotData.C
)


add_library( ${PROJECT_NAME} ${${PROJECT_NAME}_SRCS} )
target_link_libraries( ${PROJECT_NAME} Qt5::Core )


# Add tests
