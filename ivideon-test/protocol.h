#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "channel.h"
#include <list>
#include <string>

class Protocol
{
public:
    Protocol();
    ~Protocol();

private:
    Channel ch;
    std::list<std::string> prot_commands;  // известные команды протокола
};

#endif // PROTOCOL_H
