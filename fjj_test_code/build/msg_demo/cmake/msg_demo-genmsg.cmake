# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "msg_demo: 1 messages, 1 services")

set(MSG_I_FLAGS "-Imsg_demo:/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(msg_demo_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_custom_target(_msg_demo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "msg_demo" "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" ""
)

get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_custom_target(_msg_demo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "msg_demo" "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/msg_demo
)

### Generating Services
_generate_srv_cpp(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/msg_demo
)

### Generating Module File
_generate_module_cpp(msg_demo
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/msg_demo
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(msg_demo_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(msg_demo_generate_messages msg_demo_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_dependencies(msg_demo_generate_messages_cpp _msg_demo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_dependencies(msg_demo_generate_messages_cpp _msg_demo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(msg_demo_gencpp)
add_dependencies(msg_demo_gencpp msg_demo_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS msg_demo_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/msg_demo
)

### Generating Services
_generate_srv_eus(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/msg_demo
)

### Generating Module File
_generate_module_eus(msg_demo
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/msg_demo
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(msg_demo_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(msg_demo_generate_messages msg_demo_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_dependencies(msg_demo_generate_messages_eus _msg_demo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_dependencies(msg_demo_generate_messages_eus _msg_demo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(msg_demo_geneus)
add_dependencies(msg_demo_geneus msg_demo_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS msg_demo_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/msg_demo
)

### Generating Services
_generate_srv_lisp(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/msg_demo
)

### Generating Module File
_generate_module_lisp(msg_demo
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/msg_demo
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(msg_demo_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(msg_demo_generate_messages msg_demo_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_dependencies(msg_demo_generate_messages_lisp _msg_demo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_dependencies(msg_demo_generate_messages_lisp _msg_demo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(msg_demo_genlisp)
add_dependencies(msg_demo_genlisp msg_demo_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS msg_demo_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/msg_demo
)

### Generating Services
_generate_srv_nodejs(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/msg_demo
)

### Generating Module File
_generate_module_nodejs(msg_demo
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/msg_demo
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(msg_demo_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(msg_demo_generate_messages msg_demo_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_dependencies(msg_demo_generate_messages_nodejs _msg_demo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_dependencies(msg_demo_generate_messages_nodejs _msg_demo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(msg_demo_gennodejs)
add_dependencies(msg_demo_gennodejs msg_demo_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS msg_demo_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo
)

### Generating Services
_generate_srv_py(msg_demo
  "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo
)

### Generating Module File
_generate_module_py(msg_demo
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(msg_demo_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(msg_demo_generate_messages msg_demo_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/msg/num.msg" NAME_WE)
add_dependencies(msg_demo_generate_messages_py _msg_demo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fjj/documents/fjj_ros_code/fjj_test_code/src/msg_demo/srv/srv_demo.srv" NAME_WE)
add_dependencies(msg_demo_generate_messages_py _msg_demo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(msg_demo_genpy)
add_dependencies(msg_demo_genpy msg_demo_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS msg_demo_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/msg_demo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/msg_demo
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(msg_demo_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/msg_demo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/msg_demo
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(msg_demo_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/msg_demo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/msg_demo
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(msg_demo_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/msg_demo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/msg_demo
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(msg_demo_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/msg_demo
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(msg_demo_generate_messages_py std_msgs_generate_messages_py)
endif()
