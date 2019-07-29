#include <algorithm>
#include <stdio.h> 

#include "IMP_Fight.hpp"
#include "IMP_Army.hpp"
#include "IMP_Unit.hpp"


//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

namespace GameModel {
namespace Implementation {

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	void Fight::addArmy( GameModel::Army & _army)
	{
		if (hasArmyinFight(&_army))
			throw std::logic_error( "Army has been already add to fight" );
		m_armiesInFight.insert( &_army);
	}

	bool Fight::hasArmyinFight(GameModel::Army * _army) const
	{
		auto it = std::find(m_armiesInFight.begin(), m_armiesInFight.end(), _army);
		return   it != m_armiesInFight.end();
	}

	bool Fight::hasArmyDistroed(GameModel::Army & _army) const
	{
		if (!hasArmyinFight(&_army))
			throw std::logic_error("Army hasn't been in buttle");//?
		return (_army.hasArmyDistroed());
	}

	bool Fight::hasButtleEnd() const 
	{
		return(m_currentButtleState == BattleState::FinishBattle);
	}
	
	void  Fight::doRound (GameModel::Army & _redArmy
						, GameModel::Unit & _redArmySoldier
						, GameModel::Army & _blueArmy
						, GameModel::Unit &_blueArmySoldier
						)
	{
		doubleHit(_redArmy, _redArmySoldier, _blueArmy, _blueArmySoldier);
		endRound();
	}

	void Fight::endRound()
	{
		int _armyDestroyed = 0;

		for (auto & army : m_armiesInFight)
		{
			if (army->hasArmyDistroed())
			{
				_armyDestroyed++;
			}
		}

		 (m_armiesInFight.size() - _armyDestroyed > 1) ?
				(m_currentButtleState = BattleState::InProcess)
			:	(m_currentButtleState = BattleState::FinishBattle);
	}
	

	BattleState Fight::getCurrentButtleState() const
	{
		return m_currentButtleState;
	}

	GameModel::Army * Fight::getWinner() const
	{
		if (getCurrentButtleState() == BattleState::FinishBattle)
		{
			for (auto & army : m_armiesInFight)
			{
				if (!army->hasArmyDistroed())
				{
					return army;
				}
			}
			return nullptr;
		}
		throw std::logic_error( "Buttle in process" );
	}

	void Fight::getCurrentButtleState(BattleState _curentButtleState)
	{
		m_currentButtleState = _curentButtleState;
	}

	
	void Fight::singleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit )
		// 1st do hit
	{
		isUnitInArmy( _army1, _doHitUnits );
		isUnitInArmy( _army2, _damageUnit );
		isArmydifference( _army1, _army2 );
		isUnitLive( _doHitUnits );
		isUnitLive( _damageUnit );
		_damageUnit.changeCurentHP( calculatecurentHP(_doHitUnits, _damageUnit) );
	}	

	void Fight::doubleHit( GameModel::Army & _army1, GameModel::Unit & _doHitUnits, GameModel::Army & _army2, GameModel::Unit & _damageUnit )
	{
		isUnitInArmy(_army1, _doHitUnits);
		isUnitInArmy(_army2, _damageUnit);
		isArmydifference(_army1, _army2);
		isUnitLive(_doHitUnits);
		isUnitLive(_damageUnit);
		_damageUnit.changeCurentHP( calculatecurentHP(_doHitUnits, _damageUnit) );
		_doHitUnits.changeCurentHP( calculatecurentHP(_damageUnit, _doHitUnits) );
	}

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

	

	double Fight::calculatecurentHP(GameModel::Unit & _doHitUnits, GameModel::Unit & _damageUnit) const
	{
		if (_damageUnit.getDefenseRate() > _doHitUnits.getAttackRate())
			return _damageUnit.getCurentHP();

		double _other = (_damageUnit.getCurentHP() + (_damageUnit.getDefenseRate() - _doHitUnits.getAttackRate()));
		return (_other > 0) ?  _other :  0 ;
	}

	void Fight::isUnitLive( const GameModel::Unit & _unit ) const
	{
		if ( _unit.getCurentHP() ==0 )
			throw std::logic_error("This unit has been kill");
	}

	void Fight::isUnitInArmy( const GameModel::Army & _army, const GameModel::Unit & _unit) const
	{
		if (!_army.hasUnitInArmy(_unit.getUnitID()))
			throw std::logic_error("Unit hasn't been in this army");
	}

	void Fight::isArmydifference(const GameModel::Army & _army1, const GameModel::Army & _army2) const
	{
		if (&_army1 == &_army2)
			throw std::logic_error ("There are units from the same armies ");
	}

	
//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//

} // namespace Implementation
} // namespace GameModel

//*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*//
