// Copyright information and license terms for this software can be
// found in the file LICENSE that is included with the distribution

/* powerSupply.h */

/**
 * @author mrk
 * @date 2013.04.02
 */
#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H


#ifdef epicsExportSharedSymbols
#   define powerSupplyEpicsExportSharedSymbols
#   undef epicsExportSharedSymbols
#endif

#include <pv/timeStamp.h>
#include <pv/alarm.h>
#include <pv/pvTimeStamp.h>
#include <pv/pvAlarm.h>
#include <pv/pvDatabase.h>

#ifdef powerSupplyEpicsExportSharedSymbols
#   define epicsExportSharedSymbols
#	undef powerSupplyEpicsExportSharedSymbols
#endif

#include <shareLib.h>


namespace epics { namespace pvDatabase { 

epicsShareExtern epics::pvData::PVStructurePtr createPowerSupply();

class PowerSupply;
typedef std::tr1::shared_ptr<PowerSupply> PowerSupplyPtr;

class epicsShareClass PowerSupply :
    public PVRecord
{
public:
    POINTER_DEFINITIONS(PowerSupply);
    static PowerSupplyPtr create(
        std::string const & recordName);
    virtual ~PowerSupply();
    virtual void destroy();
    virtual bool init();
    virtual void process();
    
private:
    PowerSupply(std::string const & recordName,
        epics::pvData::PVStructurePtr const & pvStructure);
    void put(double power,double voltage);
    double getPower();
    double getVoltage();
    double getCurrent();

    epics::pvData::PVDoublePtr pvCurrent;
    epics::pvData::PVDoublePtr pvPower;
    epics::pvData::PVDoublePtr pvVoltage;
    epics::pvData::PVAlarm pvAlarm;
    epics::pvData::PVTimeStamp pvTimeStamp;
    epics::pvData::Alarm alarm;
    epics::pvData::TimeStamp timeStamp;
};


}}

#endif  /* POWERSUPPLY_H */
