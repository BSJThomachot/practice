#ifndef __BUFFOVERFLOW_H_
#define __BUFFOVERFLOW_H_
#include <iostream>
class BufferOverflowException: public std::runtime_error
{
public:
        BufferOverflowException(std::string const& msg):
            std::runtime_error(msg)
        {

		}
};

#endif