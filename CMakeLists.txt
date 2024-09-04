cmake_minimum_required(VERSION 3.12...3.28)

project(cairotest
  DESCRIPTION "Trying Cairo Lib"
  LANGUAGES CXX C
)


find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(X11 REQUIRED x11)

include_directories(${CAIRO_INCLUDE_DIRS} ${X11_INCLUDE_DIRS})

file(GLOB HEADER_FILES "*.h")

add_executable(cairotest test.cpp)

target_compile_options(cairotest
  INTERFACE
    ${CAIRO_CFLAGS} ${X11_CFLAGS}
)

target_link_libraries(cairotest ${CAIRO_LIBRARIES} ${X11_LIBRARIES})

target_sources(cairotest
  PRIVATE
  "window.cpp"
    ${HEADER_FILES}
)

add_compile_definitions(DEBUG)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
