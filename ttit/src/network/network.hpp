/*
 * network.hpp
 *
 *  Created on: Jan 27, 2012
 *      Author: Tofs
 */

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>

#include "tcp.hpp"




namespace ttit
{

	typedef std::vector<char> byteBuffer;

}


#endif /* NETWORK_HPP_ */
