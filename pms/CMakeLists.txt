set(source_list pms.cpp
        math/Vec.cpp
        group/Group.cpp
        group/Bicycle.cpp group/Van.cpp group/Motorbike.cpp
        management/ParkingLot.cpp management/TicketManager.cpp
        management/SlotManager.cpp management/GroupManager.cpp
        utils/Utils.cpp utils/Logger.cpp utils/CommonValue.cpp)

set(OpenGL_GL_PREFERENCE "GLVND")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})


# add executable
add_executable(pms ${source_list})

target_link_libraries(pms ${GLUT_LIBRARIES} ${OPENGL_LIBRARY})

# build static library pms
add_library(pms_static STATIC ${source_list})

add_executable(pms-asan ${source_list})
add_executable(pms-msan ${source_list})

set(CMAKE_CXX_COMPILER clang++)

target_compile_options(pms-asan PRIVATE -DNO_GUI -DDEBUG)
target_compile_options(pms-msan PRIVATE -DNO_GUI -DDEBUG)

target_compile_options(pms-asan PRIVATE -DDEBUG -g -fsanitize=address,leak,undefined,integer,bounds,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-sanitize-recover=all)
target_link_options(pms-asan PRIVATE -fsanitize=address)

target_compile_options(pms-msan PRIVATE -DDEBUG -g -fsanitize=memory -fno-omit-frame-pointer -fsanitize-memory-track-origins -fPIE)