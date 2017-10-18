//
//  AbstractFactory.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef AbstractFactory_hpp
#define AbstractFactory_hpp

#include <stdio.h>
#include <memory>
#include "AbstractCommand.hpp"

class AbstractFactory
{
    virtual std::shared_ptr<AbstractCommand> create() = 0;
};

#endif /* AbstractFactory_hpp */
