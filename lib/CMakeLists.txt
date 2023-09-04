add_library(egsa87 egsa87.cpp egsa87.h)
add_library(egsa87::egsa87 ALIAS egsa87)

add_executable(egsa87_test egsa87_test.cpp)
target_link_libraries(egsa87_test egsa87::egsa87)
set_target_properties(egsa87_test PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
