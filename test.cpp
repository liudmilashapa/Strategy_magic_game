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



 GameModel::Army &  prepareArmy(
		const int _ID
	,	const int _maxSize
	,	const int _unitsCount
	,	const double  _maxHP
	,	const double  _attackRate
	,	const double  _defenseRate)
{
	using namespace GameModel;
	
	Implementation::GameFactory factory;

	std::unique_ptr< GameModel::Army > redArmy = factory.createArmy(_ID, _maxSize);
	
	for (int i = 0; i < _unitsCount+1; ++i)
	{
		redArmy->addUnit(factory.createUnit(i, _maxHP, _attackRate, _defenseRate));
	}
	return  *redArmy;
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
		 int redSoldierNo = rand() % _redArmyForFight.getArmySize() - 1;

		 while (_redArmyForFight.getUnitForID(redSoldierNo)->getCurentHP() == 0)
		 {
			 redSoldierNo = (redSoldierNo == (_redArmyForFight.getArmySize() - 1)) ? 0 : redSoldierNo + 1;
		 }

		 int blueSoldierNo = rand() % _blueArmyForFight.getArmySize();

		 while ((_blueArmyForFight.getUnitForID(blueSoldierNo)->getCurentHP()) == 0)
		 {
			 blueSoldierNo = (blueSoldierNo == _blueArmyForFight.getArmySize() - 1) ? 0 : blueSoldierNo + 1;
		 }

		 GameModel::Unit & redArmySoldier = *_redArmyForFight.getUnitForID(rand() % _redArmyForFight.getArmySize());
		 GameModel::Unit & blueArmySoldier = *_blueArmyForFight.getUnitForID(rand() % _blueArmyForFight.getArmySize());

		 std::cout << "--------------------------------------------------------------" << std::endl;
		 std::cout << "Round #" << roundNo << std::endl;
		 std::cout << "--------------------------------------------------------------" << std::endl;

		 std::cout
			 << "Trying to fight with Red#"
			 << redSoldierNo + 1
			 << " and blue #"
			 << blueSoldierNo + 1
			 << std::endl
			 ;

		 if ((redArmySoldier.getCurentHP() == 0) || (blueArmySoldier.getCurentHP() == 0))
		 {
			 std::cout << "Round cannot proceed: some of units are deceased." << std::endl;
			 continue;
		 }

		 std::cout
			 << "Red unit HP before action:"
			 << redArmySoldier.getCurentHP()
			 << "; Blue unit HP before action:"
			 << blueArmySoldier.getCurentHP()
			 << std::endl
			 ;

		 _fight.doubleHit(
			 _blueArmyForFight
			 , blueArmySoldier
			 , _redArmyForFight
			 , redArmySoldier);
		 _fight.endRound();
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
				 std::cout << "Nobady";
			 }
			 std::cout << " won the battle." << std::endl;
		 }
	 }
 }
int main()
{
	using namespace GameModel;

	GameModel::Army & redArmyForFight = prepareArmy(1,20, 20, 30, 10, 0);
	GameModel::Army & blueArmyForFight = prepareArmy(2, 20, 10, 50, 12, 0);

	Implementation::GameFactory factory;

	std::unique_ptr< Fight > battle = factory.createFight();
	battle->addArmy(redArmyForFight);
	battle->addArmy(blueArmyForFight);

	simulateFight( *battle , blueArmyForFight, redArmyForFight);

	return 0;
}