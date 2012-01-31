
#ifndef SAMPLESENSOR_I_H
#define SAMPLESENSOR_I_H

#include <QtDBus/QtDBus>

#include <datatypes/unsigned.h>
#include "abstractsensor_i.h"


class SampleSensorChannelInterface : public AbstractSensorChannelInterface
{
    Q_OBJECT
    Q_DISABLE_COPY(SampleSensorChannelInterface)
    Q_PROPERTY(Unsigned value READ value)

public:
    /**
     * Name of the D-Bus interface for this class.
     */
    static const char* staticInterfaceName;

    /**
     * Create new instance of the class.
     *
     * @param id Sensor ID.
     * @param sessionId Session ID.
     * @return Pointer to new instance of the class.
     */
    static AbstractSensorChannelInterface* factoryMethod(const QString& id, int sessionId);


    Unsigned value();

    /**
     * Constructor.
     *
     * @param path      path.
     * @param sessionId session ID.
     */
    SampleSensorChannelInterface(const QString& path, int sessionId);

    /**
     * Request a listening interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use #interface(const QString&) instead.
     */
    static const SampleSensorChannelInterface* listenInterface(const QString& id);

    /**
     * Request a control interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     * @deprecated use #interface(const QString&) instead.
     */
    static SampleSensorChannelInterface* controlInterface(const QString& id);

    /**
     * Request an interface to the sensor.
     *
     * @param id sensor ID.
     * @return Pointer to interface, or NULL on failure.
     */
    static SampleSensorChannelInterface* interface(const QString& id);

protected:
    virtual bool dataReceivedImpl();

Q_SIGNALS:

    void sampleDataChanged(const Unsigned& sampleData);
};

namespace local {
  typedef ::SampleSensorChannelInterface SampleSensor;
}

#endif /* SAMPLESENSOR_I_H */
