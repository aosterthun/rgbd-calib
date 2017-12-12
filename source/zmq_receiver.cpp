#include <CMDParser.hpp>
#include <DataTypes.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <zmq.hpp>

#include <iostream>

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
  zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
  socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
  uint32_t hwm = 10000;
  socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
  std::string endpoint("tcp://" + socket_name);
  socket.connect(endpoint.c_str());


  while(true){
    zmq::message_t zmqm;
    socket.recv(&zmqm, 0);
    GenericMessage msg;
    
    memcpy( (unsigned char*) &msg.type, ((const unsigned char* ) zmqm.data()), sizeof(unsigned));
    memcpy( (unsigned char*) &msg.size_payload_byte, ((const unsigned char* ) zmqm.data()) + sizeof(unsigned), sizeof(unsigned));

    if(msg.type == 0){
      msg.vector_payload = std::vector<unsigned>(msg.size_payload_byte/sizeof(unsigned));

      memcpy( (unsigned char*) &msg.vector_payload[0], ((const unsigned char* ) zmqm.data()) + 2*sizeof(unsigned), msg.size_payload_byte);    

      for(auto i : msg.vector_payload)
      {
        std::cout << i << std::endl;
      }
    }else if(msg.type == 1){
      memcpy( (unsigned char*) msg.string_payload.c_str(), ((const unsigned char* ) zmqm.data()) + 2*sizeof(unsigned), msg.size_payload_byte);    
      msg.string_payload.reserve(msg.size_payload_byte);
      msg.string_payload = std::string(msg.string_payload.c_str());
      std::cout << msg.string_payload << std::endl;
    }
    

    //std::cout << msg.size_payload_byte << std::endl;

  }

  return 0;
}
