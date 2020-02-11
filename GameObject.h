#include <SDL_events.h>

#include "Body.h"
union SDL_Event;

class GameObject {
	public:

	virtual bool OnCreate()=0;

	virtual void OnDestroy() = 0;

	virtual void Update(const float deltaTime) = 0;
			
	virtual void Render()  = 0; //const before=

	virtual void HandleEvents( const SDL_Event event) = 0;
};