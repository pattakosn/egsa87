set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(PROJECT_SOURCES
	mainwindow.ui
        mainwindow.h
        mainwindow.cpp
        main.cpp
)
qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
set_target_properties(${PROJECT_NAME} PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)

add_executable(egsa87_test egsa87_test.cpp egsa87.cpp egsa87.h)
set_target_properties(egsa87_test PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
