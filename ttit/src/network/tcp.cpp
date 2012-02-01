/*
 * tcpClient.cpp
 *
 *  Created on: Jan 27, 2012
 *      Author: Tofs
 */

#include "tcp.hpp"



namespace ttit
{

tcpClient::tcpClient()
{

}

tcpClient::~tcpClient()
{
	close(sockfd);
}

int tcpClient::init(std::string adr, std::string port)
{

	memset(&hints, 0, sizeof hints); // make sure the struct is empty
	hints.ai_family = AF_INET;     // IPv4
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

	// get ready to connect
	status = getaddrinfo(adr.c_str(), port.c_str(), &hints, &servinfo);

	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);


	return 0;
}

void tcpClient::sendStr(const std::string& s)
{

	send(sockfd, s.c_str() , s.size() , 0);

}

void tcpClient::reciveStr(std::string& s)
{
	char buffer[1024];
	recv(sockfd, buffer, 1024, 0);

	s = buffer;

}


const tcpClient& tcpClient::operator << ( const std::string& s )
{

	sendStr(s);
	return *this;

}


const tcpClient& tcpClient::operator >> ( std::string& s )
{
	reciveStr(s);
	return *this;
}

} /* namespace ttit */
