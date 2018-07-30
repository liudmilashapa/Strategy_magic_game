#include <algorithm>
#include <stdio.h> 

#include "IMP_Fight.hpp"
#include "IMP_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	void Fight::singleHit( Unit & _unit1, Unit & _unit2 )
		// 1st do hit
	{
		isUnitInArmy(m_army1, _unit1);
		isUnitInArmy(m_army2, _unit2);
		isUnitLive(_unit1);
		isUnitLive(_unit2);
		_unit2.setCurentHP(calculateDamage( _unit1,  _unit2));
	}
	
	void Fight::doubleHit(Unit & _unit1, Unit & _unit2)
	{
		isUnitInArmy(m_army1, _unit1);
		isUnitInArmy(m_army2, _unit2);
		isUnitLive(_unit1);
		isUnitLive(_unit2);
		_unit2.setCurentHP(calculateDamage(_unit1, _unit2));
		_unit1.setCurentHP(calculateDamage(_unit2, _unit1));
	}

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	void Fight::isUnitInArmy(const fightContainer & _army, const Unit & _unit) const
	{	
		if (std::find(_army.begin(), _army.end(), &_unit) != m_army1.end())
			throw std::logic_error("This unit isn't situating on the board now");
	}

	void Fight::isUnitLive(const Unit & _unit) const
	{
		if (_unit.getCurentHP()==0)
			throw std::logic_error("This unit has been kill");
	}

	double Fight::calculateDamage(Unit & _unit1, Unit & _unit2) const
	{
		double _other =_unit2.getCurentHP() - (_unit2.getDefenseRate() - _unit1.getAttackRate());
		if ((_other) >= 0)
		{
			return _other;
		}
		else 
			return 0;
	}


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
