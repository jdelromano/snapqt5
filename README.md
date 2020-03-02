# snapqt5

Small project to try and test snapcraft with a Qt application. Here we try various configurations to build the project src/snapqt5.pro using a version of Qt different then the one coming with the snap.

The problems I try to face are:

- Choose file dialog not always shows up
- QDesktopServices::openUrl not always work

Probably there is a package missing... but it's hard to understand which one as testing on different os you have different behaviours...

To test, open a terminal in one of the snap-* packages and simply run the command snapcraft.

The newer packages of Qt are downloaded from ppa provided here:
https://launchpad.net/~beineri/+archive/ubuntu/opt-qt-5.14.1-bionic
