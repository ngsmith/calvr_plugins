SET(LIB_NAME WaterMaze)
SET(PLUGIN_HEADERS
    WaterMaze.h
)

ADD_LIBRARY(${LIB_NAME}
    "SHARED"
    ${PLUGIN_HEADERS}
    WaterMaze.cpp
)

INCLUDE_DIRECTORIES(${OSG_INCLUDE_DIR})

TARGET_LINK_LIBRARIES(${LIB_NAME} ${OSG_LIBRARIES})

INSTALL(TARGETS ${LIB_NAME} DESTINATION lib/plugins)
