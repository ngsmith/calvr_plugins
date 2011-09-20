FIND_PATH(CALVR_DIR include/kernel/CalVR.h
  PATHS
  $ENV{CALVR_HOME}
  NO_DEFAULT_PATH
)

FIND_PATH(CALVR_INCLUDE_DIR kernel/CalVR.h
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
    PATH_SUFFIXES include
)

FIND_LIBRARY(CALVR_COLLABORATIVE_LIBRARY 
  NAMES collaborative
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(CALVR_CONFIG_LIBRARY 
  NAMES config
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(CALVR_INPUT_LIBRARY 
  NAMES input
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(CALVR_KERNEL_LIBRARY 
  NAMES kernel
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(CALVR_MENU_LIBRARY 
  NAMES menu
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(CALVR_UTIL_LIBRARY 
  NAMES util
  PATHS
  ${CALVR_DIR}
  NO_DEFAULT_PATH
  PATH_SUFFIXES lib64 lib
)

MARK_AS_ADVANCED(CALVR_COLLABORATIVE_LIBRARY)
MARK_AS_ADVANCED(CALVR_CONFIG_LIBRARY)
MARK_AS_ADVANCED(CALVR_INPUT_LIBRARY)
MARK_AS_ADVANCED(CALVR_KERNEL_LIBRARY)
MARK_AS_ADVANCED(CALVR_MENU_LIBRARY)
MARK_AS_ADVANCED(CALVR_UTIL_LIBRARY)

SET(CALVR_FOUND "NO")
IF(CALVR_INCLUDE_DIR AND CALVR_KERNEL_LIBRARY)
    SET(CALVR_FOUND "YES")
ENDIF(CALVR_INCLUDE_DIR AND CALVR_KERNEL_LIBRARY)