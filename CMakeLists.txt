project(fcitx-sogoupinyin)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(Fcitx 4.2.8 REQUIRED)

_fcitx_add_uninstall_target()

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_CXX_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_MODULE_LINKER_FLAGS}")
add_definitions("-D_GNU_SOURCE -DFCITX_HAVE_CONFIG_H")

set(includedir "${CMAKE_INSTALL_PREFIX}/include")
set(libdir ${LIB_INSTALL_DIR})
set(pkgconfdir ${LIBDATA_INSTALL_DIR}/pkgconfig)
set(mandir ${MAN_INSTALL_DIR})
set(addondir ${libdir}/${package} )
set(pkgdatadir ${prefix}/share/${package})
set(configdescdir ${pkgdatadir}/configdesc)
set(addonconfigdir ${pkgdatadir}/addon)
set(imconfigdir ${pkgdatadir}/inputmethod)
set(localedir ${CMAKE_INSTALL_PREFIX}/share/locale)

add_subdirectory(src)
add_subdirectory(data)
