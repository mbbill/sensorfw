TEMPLATE = subdirs

include( ../common-config.pri )

SUBDIRS = alsadaptor \
          alsadaptor-sysfs \
          alsadaptor-ascii \
          tapadaptor \
          accelerometeradaptor \
          magnetometeradaptor \
          magnetometeradaptor-ascii \
          magnetometeradaptor-ncdk \
          touchadaptor \
          kbslideradaptor \
          proximityadaptor \
          proximityadaptor-evdev \
          proximityadaptor-ascii \
          mrstaccelerometer \
          gyroscopeadaptor \
          pegatronaccelerometeradaptor \
          oemtabletaccelerometer \
          oaktrailaccelerometer \
          oemtabletalsadaptor-ascii \
          oemtabletgyroscopeadaptor
