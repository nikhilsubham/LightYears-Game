#include "framwork/Object.h"
#include "framwork/Core.h"

namespace ly
{
	Object::Object()
		:mIsPendigDestroy(false)
	{

	}

	void Object::Destroy()
	{
		mIsPendigDestroy = true;
	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}
}