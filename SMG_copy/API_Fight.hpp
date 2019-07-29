#ifndef _API_FIGHT_HPP
#define _API_FIGHT_HPP

#include < list >
#include < memory > 

#include "API_Unit.hpp"
#include "API_Army.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	enum class BattleState { InProcess, FinishBattle };

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	class Fight
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	public:

		Fight()
		{}

		virtual void addArmy( Army & _army ) = 0;

		virtual bool hasArmyinFight ( Army * _army ) const = 0;
		virtual bool hasArmyDistroed( Army & _army ) const = 0;
		virtual bool hasButtleEnd() const = 0;
		virtual void doRound( GameModel::Army & _redArmy
							, GameModel::Unit & _redArmySoldier
							, GameModel::Army & _blueArmy
							, GameModel::Unit &_blueArmySoldier
							) = 0;
		virtual void endRound() = 0;
		virtual BattleState getCurrentButtleState() const = 0;
		virtual Army * getWinner() const = 0;

		virtual void getCurrentButtleState(BattleState _curentButtleState) = 0;

		//virtual void addArmy(std::unique_ptr< GameModel::Army > _army1) = 0;

		virtual void singleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit ) = 0;
		virtual void doubleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit ) = 0;

		virtual double calculatecurentHP(GameModel::Unit & _unit1, GameModel::Unit & _unit2) const = 0;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	private:

		virtual void isUnitLive( const GameModel::Unit & _unit ) const = 0;
		virtual void isUnitInArmy( const GameModel::Army & _army1, const GameModel::Unit  & _unit ) const = 0;
		virtual void isArmydifference(const GameModel::Army & _army1, const GameModel::Army & _army2 ) const = 0;
	
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif //!_API_FIGHT_HPP