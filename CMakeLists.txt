cmake_minimum_required(VERSION 3.5)
project(ASPA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)






set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        img.qrc
        loginuser.h
        loginuser.cpp
        loginuser.ui
        register.h
        register.cpp
        register.ui
        adminlogin.h
        adminlogin.cpp
        adminlogin.ui
        usermenu.h
        usermenu.cpp
        usermenu.ui
        iuser.h
        iuser.cpp
        userclient.h
        userclient.cpp
        useradmin.h
        useradmin.cpp
        filteradopt.h
        filteradopt.cpp
        filteradopt.ui
        adoptsearch.h
        adoptsearch.cpp
        adoptsearch.ui
        animalprofile.h
        animalprofile.cpp
        animalprofile.ui
        tcpclient.cpp
        tcpclient.h
        informationsmenu.h
        informationsmenu.cpp
        informationsmenu.ui
        eventreport.h
        eventreport.cpp
        eventreport.ui
        campaign.h
        campaign.cpp
        campaign.ui
        vaccinareinfo.h
        vaccinareinfo.cpp
        vaccinareinfo.ui
        adoptareinfo.h
        adoptareinfo.cpp
        adoptareinfo.ui
        sterilizareinfo.h
        sterilizareinfo.cpp
        sterilizareinfo.ui
        adminmenu.h
        adminmenu.cpp
        adminmenu.ui
        addanimal.h
        addanimal.cpp
        addanimal.ui
        addcampaign.h
        addcampaign.cpp
        addcampaign.ui
        manageanimals.h
        manageanimals.cpp
        manageanimals.ui
        system.h
        system.cpp
        iprotocol.h
        iprotocol.cpp
        protocol.h
        protocol.cpp
        protocollogin.h
        protocollogin.cpp
        protocolregister.h
        protocolregister.cpp
        protocoladdanimal.h
        protocoladdanimal.cpp
        protocolfilteranimals.h
        protocolfilteranimals.cpp
        protocolcampaigns.h
        protocolcampaigns.cpp
        campaigns.h
        campaigns.cpp
        protocolloginadmin.h
        protocolloginadmin.cpp
        animal.h
        animal.cpp
        adoptformular.h
        adoptformular.cpp
        adoptformular.ui
        protocolformular.h
        protocolformular.cpp
        protocoladdcampaign.h
        protocoladdcampaign.cpp
        protocolremoveanimal.h
        protocolremoveanimal.cpp
        protocolremovecampaign.h
        protocolremovecampaign.cpp
        protocollog.h
        protocollog.cpp
        logfile.h
        logfile.cpp
        logfile.ui
        protocolrequests.h
        protocolrequests.cpp
        request.h
        request.cpp
        protocolapproval.h
        requestslist.h
        requestslist.cpp
        requestslist.ui
        protocolapproval.cpp
        requestpage.h
        requestpage.cpp
        requestpage.ui



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ASPA
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ASPA APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ASPA SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ASPA
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ASPA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ASPA PRIVATE Qt6::Network)


set_target_properties(ASPA PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ASPA)
endif()
