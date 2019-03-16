# -*- coding: utf-8 -*-
from __future__ import print_function
import argparse
import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/kinetic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/kinetic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in "/home/fjj/documents/course_code/my_book_code/devel;/home/fjj/documents/new_pack_code/turtlebot_source_code/devel;/home/fjj/documents/fjj_ros_code/fjj_project_code/devel;/home/fjj/documents/fjj_ros_code/fjj_learn/devel;/home/fjj/documents/course_code/ROS_FOR_BEGINER_COURSE_CODE/devel;/home/fjj/documents/project_code/devel;/home/fjj/documents/new_pack_code/my_robot_model/devel;/home/fjj/documents/fjj_ros_code/fjj_code/devel;/home/fjj/documents/course_code/roslearn/devel;/home/fjj/documents/course_code/ros_course_for_kinetic/devel;/opt/ros/kinetic".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/fjj/documents/fjj_ros_code/fjj_code/devel/env.sh')

output_filename = '/home/fjj/documents/fjj_ros_code/fjj_code/build/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
