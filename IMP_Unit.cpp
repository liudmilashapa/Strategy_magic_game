#include "API_Unit.hpp"
#include "IMP_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace Game_Model {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


	double Unit::getCurentHP() const
	{
		return m_curentHP;
	}

	double Unit::getMaxHP() const
	{
		return m_maxHP;
	}

	double Unit::getAttackRate() const
	{
		return m_attackRate;
	}

	double Unit::getDefenseRate() const
	{
		return m_defenseRate;
	}
	

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
}
}

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//