add_subdirectory(libraries)

OPTION(TEST "Test for libraries and integration" ON)
IF(TEST)
add_subdirectory(test)
ENDIF()

OPTION(APPS "Aplications (Ceabot, footbal...)" ON)
IF(APPS)
add_subdirectory(apps)
ENDIF()



