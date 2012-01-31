

#include "sensormanagerinterface.h"
#include "samplesensor_i.h"

const char* SampleSensorChannelInterface::staticInterfaceName = "local.SampleSensor";

AbstractSensorChannelInterface* SampleSensorChannelInterface::factoryMethod(const QString& id, int sessionId)
{
    return new SampleSensorChannelInterface(OBJECT_PATH + "/" + id, sessionId);
}

SampleSensorChannelInterface::SampleSensorChannelInterface(const QString &path, int sessionId) :
    AbstractSensorChannelInterface(path, SampleSensorChannelInterface::staticInterfaceName, sessionId)
{
}

const SampleSensorChannelInterface* SampleSensorChannelInterface::listenInterface(const QString& id)
{
    return dynamic_cast<const SampleSensorChannelInterface*>(interface(id));
}

SampleSensorChannelInterface* SampleSensorChannelInterface::controlInterface(const QString& id)
{
    return interface(id);
}

SampleSensorChannelInterface* SampleSensorChannelInterface::interface(const QString& id)
{
    SensorManagerInterface& sm = SensorManagerInterface::instance();
    if ( !sm.registeredAndCorrectClassName( id, SampleSensorChannelInterface::staticMetaObject.className() ) )
    {
        return 0;
    }

    return dynamic_cast<SampleSensorChannelInterface*>(sm.interface(id));
}

bool SampleSensorChannelInterface::dataReceivedImpl()
{
    QVector<TimedUnsigned> values;
    if(!read<TimedUnsigned>(values))
        return false;
    foreach(const TimedUnsigned& data, values)
        emit sampleDataChanged(data);
    return true;
}

Unsigned SampleSensorChannelInterface::value()
{
    return getAccessor<Unsigned>("value");
}
