//
//  AbstractGLThreadMessageHandler.h
//
//  Created by zhouyan on 2013-01-09.
//

#ifndef __ABSTRACT_GL_THREAD_MESSAGE_HANDLER_H__
#define __ABSTRACT_GL_THREAD_MESSAGE_HANDLER_H__

#include "Cloneable.h"

class AbstractGLThreadMessageHandler {
public:
	virtual ~AbstractGLThreadMessageHandler() {};
	virtual void processMessage(Cloneable* message) = 0;
};

#endif  // __ABSTRACT_GL_THREAD_MESSAGE_HANDLER_H__
