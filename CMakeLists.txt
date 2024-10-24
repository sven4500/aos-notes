cmake_minimum_required(VERSION 3.5)
project(ru.ivars.rozhleys.notes CXX)

find_package (Qt5 COMPONENTS Core Network Qml Gui Quick LinguistTools Sql Multimedia REQUIRED)

include(FindPkgConfig)
if (${PLATFORM_ID} STREQUAL "auroraos")
    pkg_search_module(AURORA auroraapp REQUIRED)
    pkg_search_module(AURORA auroraapp_i18n REQUIRED)
    set(PLATFORM_INCLUDE_DIRS ${AURORA_INCLUDE_DIRS})
    set(PLATFORM_LDFLAGS ${AURORA_LDFLAGS})
elseif (${PLATFORM_ID} STREQUAL "sailfishos")
    pkg_search_module(SAILFISH sailfishapp REQUIRED)
    set(PLATFORM_INCLUDE_DIRS ${SAILFISH_INCLUDE_DIRS})
    set(PLATFORM_LDFLAGS ${SAILFISH_LDFLAGS})
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(short_name notes)

set(SOURCES
    src/audiorecorder.cpp
    src/audiorecorder.h
    src/dao/databasedao.cpp
    src/dao/databasedao.h
    src/dto/audionote.h
    src/dto/databaseentry.h
    src/dto/sketchnote.h
    src/dto/textnote.h
    src/main.cpp
    src/models/audionotemodel.cpp
    src/models/audionotemodel.h
    src/models/sketchnotemodel.cpp
    src/models/sketchnotemodel.h
    src/models/textnotemodel.cpp
    src/models/textnotemodel.h
    src/qmlitems/sketchitem.cpp
    src/qmlitems/sketchitem.h
    src/viewmodels/audionoteviewmodel.cpp
    src/viewmodels/audionoteviewmodel.h
    src/viewmodels/listviewmodel.cpp
    src/viewmodels/listviewmodel.h
    src/viewmodels/noteviewmodel.cpp
    src/viewmodels/noteviewmodel.h
    src/viewmodels/sketchnoteviewmodel.cpp
    src/viewmodels/sketchnoteviewmodel.h
    src/viewmodels/textnoteviewmodel.cpp
    src/viewmodels/textnoteviewmodel.h
)

file(GLOB_RECURSE QmlFiles "qml/*.qml")
file(GLOB TsFiles "translations/*.ts")
set(SourceFiles ${SOURCES} ${QmlFiles})
qt5_create_translation(TRANSLATION_QM ${SourceFiles} ${TsFiles})
qt5_add_translation(QmFiles ${TsFiles})

set(CMAKE_SKIP_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/lib")

add_executable(${PROJECT_NAME} ${SOURCES} ${QmFiles})
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
    ${PLATFORM_ID}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:
    ${PLATFORM_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src
>)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Quick
    Qt5::Sql
    Qt5::Multimedia
    ${PLATFORM_LDFLAGS}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY qml
    DESTINATION share/${PROJECT_NAME}
)

foreach(_file IN LISTS QmFiles)
    get_filename_component(_filename "${_file}" NAME)
    string(REPLACE "${short_name}" "${PROJECT_NAME}" _full_filename "${_filename}")
    install(FILES ${_file} DESTINATION share/${PROJECT_NAME}/translations RENAME ${_full_filename})
endforeach()

set(IconSize 86x86 108x108 128x128 172x172)
foreach(_size IN LISTS IconSize)
    install(FILES icons/${_size}/${PROJECT_NAME}.png DESTINATION share/icons/hicolor/${_size}/apps)
endforeach()

install(FILES ${PROJECT_NAME}.desktop
    DESTINATION share/applications
)

# Get the other files reachable from the project tree in Qt Creator
file(GLOB_RECURSE IconFiles "icons" "*.png")
set(RESOURCE_FILES ${IconFiles})

file(GLOB_RECURSE QmlFiles "qml/*.qml")

add_custom_target(distfiles
    SOURCES
        ${PROJECT_NAME}.desktop
        rpm/${PROJECT_NAME}.spec
        rpm/${PROJECT_NAME}.changes.in
        rpm/${PROJECT_NAME}.changes.run.in
        ${QmlFiles}
        ${TsFiles}
        ${IconFiles})

file(WRITE "${CMAKE_BINARY_DIR}/QtCreatorDeployment.txt"
    "${CMAKE_INSTALL_PREFIX}
${CMAKE_BINARY_DIR}/${PROJECT_NAME}:bin
")
