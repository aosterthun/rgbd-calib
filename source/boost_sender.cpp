#include <CMDParser.hpp>
#include <DataTypes.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <zmq.hpp>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <ctime>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <PlayCommand.hpp>


struct GenericMessage
{
  unsigned type;
  unsigned size_payload_byte;
  std::vector<unsigned> vector_payload;
  std::string string_payload;
};


int main(int argc, char* argv[]){
  CMDParser p("socket");
  p.init(argc,argv);

  std::string socket_name(p.getArgs()[0]);

  zmq::context_t ctx(1); // means single threaded
  zmq::socket_t  socket(ctx, ZMQ_PUB); // means a publisher
  uint32_t hwm = 10000;
  socket.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));

  std::string endpoint("tcp://" + socket_name);
  socket.bind(endpoint.c_str());
  sleep(1);
  std::srand(std::time(0));


  while(true){
    int rand_num = std::rand() % 100;
    GenericMessage msg;
    msg.type = 1;
    
    for (int i = 0; i < rand_num; ++i)
    {
      msg.vector_payload.push_back(i);
      //msg.string_payload += std::to_string(i);
    }

    PlayCommand play;
    play.filename("test.txt");
    std::stringstream sstream{};
    boost::archive::text_oarchive oarchive{sstream};
    oarchive << play;
    msg.string_payload = sstream.str();
    std::cout << msg.string_payload << std::endl;
    if(msg.type == 0){
      msg.size_payload_byte = rand_num * sizeof(unsigned);      
      zmq::message_t zmqm(2*sizeof(unsigned) + msg.size_payload_byte);
      memcpy( ((unsigned char* ) zmqm.data()), (const unsigned char*) &msg.type, sizeof(unsigned));
      memcpy( ((unsigned char* ) zmqm.data()) + sizeof(unsigned), (const unsigned char*) &msg.size_payload_byte, sizeof(unsigned));
      memcpy( ((unsigned char* ) zmqm.data()) + 2*sizeof(unsigned), (const unsigned char*) &msg.vector_payload[0], msg.size_payload_byte);  
      socket.send(zmqm);
    }else if(msg.type == 1){
      msg.size_payload_byte = msg.string_payload.size()+1;
      zmq::message_t zmqm(2*sizeof(unsigned) + msg.size_payload_byte);
      memcpy( ((unsigned char* ) zmqm.data()), (const unsigned char*) &msg.type, sizeof(unsigned));
      memcpy( ((unsigned char* ) zmqm.data()) + sizeof(unsigned), (const unsigned char*) &msg.size_payload_byte, sizeof(unsigned));
      memcpy( ((unsigned char* ) zmqm.data()) + 2*sizeof(unsigned), (const unsigned char*) msg.string_payload.c_str(), msg.size_payload_byte);
/*      std::string check;
      memcpy( (unsigned char* ) check.c_str(), ((const unsigned char*) zmqm.data()) + 2*sizeof(unsigned), msg.size_payload_byte);
      std::cout << "test:: " << check.c_str() << std::endl;*/
      socket.send(zmqm);
      std::cout << "sending: " << msg.size_payload_byte << std::endl;
    }
  }



  return 0;
}