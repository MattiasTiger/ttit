/*
 * tcpClient.hpp
 *
 *  Created on: Jan 27, 2012
 *      Author: Tofs
 */

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include <iostream>
#include <string>
#include <fstream>

#include "network.hpp"


namespace ttit
{

class tcpClient
{
private:
	int status;
	int sockfd;
	struct addrinfo hints;
	struct addrinfo *servinfo;  // will point to the results
public:
	tcpClient();
	virtual ~tcpClient();
	int init(std::string adr, std::string port);
	void sendStr(const std::string &s);
	void reciveStr(std::string& s);
	std::string* reciveStr();
	const tcpClient& operator << ( const std::string& );
	const tcpClient& operator >> ( std::string& );

};

} /* namespace ttit */
#endif /* TCPCLIENT_HPP_ */
