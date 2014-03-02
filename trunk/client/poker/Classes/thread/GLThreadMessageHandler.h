#ifndef __GL_THREAD_MESSAGE_HANDLER_H__
#define __GL_THREAD_MESSAGE_HANDLER_H__

#include "AbstractGLThreadMessageHandler.h"
//#include "HttpClientCommand.h"

class GLThreadMessageHandler : public AbstractGLThreadMessageHandler {
public:
	void processMessage(Cloneable* message);
};

#endif  // __GL_THREAD_MESSAGE_HANDLER_H__
