#include <stdio.h> 
#include <memory>
#include <algorithm>

#include "IMP_Army.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

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

	int Army::getIDSelectionUnitFromArmy() const

	{
		int soldierNo = rand() % (getArmySize() - 1);

		while (getHPForID(soldierNo) == 0)
		{
			soldierNo = (soldierNo == (getArmySize() - 1)) ? 0 : soldierNo + 1;
		}

		return soldierNo;
	}

	double Army::getHPForID( int _id ) const
	{
		auto it = m_army.find(_id);
		if (it != m_army.end())
		{
			return it->second->getCurentHP();
		}
		throw std::logic_error("Unit isn't below this army");
	}

	GameModel::Unit & Army::getUnitForID(int _id) const
	{
		std::optional < GameModel::Unit * > _unit = findUnit(_id);
		if (_unit)
		{
			return **_unit;
		}
		throw std::logic_error("Unit isn't below this army");
	}

	bool Army::hasUnitInArmy(int _id) const
	{
		auto it = std::find_if
			(	m_army.begin()
			,	m_army.end()
			,	[_id](armyPair const & _pair) -> bool
		{
			return (_pair.first == _id);
		}
		);
		return   it != m_army.end();
	}

	bool Army::hasArmyDistroed() const
	{
		auto it = std::find_if(
				m_army.cbegin()
			,	m_army.cend()
			,	[](armyPair const & _pair) -> bool
		{
			return( _pair.second->getCurentHP() != 0);
		}
		);
		return (it == m_army.cend());
	}


	void Army::addUnit(std::unique_ptr< GameModel::Unit > _unit)
	{
		isAmyFullness();
		m_army.insert(std::make_pair(_unit->getUnitID(), std::move(_unit)));
	}

	void Army::removedUnit(int _id)
	{
		auto it = m_army.find(_id);
			if (it == m_army.end())
			{
				throw std::logic_error("Unit wasnt finded there");
			}
			m_army.erase(it);
	}

	 std::optional < GameModel::Unit * > Army::findUnit(int _id) const
	{
		 std::optional < GameModel::Unit * > _res;
		 auto it = m_army.find(_id);
		if (it != m_army.end())
			 {
			_res =  it->second.get();
			 }
		return _res;
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
