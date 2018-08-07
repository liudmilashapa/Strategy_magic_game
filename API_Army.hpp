#ifndef _API_ARMY_HPP_
#define _API_ARMY_HPP_

#include <optional>
#include "API_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Army
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		Army() 
		{}


		virtual bool compair(std::unique_ptr <GameModel::Unit> _unit1, std::unique_ptr <GameModel::Unit> _unit2) const = 0;

		virtual GameModel::Unit * getdUnit( int _number ) const = 0;
		virtual int getArmySize() const = 0;
		virtual int getMaxUnitsCount() const = 0;
		virtual int getID() const = 0;
		virtual Unit * getUnitForID( int _ID) const = 0;


		virtual bool hasUnitInArmy(const GameModel::Unit & _unit) const = 0;
		virtual bool hasArmyDistroed() const = 0;
		virtual void addUnit( GameModel::Unit * _unit ) = 0;
		virtual void Army::addUnit(std::unique_ptr< GameModel::Unit > _unit) = 0;

		virtual void removedUnit( GameModel::Unit & _unit ) = 0;
		virtual GameModel::Unit *
			findUnit(GameModel::Unit & _unit) = 0;

		//virtual std::unique_ptr< GameModel::Unit > getdUnit( GameModel::Unit & _unit ) = 0;
	
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:

		void isAmyFullness() const;

	};


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

}// namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

#endif // !_API_ARMY_HPP_