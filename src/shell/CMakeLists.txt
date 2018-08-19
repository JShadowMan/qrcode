cmake_minimum_required(VERSION 3.8)

# -- qrcode-client detail
set(QRCODE_TARGET_NAME qc-cli)

# -- client sources
aux_source_directory(${QRCODE_SOURCES}/shell QRCODE_TARGET_SOURCES)

# -- executable generated
add_executable(${QRCODE_TARGET_NAME}
    ${QRCODE_LIBRARIES_SOURCES} ${QRCODE_TARGET_SOURCES})
