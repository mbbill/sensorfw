TEMPLATE = subdirs

include( ../common-config.pri )
include( ../common-install.pri )

SUBDIRS = adaptorplugin \
          chainplugin \
          filterplugin \
          sensorplugin
