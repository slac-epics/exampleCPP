/*ArchiverServiceRPCMain.cpp */

/* Author: Marty Kraimer */

#include <cstddef>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <cstdio>
#include <memory>
#include <iostream>

#include <cantProceed.h>
#include <epicsStdio.h>
#include <epicsMutex.h>
#include <epicsEvent.h>
#include <epicsThread.h>

#include <epicsExport.h>

#include <pv/pvIntrospect.h>
#include <pv/pvData.h>
#include <pv/pvAccess.h>
#include <pv/serverContext.h>

#include <pv/pvDatabase.h>
#include <pv/pvServiceProvider.h>
#include <ArchiverServiceRPC.h>

using namespace std;
using namespace epics::pvData;
using namespace epics::pvAccess;
using namespace epics::pvIOC;

int main(int argc,char *argv[])
{
    if(argc < 3)
    {
        cerr << "usage: ArchiverServiceRPC index channel" << endl;
        exit(1);
    }

    char * index = argv[1];
    char * channel = argv[2];

    PVServiceChannelCTX::shared_pointer myCTX
        = PVServiceChannelCTX::shared_pointer(new PVServiceChannelCTX());
    ArchiverServiceRPC::shared_pointer example
        = ArchiverServiceRPC::shared_pointer(new ArchiverServiceRPC(index));
    ServiceChannelRPC::shared_pointer serviceChannelRPC
        = ServiceChannelRPC::shared_pointer(
            new ServiceChannelRPC(channel, example));
    cout << channel << endl;
    string str;
    while(true) {
        cout << "Type exit to stop: \n";
        getline(cin,str);
        if(str.compare("exit")==0) break;
        
    }
    return(0);
}
