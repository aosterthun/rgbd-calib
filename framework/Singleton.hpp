//
//  Singelton.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 30.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>
#include <memory>

template <typename C>
class Singleton
{
public:
	static std::shared_ptr<C> instance ()
	{
		if (!_instance)
			_instance.reset(new C);
		return _instance;
	}
	virtual
	~Singleton ()
	{
		_instance = 0;
	}
private:
	static std::shared_ptr<C> _instance;
protected:
	Singleton () { }
};
template <typename C> std::shared_ptr<C> Singleton <C>::_instance;

#endif /* Singelton_hpp */
