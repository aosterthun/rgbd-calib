//
//  KinectDaemonHandshake.cpp
//  kinectdaemon
//
//  Created by Arne Osterthun on 19.09.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "KinectDaemonHandshake.hpp"
void KinectDaemonHandshake::client_ip(std::string _client_ip)
{
	this->client_ip_mem = _client_ip;
}
std::string KinectDaemonHandshake::client_ip()
{
	return this->client_ip_mem;
}