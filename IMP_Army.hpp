#ifndef _IMP_ARMY_HPP_
#define _IMP_ARMY_HPP_

#include <set>
#include <memory>

#include "API_Army.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	typedef
		std::set< std::unique_ptr< GameModel::Unit > >
		armyContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	typedef
		armyContainer::iterator itArmyContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Army : public GameModel::Army
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		Army(int _ID, int _maxArmyCount)
		:	m_ID( _ID ),
			m_maxUnitsCount( _maxArmyCount )
		{}

		Army(const Army & _other) = delete;
		Army & operator = (const Army & _other) = delete;

		virtual bool compair(std::unique_ptr <GameModel::Unit> _unit1, std::unique_ptr <GameModel::Unit> _unit2) const override;

		virtual GameModel::Unit * getdUnit(int _number) const override;
		virtual int getArmySize() const override;
		virtual int getMaxUnitsCount() const override;
		virtual int getID() const override;
		virtual GameModel::Unit * getUnitForID( int _ID) const override;

		virtual bool hasUnitInArmy(const GameModel::Unit & _unit) const override;
		virtual bool hasArmyDistroed() const override;

		virtual void addUnit( GameModel::Unit * _unit ) override;
		virtual void Army::addUnit(std::unique_ptr< GameModel::Unit > _unit) override;
		virtual void removedUnit( GameModel::Unit & _unit ) override;
		virtual GameModel::Unit * 
			findUnit( GameModel::Unit & _unit ) override;

		//virtual std::unique_ptr< GameModel::Unit > getdUnit( GameModel::Unit & _unit ) override;
	
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:

		armyContainer m_army;
		int m_maxUnitsCount;
		int m_ID;
		void isAmyFullness() const;

	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

}//Implementation
}// namespace GameModel

  //*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif // !_IMP_ARMY_HPP_
