cmake_minimum_required(VERSION 3.16)

# Target name = folder name
get_filename_component(TGT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Compile all .cpp in src/
file(GLOB SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

if (SRC_FILES)
  add_executable(${TGT} ${SRC_FILES})
  target_include_directories(${TGT} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
else()
  message(WARNING "Skipping ${TGT}: no .cpp files in src/")
endif()
