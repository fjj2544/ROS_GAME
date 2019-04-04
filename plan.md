# Final goal
The primary goal is to escort multiple people to designated locations.

# Short-term goal
## Basic restrictions:
1. You can create a map inside the house and try to establish an external static map in advance.
2. When the escort is made, people follow the robot.
3. The position of the person remains the same when the person is identified, and the position of the person does not change after the robot has taken the baggage.
4. For the time being, the man-machine coordination during the escort is not considered, that is, the robot is not required to help the person to support the umbrella.

## Basic process:
1. First, the robot starts from the initial coordinate point and establishes an internal map or an existing map in the early stage by moving continuously in the house (at least 1 minute) to obtain a static map inside the house. (Using lidar or kinect to perform SLAM, the difficulty is that the accuracy of the mapping is not high, and the information such as the odometer has data noise, and can be added to the Kalman filter combined with imu)
2. The robot then moves continuously to identify if there are people who want to leave the room.
2.1 If there is a person who wants to leave, the robot will be close to the person who wants to leave, then identify its clothes by identifying its characteristics, and record the current position.
2.1.1 Then the robot will go to the location where the clothes are placed and get the clothes.
2.1.2 Finally, the robot returns to the requester's side and prepares to take it to the cab position. Here, it is guaranteed that the person will not move or leave the original coordinate point during the process of taking the clothes. (fetch function)
2.2 If there is no one who wants to leave, the robot will move continuously in the room, continue to wait for instructions, and repeat the second step until someone wants to signal the signal they want to leave.
3. When the second step is completed, let the robot automatically navigate outside the door and take the person outside the door.
3.1 Then identify and locate outside the door, find the corresponding cab (here because the recognition distance of the kinect is only 3m), so after the recognition, the person is guided to the corresponding cab position.
3.2 The person puts the umbrella on the robot.
4. After the third step is completed, the robot will return to the original coordinate point, and finally repeat the process of 2-4 to complete the escort operation. (still the construction error, preventing static map offset)

## The basic difficulties of the corresponding process:
1. Using kinect to map the accuracy error at the cm level, the error is too large, the mapping accuracy is not high. Sensors such as odometers have large noise interference and need to be compatible with imu to perform Kalman filtering. The difficulty here is how to implement the automatic mapping process Relocate the Cab Driver.
2. Real-time obstacle avoidance function when moving (the effect of the current function package is not good, may hit people) and the recovery problem when slam, that is, behavior_recovery.
2.1 Need to remember the target point and automatically navigate to the corresponding clothing placement point. Finally, return to the requester's location, to achieve a fetch function. It is possible to use amcl to enhance the positioning accuracy or not to return to the original location, which is related to the gmapping and amcl compatibility issues or the switching problem between the two.
3. This place has to solve the robot's problem of passing the door, which is to solve the problem that the robot passes through the narrow area. (Because there is a certain expansion ratio in the costmap, the excessive expansion ratio will cause the robot to fail to pass through the narrow area. If it is too low, the robot will encounter obstacles.)
3.1 3.2 
4. The same reason is to achieve a classic problem of going out and returning. If the accuracy of the drawing is not high, the positioning effect is not good (that is, it cannot be compatible with gmapping and amcl) and may not return to the original point.

## The main solution to the problem and the expected implementation of the function:
1. Improve the accuracy of SLAM mapping. Create a more accurate map.
2. Develop a plan to pass a narrow area.
3. implement the fetch operation. Realize the return of the state.
4. Need to implement the function of automatic SLAM (not keyboard operation).
5. Need to achieve the function of patrolling the house while avoiding obstacles.


# Long-term goals
## Basic restrictions:
1. You can create a map inside the house. The external map must be built dynamically and cannot be built in advance.
2. When the escort is taken, the robot leads the person to the target point.
3. Consider the escort with the umbrella, use the double kinect and other technologies to realize the front navigation map, and the latter use the depth ranging to establish the dynamic speed control model to ensure the human-machine coordination.
4. The position of the person is allowed to change after the item is acquired. (Second recognition)

## Basic process:
1. First, the robot starts from the initial coordinate point and establishes an internal map or an existing map in the early stage by moving continuously in the house (at least 1 minute) to obtain a static map inside the house. (Using lidar or kinect to perform SLAM, the difficulty is that the accuracy of the mapping is not high, and the information such as the odometer has data noise, and can be added to the Kalman filter combined with imu)
2. The robot then moves continuously to identify if there are people who want to leave the room.
2.1 If there is a person who wants to leave, the robot will be close to the person who wants to leave, and then identify its characteristics and identify its characteristics by identifying its characteristics.
2.1.1 Then the robot will go to the location where the clothes are placed and get the clothes.
2.1.2 Then the robot continues the original coordinate point and starts looking for the person who just called in the house.
2.2 If there is no one who wants to leave, the robot will move continuously in the room, continue to wait for instructions, and repeat the second step until someone wants to signal the signal they want to leave.
3. When the second step is completed, set the robot outside the door and guide the person outside the door. When guiding, you need to use double kinect, the front camera synchronizes SLAM construction and navigation, the rear camera collects human body position information, and combines PID control for human-machine coordination.
3.1 Then identify and locate outside the door, find the corresponding cab (here because the recognition distance of the kinect is only 3m), so after the recognition, the person is guided to the corresponding cab position. At the same time, human-machine collaboration is carried out in the above manner.
3.2 Finally the robot closes the umbrella and prepares to bring it back.
4. After the third step is completed, the robot will return to the original coordinate point, and finally repeat the process of 2-4 to complete the escort operation. (still the construction error, preventing static map offset)

## The basic difficulties of the corresponding process:
1. Using kinect to map the accuracy error at the cm level, the error is too large, the mapping accuracy is not high. Sensors such as odometers have large noise interference and need to be compatible with imu to perform Kalman filtering. The difficulty here is how to implement the process of automatic drawing.
2. Real-time obstacle avoidance function when moving (the effect of the current function package is not good, may hit people) and the recovery problem when SLAM, that is, behavior_recovery. And you need to find the location of the requester again, you need to design a patrol algorithm.
2.1 Need to remember the target point and automatically navigate to the corresponding clothing placement point. Finally, return to the requester's location, to achieve a fetch function. It is possible to use amcl to enhance the positioning accuracy or not to return to the original location, which is related to the gmapping and amcl compatibility issues or the switching problem between the two.
3. This place has to solve the robot's problem of passing the door, which is to solve the problem that the robot passes through the narrow area. (Because there is a certain expansion ratio in the costmap, the expansion ratio is too high, which will cause the robot to fail to pass through the narrow area. If it is too low, the robot will encounter obstacles.) If you need dynamic mapping, you must combine gmapping and amcl. Add a PID speed controller to ensure human-machine coordination.
3.1 3.2 
4. The same reason is to achieve a classic problem of going out and returning. If the accuracy of the drawing is not high, the positioning effect is not good (that is, it cannot be compatible with gmapping and amcl) and may not return to the original point.
The main problem solved and the expected implementation of the function:
1. Double kinect is activated to measure the distance between human and robot.
2. Design the PID model, combined with the rear kinect to adjust the speed of the robot to achieve human-machine synergy.
3. It is also to adjust the compatibility of gmapping and amcl to improve the accuracy of mapping and positioning.
4. It is necessary to design an algorithm that retrieves the requester after returning to the requested location after getting the person's clothes.
5. Need to design a patrol algorithm.