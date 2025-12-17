add_library(frontend
  scanner.cpp
  )

target_include_directories(frontend 
  ${WARNING_GUARD} PUBLIC 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/frontend>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include/frontend>
    )

target_compile_features(frontend PUBLIC cxx_std_20)
target_compile_options(frontend PUBLIC ${PROJECT_WARNINGS})
