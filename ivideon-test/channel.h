#ifndef CHANNEL_H
#define CHANNEL_H

#include <sys/types.h>

class Channel
{
public:
    Channel();

    virtual ~Channel();

    bool openChannel();

    ssize_t readFromChannel();

    ssize_t writeToChannel();

    void closeChannel();

};

#endif // CHANNEL_H
