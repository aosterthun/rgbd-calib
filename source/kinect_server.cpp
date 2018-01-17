//
//  main.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include <KinectServer.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
    KinectServer _server("141.54.147.106");
    _server.start();
}
