#pragma once

namespace ly 
{
	class Object
	{
	public:
		Object();
		void Destroy();
		virtual ~Object();

		bool isPendigDestroy() const { return mIsPendigDestroy; }

	private:
		bool mIsPendigDestroy;
	};
}
