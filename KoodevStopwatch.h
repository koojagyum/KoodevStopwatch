#ifndef KoodevStopWatch_h
#define KoodevStopWatch_h

#include "koodev_config.h"

#include <sys/time.h>
#include <vector>
#include <string>

#define KOODEV_ADDRESS_LENGTH 10 // 32bit(8) + "0x"(2)
#define KOODEV_DEFAULT_MESSAGE_LENGTH 16 + KOODEV_ADDRESS_LENGTH

#ifdef KOODEV_NAMESPACE
namespace KOODEV_NAMESPACE {
#endif // KOODEV_NAMESPACE

class KoodevStopwatch
{
public:
    KoodevStopwatch(const char *msg=NULL, bool autostart=true, bool dumpOnDestroy=true, bool nanos=false);
    ~KoodevStopwatch();

    void start();
    void stop(bool andDump = false);
    void reset();
    void lab();
    void lab(const char *tag);

    void setMessage(const char *msg);
    void dump();

    long getCurrentTimeMillis();

private:
    struct LabTimeDescriptor
    {
        timeval labTimeval;
        std::string tag;
    };

    bool m_started;
    bool m_measureNanos;

    char m_defaultMessage[KOODEV_DEFAULT_MESSAGE_LENGTH];

    timeval m_startTimeval;
    timeval m_endTimeval;
    std::vector<LabTimeDescriptor> m_labTimeRecords;
    std::string m_message;

    bool m_dumpOnDestroy;

    void initDefaultMessage();
    long getTime(timeval &labTimeval);
    long getTime();
    long getLabTime(timeval &labTimeval);
    void dumpMessage(long labTime);
    void dumpMessage(long labTime, int index);
    void dumpMessage(long labTime, const char *tag);
    const char* getTimeUnit();
};

#ifdef KOODEV_NAMESPACE
} // namespace
#endif // KOODEV_NAMESPACE

#endif // KoodevTimer_h
