#ifndef _IMP_FIGHT_HPP
#define _IMP_FIGHT_HPP

#include < set >
#include < memory > 

#include "API_Fight.hpp"
#include "IMP_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	typedef
		std::set < GameModel::Army * >
		fightContainer;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
	
	class Fight : public GameModel::Fight
	{

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	public:

		Fight()
		{}

		Fight( const Fight & _other ) = delete;
		Fight & operator = ( const Fight & _other ) = delete;

		virtual void addArmy( GameModel::Army & _army1) override;
	
		virtual bool hasArmyinFight(GameModel::Army * _army) const override;
		virtual bool hasArmyDistroed(GameModel::Army & _army) const override;
		virtual bool hasButtleEnd() const override;
		virtual void doRound( GameModel::Army & _redArmy
							, GameModel::Unit & _redArmySoldier
							, GameModel::Army & _blueArmy
							, GameModel::Unit &_blueArmySoldier
							) override;
		virtual void endRound() override;

		virtual BattleState getCurrentButtleState() const override;
		virtual GameModel::Army * getWinner() const override;

		virtual  void getCurrentButtleState(BattleState _curentButtleState) override;

		virtual void singleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit ) override;
		virtual void doubleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit ) override;

		virtual double calculatecurentHP( GameModel::Unit & _unit1, GameModel::Unit & _unit2) const override;

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	private:

		fightContainer m_armiesInFight;
		BattleState m_currentButtleState;

		virtual void isUnitLive( const GameModel::Unit & _unit ) const override;
		virtual void isUnitInArmy( const GameModel::Army & _army, const GameModel::Unit & _unit ) const override;

		virtual void isArmydifference(const GameModel::Army & _army1, const GameModel::Army & _army2) const override;
	};

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//


#endif //!_IMP_FIGHT_HPP