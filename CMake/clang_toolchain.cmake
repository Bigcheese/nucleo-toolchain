# Sadly try_compile doesn't propagate CMAKE_TOOLCHAIN_FILE, so we can't use it to derive the TOOLCHAIN_DIR.
#get_filename_component(TOOLCHAIN_DIR "${CMAKE_TOOLCHAIN_FILE}" PATH)
set(TOOLCHAIN_DIR "C:/Users/Michael/Projects/ST Nucleo/toolchain/CMake")

include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-clang GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-clang++ GNU)

set(COMMON_FLAGS "-mcpu=cortex-m3 -mthumb -ffunction-sections -fdata-sections -DSTM32F10X_MD -fcolor-diagnostics -fno-exceptions")
set(CMAKE_CXX_FLAGS "-std=c++11 ${COMMON_FLAGS} ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "-std=c11 ${COMMON_FLAGS} ${CMAKE_C_FLAGS}")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS} ${CMAKE_ASM_FLAGS}")
set(CMAKE_SIZEOF_VOID_P 4)

include_directories(BEFORE SYSTEM K:/Build/llvm-project/vs11/Release/lib/clang/3.5.0/include)
include_directories(SYSTEM "${TOOLCHAIN_DIR}/../source/include")
link_directories("${TOOLCHAIN_DIR}/../lib")

set(DEFAULT_OBJECTS "\"${TOOLCHAIN_DIR}/../lib/init.o\"")
set(LINK_LINE "arm-none-eabi-ld -T \"${TOOLCHAIN_DIR}/STM32F103RB.ld\" -nostdlib -nodefaultlib -gc-sections <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> ${DEFAULT_OBJECTS} <OBJECTS> -o <TARGET> <LINK_LIBRARIES> -lpdc -lcore -lperipherals -lclang_rt.arm")

set(CMAKE_C_LINK_EXECUTABLE ${LINK_LINE})
  
set(CMAKE_CXX_LINK_EXECUTABLE ${LINK_LINE})
