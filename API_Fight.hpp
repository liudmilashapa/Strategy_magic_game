#ifndef _API_FIGHT_HPP
#define _API_FIGHT_HPP

#include < list >
#include < memory > 

#include "API_Unit.hpp"

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel
{

	typedef 
	std::list < std::unique_ptr < API_Unit > >
	FightContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Fight
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	private:

		FightContainer army1;
		FightContainer army2;
	
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

}

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif //!_API_FIGHT_HPP