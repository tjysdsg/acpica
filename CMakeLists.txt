aux_source_directory(source/components/dispatcher ACPICA_SRCS)
aux_source_directory(source/components/events ACPICA_SRCS)
aux_source_directory(source/components/executer ACPICA_SRCS)
aux_source_directory(source/components/hardware ACPICA_SRCS)
aux_source_directory(source/components/namespace ACPICA_SRCS)
aux_source_directory(source/components/parser ACPICA_SRCS)
aux_source_directory(source/components/tables ACPICA_SRCS)
aux_source_directory(source/components/utilities ACPICA_SRCS)

add_library(
        acpica
        ${ACPICA_SRCS}
)

target_compile_options(
        acpica
        PRIVATE -ffreestanding -Wall -fno-exceptions
)
target_include_directories(acpica PUBLIC source/include)
target_compile_definitions(acpica PUBLIC _TOS __KERNEL__)

if (NOT TARGET c)
    message(FATAL_ERROR "Need libc target for acpica")
endif()
target_link_libraries(acpica PUBLIC c)
