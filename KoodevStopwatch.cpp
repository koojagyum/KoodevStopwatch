#include "KoodevStopwatch.h"
#include <stdio.h>

using namespace std;

#ifdef KOODEV_NAMESPACE
namespace KOODEV_NAMESPACE {
#endif // KOODEV_NAMESPACE

KoodevStopwatch::KoodevStopwatch(const char *msg/*=NULL*/, bool autostart/*=true*/, bool dumpOnDestroy/*=true*/, bool nanos/*=false*/)
	: m_started(false)
	, m_dumpOnDestroy(dumpOnDestroy)
    , m_measureNanos(nanos)
{
    initDefaultMessage();
    setMessage(msg);
    if (autostart)
        start();
}

KoodevStopwatch::~KoodevStopwatch()
{
    if (m_dumpOnDestroy) {
        stop();
        dump();
    }
}

void KoodevStopwatch::start()
{
    m_started = true;
    gettimeofday(&m_startTimeval, NULL);
}

void KoodevStopwatch::stop(bool andDump/* = false*/)
{
    if (!m_started)
        return;

    if (m_labTimeRecords.size() > 0)
        lab();
    gettimeofday(&m_endTimeval, NULL);
    m_started = false;

    if (andDump)
        dump();
}

void KoodevStopwatch::reset()
{
    m_started = false;
    m_labTimeRecords.clear();
}

void KoodevStopwatch::lab()
{
    char buffer[8] = {0, };
    sprintf(buffer, "lab#%ld", m_labTimeRecords.size()+1);
    lab(buffer);
}

void KoodevStopwatch::lab(const char *tag)
{
    if (!m_started)
        return;

    LabTimeDescriptor ltd;
    gettimeofday(&ltd.labTimeval, NULL);
    ltd.tag = tag;
    m_labTimeRecords.push_back(ltd);
}

void KoodevStopwatch::setMessage(const char *msg)
{
    if (msg == NULL)
        m_message = m_defaultMessage;
    else
        m_message = msg;
}

void KoodevStopwatch::dump()
{
    long prevTime = 0;
    for (int i = 0; i < m_labTimeRecords.size(); i++) {
        long currentTime = getTime(m_labTimeRecords[i].labTimeval);
        dumpMessage(currentTime - prevTime, m_labTimeRecords[i].tag.data());
        prevTime = currentTime;
    }
    if (!m_started)
        dumpMessage(getTime());
}

long KoodevStopwatch::getTime()
{
    return getTime(m_endTimeval);
}

long KoodevStopwatch::getTime(timeval &labTimeval)
{
    long sec = labTimeval.tv_sec - m_startTimeval.tv_sec;
    long usec = labTimeval.tv_usec - m_startTimeval.tv_usec;
    if (m_measureNanos) {
        // FIXME - exception for overflow
        return sec * 1000000 + usec;
    }
    return sec * 1000 + usec / 1000;
}

long KoodevStopwatch::getCurrentTimeMillis()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void KoodevStopwatch::initDefaultMessage()
{
    sprintf(m_defaultMessage, "default message [%p]", this);
}

long KoodevStopwatch::getLabTime(timeval &labTimeval)
{
    return getTime(labTimeval);
}

void KoodevStopwatch::dumpMessage(long labTime)
{
    KOODEV_PRINT("[%s] %ld %s\n", m_message.data(), labTime, getTimeUnit());
}

void KoodevStopwatch::dumpMessage(long labTime, int index)
{
    KOODEV_PRINT("[%s][lab#%d] %ld %s\n", m_message.data(), index, labTime, getTimeUnit());
}

void KoodevStopwatch::dumpMessage(long labTime, const char *tag)
{
    KOODEV_PRINT("[%s][%s] %ld %s\n", m_message.data(), tag, labTime, getTimeUnit());
}

const char* KoodevStopwatch::getTimeUnit()
{
    if (m_measureNanos) return "ns";
    return "ms";
}

#ifdef KOODEV_NAMESPACE
} // namespace
#endif // KOODEV_NAMESPACE
