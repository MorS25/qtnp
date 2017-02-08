# qtnp
Qt+CGAL+ROS area partition and path planning for multiple UAVs for coastal regions.

***

# Multiple UAV waypoint path planning application.

Made with Qt5.5, for ROS Kinetic, using CGAL 4.8.

A kml file defines area borders and no-fly zones. 

Multiple UAVs can be assigned anywhere in that area, having different Field of View (FoV) footprint projections on the sea. Area decomposition and partition is performed based on those restrictions and coverage waypoint lists are produced in MAVlink format.
