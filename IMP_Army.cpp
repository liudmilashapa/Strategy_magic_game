#include <stdio.h> 
#include <memory>
#include <algorithm>

#include "IMP_Army.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	bool Army::compair(std::unique_ptr <GameModel::Unit> _unit1, std::unique_ptr <GameModel::Unit> _unit2) const
	{
		return (_unit1.get() == _unit2.get());
	}
	
	GameModel::Unit *  Army::getdUnit(int _number) const
	{

	}

	int Army::getArmySize() const
	{
		return (int) m_army.size();
	}

	int Army::getMaxUnitsCount() const
	{
		return m_maxUnitsCount;
	}
	
	int Army::getID() const
	{
		return m_ID;
	}

	GameModel::Unit *  Army::getUnitForID( int _ID ) const
	{
		auto it = std::find_if(
				m_army.begin()
			,	m_army.end()
			, [_ID] (std::unique_ptr< Unit > const & _unit)-> bool
		{
			return (_unit->getUnitID() == _ID);
		}
		);
		if (it != m_army.end)
		{
			return it->get();
		}
		return nullptr;
	}

	bool Army::hasUnitInArmy(const GameModel::Unit & _unit) const
	{
		auto it = std::find(m_army.begin(), m_army.end(), _unit);
		return   it != m_army.end();
	}

	bool Army::hasArmyDistroed() const
	{
		auto it = std::find_if(
			m_army.begin()
			, m_army.end()
			, [](std::unique_ptr< Unit > const & _unit) -> bool
		{
			return( _unit->getCurentHP() != 0);
		}
		);
		return (it == m_army.end());
	}

	void Army::addUnit(GameModel::Unit * _unit)
	{
		isAmyFullness();
		std::unique_ptr < GameModel::Unit > unit(_unit);
		m_army.insert ( unit );
	}

	void Army::addUnit(std::unique_ptr< GameModel::Unit > _unit)
	{
		isAmyFullness();
		m_army.insert(_unit);
	}

	void Army::removedUnit(GameModel::Unit & _unit)
	{
		auto it = std::remove_if (
			m_army.begin()
			, m_army.end()
			, [&_unit] (std::unique_ptr< Unit > const & _unit2) -> bool
		{
			return(&_unit == _unit2.get());
		}
		);
	}


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	void Army::isAmyFullness() const
	{
		if ( getArmySize() == getMaxUnitsCount())
			throw std::logic_error ( "The Army is fullness" );
	}


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

}// namespace Implementation
}// namespace GameModel

 //*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
