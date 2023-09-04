add_library(egsa87)
add_library(egsa87::egsa87 ALIAS egsa87)
target_sources(egsa87 PRIVATE egsa87.cpp PUBLIC egsa87.h)
target_include_directories(egsa87 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(egsa87_test egsa87_test.cpp)
target_link_libraries(egsa87_test PRIVATE egsa87::egsa87)
set_target_properties(egsa87_test PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
