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

	double Army::getHPForID( int _ID ) const
	{
		auto it = std::find_if(
				m_army.begin()
			,	m_army.end()
			, [_ID] (armyPair & _pair)-> bool
		{
			return (_pair.second->getUnitID() == _ID);
		}
		);
		if (it != m_army.end())
		{
			return it->second->getCurentHP();
		}
		throw std::logic_error("Unit isn't below this army");
	}

	GameModel::Unit & Army::getUnitForID(int _ID) const
	{
		std::optional < GameModel::Unit & > _it = findUnit(_ID);
		if (_it)
		{
			return _it->second.get();
		}
		
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
			, [](armyPair & _pair) -> bool
		{
			return( _pair.second->getCurentHP() != 0);
		}
		);
		return (it == m_army.end());
	}


	void Army::addUnit(std::unique_ptr< GameModel::Unit > _unit)
	{
		isAmyFullness();
		m_army.insert(std::make_pair(_unit->getUnitID(), _unit));
	}

	void Army::removedUnit(int _ID)
	{
		auto it = std::remove_if
		(
				m_army.begin()
			,	m_army.end()
			,	[&_ID](armyPair & _pair) -> bool
			{
				return(_ID == _pair.first);
			}
		);
			if (it == m_army.end())
			{
				throw std::logic_error("Unit wasnt finded there");
			}
			m_army.erase(it);

		//std::unique_ptr < GameModel::Unit >
	}

	 std::optional < GameModel::Unit & > Army::findUnit(int _id) const
	{
		 std::optional <armyIt> _res;
		 auto it = std::find_if(
			 m_army.begin()
			 , m_army.end()
			 , [_id](armyPair & _pair)-> bool
		 {
			 return (_pair.second->getUnitID() == _id);
		 }
		 ); 
		if (it != m_army.end())
			 {
			_res = it;
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
