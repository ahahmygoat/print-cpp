cmake_minimum_required(VERSION 3.16)

# Target name = folder name (e.g., mini-01-market-data)
get_filename_component(TGT "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

# Compile all .cpp in src/
file(GLOB SRC_FILES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

if (SRC_FILES)
  add_executable(${TGT} ${SRC_FILES})
  # Local headers like ok.hpp in src/
  target_include_directories(${TGT} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
else()
  message(WARNING "Skipping ${TGT}: no .cpp files in src/")
endif()
