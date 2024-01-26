#pragma once

namespace ly
{
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		void beginPlayInternal();
		void TickInternal(float deltaTime);

		virtual ~World();

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;
	};
}

