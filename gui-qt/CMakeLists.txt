set(GUI_SOURCES
	mainwindow.ui
        mainwindow.h
        mainwindow.cpp
        main.cpp
)
qt_add_executable(${PROJECT_NAME} ${GUI_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets egsa87::egsa87)
set_target_properties(${PROJECT_NAME} PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)
