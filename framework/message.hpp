//
//  message.cpp
//  kinectServiceProtocolMessage
//
//  Created by Arne Osterthun on 21.01.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include <stdio.h>


enum message_type {SEND = 0, RECORD = 1};

struct KinectServiceMessage {
    int message_id;
    message_type type;
    char payload[258];
};

struct KinectServiceMessagePayload {
    char* ksmp_message_id;
    char* ksmp_filepath_length_src;
    char* ksmp_filepath_src;
    char* ksmp_startframe;
    char* ksmp_endframe;
    char* ksmp_loop;
    char* ksmp_serverport;
    char* ksmp_num_cameras;
    char* ksmp_duration;
    char* ksmp_is_compressed;
    char* ksmp_filepath_length_dest;
    char* ksmp_filepath_dest;
};

