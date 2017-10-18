//
//  PlayCommandFactory.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 22.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef PlayCommandFactory_hpp
#define PlayCommandFactory_hpp

#include <stdio.h>
#include <memory>
#include "AbstractFactory.hpp"
#include "AbstractCommand.hpp"
#include "PlayCommand.hpp"
class PlayCommandFactory : public AbstractFactory
{
public:
    std::shared_ptr<AbstractCommand> create();
};

#endif /* PlayCommandFactory_hpp */
