#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/kiran/catkin_ws/src/navigation_hydro_devel/base_local_planner"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/kiran/catkin_ws/install/lib/python2.7/dist-packages:/home/kiran/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/kiran/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/kiran/catkin_ws/src/navigation_hydro_devel/base_local_planner/setup.py" \
    build --build-base "/home/kiran/catkin_ws/build/navigation_hydro_devel/base_local_planner" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/kiran/catkin_ws/install" --install-scripts="/home/kiran/catkin_ws/install/bin"
