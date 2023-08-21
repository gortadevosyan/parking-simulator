set(source_list ipa.cpp
        figure/Figure.cpp figure/ColoredFigure.cpp
        figure/Rectangle.cpp
        figure/Quadrilateral.cpp figure/Circle.cpp
        figure/Triangle.cpp figure/Line.cpp
        figure/SemiCircle.cpp figure/Trajectory.cpp
        group/Spacecraft.cpp group/Teleporter.cpp
        group/UFO.cpp group/Car.cpp group/Group.cpp
        management/ParkingLot.cpp management/PlotManager.cpp
        management/GroupManager.cpp management/SlotManager.cpp
        ../pms/utils/Utils.cpp figure/Line.cpp ../include/figure/Line.h ../include/figure/SemiCircle.h figure/SemiCircle.cpp)

set(test_list test/test.cpp)

# include OpenGL lib
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

# add executable
add_executable(ipa ${source_list} figure/Line.cpp ../include/figure/Line.h ../include/figure/SemiCircle.h figure/SemiCircle.cpp)

target_link_libraries(ipa ${GLUT_LIBRARIES} ${OPENGL_LIBRARY} pms_static)

#add_executable(test_ipa ${test_list})
#
#target_link_libraries(test_ipa pms_static)
#
add_executable(ipa-asan ${source_list})

target_link_libraries(ipa-asan pms_static)

set(CMAKE_CXX_COMPILER clang++)

target_compile_options(ipa-asan PRIVATE -DNO_GUI -DDEBUG)

target_compile_options(ipa-asan PRIVATE -DDEBUG -g -fsanitize=address,leak,undefined,integer,bounds,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-sanitize-recover=all)
target_link_options(ipa-asan PRIVATE -fsanitize=address)
