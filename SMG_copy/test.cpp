#include "API_Ability_Unit.hpp"
#include "API_Fight.hpp"
#include "API_Magic_Unit.hpp"
#include "API_Unit.hpp"

#include "IMP_Factory.hpp"
#include "IMP_Fight.hpp"
#include "Spell.hpp"

#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>


	using namespace GameModel;

 std::unique_ptr< GameModel::Army >  prepareArmy(
		Implementation::GameFactory & factory
	,	const int _ID
	,	const int _maxSize
	,	const int _unitsCount
	,	const double  _maxHP
	,	const double  _attackRate
	,	const double  _defenseRate)
{
	 
	std::unique_ptr< GameModel::Army > redArmy = factory.createArmy(_ID, _maxSize);
	
	for (int i = 0; i < _unitsCount; ++i)
	{
		redArmy->addUnit(factory.createUnit(i, _maxHP, _attackRate, _defenseRate));
	}
	return redArmy;
}

 int unitSelectionFromArmy(GameModel::Army & _ArmyForFight)
 
 {
	 int SoldierNo = rand() % (_ArmyForFight.getArmySize() - 1);

	 while (_ArmyForFight.getHPForID(SoldierNo) == 0)
	 {
		 SoldierNo = (SoldierNo == (_ArmyForFight.getArmySize() - 1)) ? 0 : SoldierNo + 1;
	 }
	 return SoldierNo;
 }


 void simulateFight(GameModel::Fight & _fight, GameModel::Army & _blueArmyForFight, GameModel::Army & _redArmyForFight)
 {
	 std::cout << "--------------------------------------------------------------" << std::endl;
	 std::cout << "                The battle has begun!" << std::endl;
	 std::cout << "--------------------------------------------------------------" << std::endl;

	 srand(time(NULL));

	 int roundNo = 1;

	 while (_fight.getCurrentButtleState() == GameModel::BattleState::InProcess)
	 {
		 int redSoldierNo = unitSelectionFromArmy(_redArmyForFight);
		 int blueSoldierNo = unitSelectionFromArmy(_blueArmyForFight);

		 GameModel::Unit & redArmySoldier = _redArmyForFight.getUnitForID(redSoldierNo);
		 GameModel::Unit & blueArmySoldier = _blueArmyForFight.getUnitForID(blueSoldierNo);

		 std::cout << "--------------------------------------------------------------" << std::endl;
		 std::cout << "Round #" << roundNo << std::endl;
		 std::cout << "--------------------------------------------------------------" << std::endl;

		 std::cout
			 << "Trying to fight with Red#"
			 << redSoldierNo 
			 << " and blue #"
			 << blueSoldierNo
			 << std::endl
			 ;

		 std::cout
			 << "Red unit HP before action:"
			 << redArmySoldier.getCurentHP()
			 << "; Blue unit HP before action:"
			 << blueArmySoldier.getCurentHP()
			 << std::endl
			 ;

		 if ((redArmySoldier.getCurentHP() == 0) || (blueArmySoldier.getCurentHP() == 0))
		 {
			 throw std::logic_error("Round cannot proceed: some of units are deceased.");
			 continue;
		 }
		 _fight.doRound(  _blueArmyForFight
						, blueArmySoldier
						, _redArmyForFight
						, redArmySoldier);

		 std::cout
			 << "Red unit HP after action:"
			 << redArmySoldier.getCurentHP()
			 << "; Blue unit HP after action:"
			 << blueArmySoldier.getCurentHP()
			 << std::endl
			 ;

		 std::cout << "--------------------------------------------------------------" << std::endl;

		 if (!_fight.hasButtleEnd())
			 ++roundNo;



		 std::cout << "--------------------------------------------------------------" << std::endl;
		 if (_fight.getCurrentButtleState() == GameModel::BattleState::FinishBattle)
		 {
			 if (_fight.getWinner() != nullptr)
			 {
				 std::cout << _fight.getWinner()->getID();
			 }
			 else
			 {
				 std::cout << "Nobody";
			 }
			 std::cout << " won the battle." << std::endl;
		 }
	 }
 }
int main()
{
	using namespace GameModel;

	Implementation::GameFactory factory;
	std::unique_ptr< GameModel::Army >  redArmyForFight = prepareArmy(factory, 1,20, 20, 30, 10, 0);
	std::unique_ptr< GameModel::Army >  blueArmyForFight = prepareArmy(factory, 2, 20, 8, 50, 15, 0);


	std::unique_ptr< Fight > battle = factory.createFight();
	battle->addArmy( *redArmyForFight );
	battle->addArmy( *blueArmyForFight );

	simulateFight( *battle , *blueArmyForFight, *redArmyForFight);

	return 0;
}