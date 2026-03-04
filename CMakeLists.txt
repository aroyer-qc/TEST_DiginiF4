cmake_minimum_required (VERSION 3.21)
project(Test_DiginiF4 C CXX ASM)

# Set toolchain for ARM GCC (adjust path as needed)
# set(CMAKE_TOOLCHAIN_FILE path/to/arm-none-eabi-gcc-toolchain.cmake)

find_program(CCACHE "ccache")
if(CCACHE)
    message(NOTICE "Found ccache and will use it for c and c++")
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
endif(CCACHE)

# Collect all source files
set(SOURCES
    ../App/src/bsp.cpp
    ../App/src/irq.cpp
    ../App/src/main.cpp
    ../App/src/task_network.cpp
    ../App/src/taskIdle.cpp
    ../App/src/taskMQTT.cpp
    ../App/src/taskTCP_Client.cpp
    ../App/startup_stm32f4xx.S
    ../Module/Digini/Comm/CmdLine/src/lib_cli.cpp
    ../Module/Digini/Comm/CmdLine/src/lib_cli_command.cpp
    ../Module/Digini/Comm/Comm/src/lib_comm.cpp
    ../Module/Digini/Comm/Console/src/lib_console.cpp
    ../Module/Digini/Comm/VT100/src/lib_vt100.cpp
    ../Module/Digini/Comm/VT100/src/lib_vt100_callback.cpp
    ../Module/Digini/Database/src/lib_class_database.cpp
    ../Module/Digini/Database/src/lib_class_hard_dbase.cpp
    ../Module/Digini/Database/src/lib_class_rom_dbase.cpp
    ../Module/Digini/Database/src/lib_database_wrapper.cpp
    ../Module/Digini/Digini/src/digini.cpp
    ../Module/Digini/Digini/src/lib_label.cpp
    ../Module/Digini/Memory/src/lib_memory.cpp
    ../Module/Digini/NanoIP/src/Driver/Adapters/ETH_SM32_Adapter.cpp
    ../Module/Digini/NanoIP/src/Driver/MAC/lib_class_PHY_LAN8742A.cpp
    ../Module/Digini/NanoIP/src/lib_class_arp.cpp
    ../Module/Digini/NanoIP/src/lib_class_context.cpp
    ../Module/Digini/NanoIP/src/lib_class_dhcp.cpp
    ../Module/Digini/NanoIP/src/lib_class_dns.cpp
    ../Module/Digini/NanoIP/src/lib_class_ethernet_if.cpp
    ../Module/Digini/NanoIP/src/lib_class_icmp.cpp
    ../Module/Digini/NanoIP/src/lib_class_IP_Manager.cpp
    ../Module/Digini/NanoIP/src/lib_class_mqtt.cpp
    ../Module/Digini/NanoIP/src/lib_class_sntp.cpp
    ../Module/Digini/NanoIP/src/lib_class_socket.cpp
    ../Module/Digini/NanoIP/src/lib_class_tcp.cpp
    ../Module/Digini/NanoIP/src/lib_class_udp.cpp
    ../Module/Digini/Peripheral/src/device/lib_class_pwm_WS281x.cpp
    ../Module/Digini/Peripheral/src/device/lib_class_spi_VFD.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_crc.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_dma.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_eth.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_pwm.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_spi.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_tim.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_class_STM32F4_uart.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_io.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_isr.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_rng.cpp
    ../Module/Digini/Peripheral/src/port/STM32F4xx/lib_STM32F4_system_clock.c
    ../Module/Digini/RTOS_Wrapper/src/nOS/lib_nOS_Tick.c
    ../Module/Digini/String/src/lib_string.cpp
    ../Module/Digini/Utility/src/lib_bit_reversal.cpp
    ../Module/Digini/Utility/src/lib_class_bit_array.cpp
    ../Module/Digini/Utility/src/lib_class_crc.cpp
    ../Module/Digini/Utility/src/lib_fast_memcpy.cpp
    ../Module/Digini/Utility/src/lib_fifo.cpp
    ../Module/Digini/Utility/src/lib_stacktistic.cpp
    ../Module/Digini/Utility/src/lib_time_and_delay.cpp
    ../Module/Digini/Utility/src/port/STM32F4xx/lib_stacktistic_STM32F4.cpp
    ../Module/nOS/src/nOSAlarm.c
    ../Module/nOS/src/nOSBarrier.c
    ../Module/nOS/src/nOSEvent.c
    ../Module/nOS/src/nOSFlag.c
    ../Module/nOS/src/nOSList.c
    ../Module/nOS/src/nOSMem.c
    ../Module/nOS/src/nOSMutex.c
    ../Module/nOS/src/nOSQueue.c
    ../Module/nOS/src/nOSSched.c
    ../Module/nOS/src/nOSSem.c
    ../Module/nOS/src/nOSSignal.c
    ../Module/nOS/src/nOSThread.c
    ../Module/nOS/src/nOSTime.c
    ../Module/nOS/src/nOSTimer.c
    ../Module/nOS/src/port/GCC/ARM_Cortex_M4/nOSPort.c
    ebmon.c
)

# Include directories
include_directories(
    ../Config
    ../Module
    ../App/inc
    ../Module/Digini/Comm/CmdLine/inc
    ../Module/Digini/Comm/Comm/inc
    ../Module/Digini/Comm/Console/inc
    ../Module/Digini/Comm/VT100/inc
    ../Module/Digini/Database/inc
    ../Module/Digini/Digini/inc
    ../Module/Digini/Memory/inc
    ../Module/Digini/NanoIP/inc
    ../Module/Digini/NanoIP/inc/Driver/Adapters
    ../Module/Digini/NanoIP/inc/Driver/MAC
    ../Module/Digini/NanoIP/inc/Interface
    ../Module/Digini/Peripheral/inc
    ../Module/Digini/Peripheral/inc/device
    ../Module/Digini/Peripheral/inc/device/port/STM32F4xx
    ../Module/Digini/Peripheral/inc/port/STM32F4xx
    ../Module/Digini/String/inc
    ../Module/Digini/Utility/inc
    ../Module/nOS/inc
    ../Module/nOS/inc/port/GCC/ARM_Cortex_M4
)

# Common compile options
set(COMMON_C_FLAGS "-mfloat-abi=hard -std=gnu11 -O0 -g3 -fno-strict-aliasing")
set(COMMON_CXX_FLAGS "-mfloat-abi=hard -std=gnu++17 -fschedule-insns2 -O0 -g3 -Wno-psabi -Wno-literal-suffix -fpermissive -fno-strict-aliasing -fno-use-cxa-atexit -Wno-register")
set(COMMON_DEFINES "-DARM_MATH_CM4 -Dx__FPU_PRESENT=1 -DxUSE_USB_FS -DSTM32F4xx -DSTM32F429_439xx")

# Targets
foreach(TARGET_NAME IN ITEMS "Debug_F429" "Release_F429" "Debug_F401" "Release_F401" "Debug_F427" "Release_F427")
    if(TARGET_NAME MATCHES "Debug_F429")
        set(LINKER_SCRIPT "./stm32f429zi_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Debug_F429")
        set(CPU_DEFINES "-DSTM32F429xx -DDEBUG")
        set(C_FLAGS "${COMMON_C_FLAGS} -Wcomment -Wall -fshort-enums -ffunction-sections -O0 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS} -std=gnu++11 -Wcomment -pedantic-errors -Wall -fdata-sections -ffunction-sections -g3")
        set(ASM_FLAGS "-Wa,--gdwarf-2")
        set(LINK_FLAGS "-Wl,--cref")
    elseif(TARGET_NAME MATCHES "Release_F429")
        set(LINKER_SCRIPT "./stm32f429zi_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Release_F429")
        set(CPU_DEFINES "-DSTM32F429xx")
        set(C_FLAGS "${COMMON_C_FLAGS} -fdata-sections -ffunction-sections -O2 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS}")
        set(ASM_FLAGS "-Wa,--no-warn")
        set(LINK_FLAGS "-Wl,--gc-sections")
    elseif(TARGET_NAME MATCHES "Debug_F401")
        set(LINKER_SCRIPT "./stm32f401re_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Debug_F401")
        set(CPU_DEFINES "-DSTM32F401xE -DDEBUG")
        set(C_FLAGS "${COMMON_C_FLAGS} -Wcomment -Wall -fshort-enums -ffunction-sections -O0 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS} -std=gnu++11 -Wcomment -pedantic-errors -Wall -fdata-sections -ffunction-sections -g3")
        set(ASM_FLAGS "-Wa,--gdwarf-2")
        set(LINK_FLAGS "-Wl,--cref")
    elseif(TARGET_NAME MATCHES "Release_F401")
        set(LINKER_SCRIPT "./stm32f401re_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Release_F401")
        set(CPU_DEFINES "-DSTM32F401xE")
        set(C_FLAGS "${COMMON_C_FLAGS} -fdata-sections -ffunction-sections -O2 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS}")
        set(ASM_FLAGS "-Wa,--no-warn")
        set(LINK_FLAGS "-Wl,--gc-sections")
    elseif(TARGET_NAME MATCHES "Debug_F427")
        set(LINKER_SCRIPT "./stm32f429zi_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Debug_F427")
        set(CPU_DEFINES "-DSTM32F427xx -DDEBUG")
        set(C_FLAGS "${COMMON_C_FLAGS} -Wcomment -Wall -fshort-enums -ffunction-sections -O0 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS} -std=gnu++11 -Wcomment -pedantic-errors -Wall -fdata-sections -ffunction-sections -g3")
        set(ASM_FLAGS "-Wa,--gdwarf-2")
        set(LINK_FLAGS "-Wl,--cref")
    elseif(TARGET_NAME MATCHES "Release_F427")
        set(LINKER_SCRIPT "./stm32f429zi_flash.ld")
        set(OUTPUT_NAME "Test_DiginiF4_Release_F427")
        set(CPU_DEFINES "-DSTM32F427xx")
        set(C_FLAGS "${COMMON_C_FLAGS} -fdata-sections -ffunction-sections -O2 -g2")
        set(CXX_FLAGS "${COMMON_CXX_FLAGS}")
        set(ASM_FLAGS "-Wa,--no-warn")
        set(LINK_FLAGS "-Wl,--gc-sections")
    endif()

    add_executable(${OUTPUT_NAME} ${SOURCES})
    target_compile_options(${OUTPUT_NAME} PRIVATE ${C_FLAGS} ${CXX_FLAGS} ${ASM_FLAGS})
    target_link_options(${OUTPUT_NAME} PRIVATE ${LINK_FLAGS} -T${LINKER_SCRIPT} -lm -lstdc++)
    target_compile_definitions(${OUTPUT_NAME} PRIVATE ${COMMON_DEFINES} ${CPU_DEFINES})
    # Add additional include directories if needed
    # target_include_directories(${OUTPUT_NAME} PRIVATE ...)
endforeach()